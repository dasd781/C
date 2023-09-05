#include "queue"
#include "list"
#include <mutex>
#include <thread>
#include <random>
#include <memory>
#include <string>
#include <iostream>

using namespace std;


// структура детали
typedef struct Part {
	int part_id;
	float volume;
	typedef shared_ptr<struct Part> PartPtr; // умный указатель
} Part;


static bool done = false;
queue<Part::PartPtr> shared_queue;
mutex lock_queue;
mutex lock_cout;

/*
тип Part, обозначающий деталь,
тип PartPtr, который является умным указателем на объект типа Part,
мьютекс lock_queue для блокировки доступа к разделяемой между потоками очереди shared_queue,
мьютекс lock_cout для блокировки объекта вывода cout,
переменную done, которая будет сообщать о конце работы потока А.
*/

void threadAwork(Part::PartPtr& part) {
	// делаем вычитание из объема и имитируем задержку
	part->volume -= 2;
	std::this_thread::sleep_for(std::chrono::milliseconds(500 + rand() % 6000));

	locked_output("threadAwork finished with part " + to_string(part->part_id));
}

void threadBwork(Part::PartPtr& part) {
	// делаем вычитание из объема и имитируем задержку
	part->volume -= 1;
	std::this_thread::sleep_for(std::chrono::milliseconds(500 + rand() % 6000));

	locked_output("threadBwork finished with part " + to_string(part->part_id));
}
void locked_output(const std::string& str) {
	// захват мьютекса для защищенного вывода
	lock_guard<mutex> raii(lock_cout);
	cout << str << endl;
}

/*
Тут представлены две функции threadAwork() и threadBwork(), которые символизируют работу мастеров над деталью. 
Они просто вычитают константу из volume (объема) объекта Part, после чего делают случайные задержки для имитации временных затрат. 
Случайные задержки реализуются с помощью функции rand().
Также введена ещё одна функцию locked_output(), которая будет делать потокобезопасный вывод в std::cout.
*/

void threadA(list<Part::PartPtr>& input) {
	srand(7777777);
	size_t size = input.size();
	for (size_t i = 0; i < size; i++) {
		// обрабатываем деталь
		threadAwork(*input.begin());
		// кладём в очередь
		{
			lock_guard<mutex> raii_obj(lock_queue);
			shared_queue.push(Part::PartPtr(*input.begin()));
			input.remove(*input.begin());
			locked_output("Part was added to queue");
		}
	}
	done = true;
}
/*
Далее мы определяем функцию входа для потока А (первый мастер). 
Она принимает на вход ссылку на список деталей, которые нужно обработать.
*/

void threadB() {
	srand(100000);
	while (true) {
		Part::PartPtr part_for_work;
		{
			// блокируем мьютекс
			lock_queue.lock();
			if (shared_queue.empty()) {
				// если нет элементов, то освобождаем мьютекс
				// и делаем задержку в 1 секунду перед
				// следующий просыпанием
				lock_queue.unlock();
				if (done) break; // условие конца работы потока
				locked_output("threadB useless check, queue is empty. Going to bed");
				this_thread::sleep_for(chrono::milliseconds(1000));
				continue;
			}
			else {
				// забираем элемент из очереди
				part_for_work = shared_queue.front();
				shared_queue.pop();
				// не мешаем потоку А, освободим мьютекс
				lock_queue.unlock();
				locked_output("Part was removed from queue");
			}
		}
		// работаем над деталью
		threadBwork(part_for_work);
	}
}
/*
Функция threadB() является точкой входа для потока Б. В ней реализуется концепция поллинга:

Мы видим цикл while(true), который блокируя мьютекс, проверяет очередь на пустоту. Далее возможны два случая.
В первом очередь пуста, тогда поток разблокирует мьютекс и проверяет, не закончил ли поток А свою работу. 
Если это так, то в очередь уже ничего не поступит и его работа закончилась.
Если поток А ещё работает, то поток Б делает небольшой таймаут перед следующим опросом, во время которого он не занимает процессорное время, и повторяет процедуру.
Во втором кейсе (случае) очередь имеет элементы. 
Тогда поток забирает из очереди деталь, удаляя её оттуда, разблокирует мьютекс и начинает работу с деталью.
Заметьте, что блокировка мьютекса производится только во время доступа к разделяемой очереди. 
Сама полезная работа над деталями производится вне блокировок.
*/

int main(int argc, char* argv[])
{
	list<Part::PartPtr> spare_parts;
	for (int i = 0; i < 5; i++) {

		spare_parts.push_back(Part::PartPtr(new Part{ i + 1, 10.0 }));
	}
	// запуск потоков
	thread ta(threadA, std::ref(spare_parts));
	thread tb(threadB);
	// ждем завершения
	ta.join();
	tb.join();

	locked_output("done");
	return 0;
}