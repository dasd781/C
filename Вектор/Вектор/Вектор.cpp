#include<iostream>
#include<vector>
using namespace std;

int main()
{
	std::vector<int> v{0,1,2,3,4};
	cout << v.size() << endl;//возвращает текущий размер вектора
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	cout << "current size: " << v.size() << endl;//возвращает текущий размер вектора
	cout << "max size: " << v.max_size() << endl;//возвращает максимальное количество элементов
	cout << "current capacity: " << v.capacity() << endl;//возвращает количество элементов,
	//которое можно вместить в текущее хранилище без выделения дополнительной памяти.
	cout << "is vector empty: " << v.empty() << endl;//возвращает true, если вектор пуст
	cout << "current capacity: " << v.capacity() << endl;

	v.reserve(100);//зарезервировать хранилище, то есть создать хранилище
	//размера не меньше, чем new_cap.
	cout << "current capacity after reserve: " << v.capacity() << endl;

	v.resize(200);//изменить размер текущего хранилища, чтобы он стал равен new_cap.
	cout << "current capacity after resize: " << v.capacity() << endl;

	v.clear();// очистить содержимое вектора.

	cout << "current capacity after clear: " << v.capacity() << endl;

	v.shrink_to_fit();//приравнивает capacity() к size, освобождает 
	//всю неиспользованную память (память под элементы между size и capasity, если таковые были).
	cout << "current capacity after shrink: " << v.capacity() << endl;
	cout << v[2];// operator[] возвращает ссылку на элемент массива

	//Помимо этого существует метод at(size_type pos), 
	// который проверяет границы массива перед доступом элемента — pos < size(). 
	//В случае, если происходит выход за границу, будет вызвано исключение std::out_of_range:
	cout << v.at(4) << endl;

	try
	{
		cout << v.at(7) << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what();
	}
	//Для получения первого и последнего элемента существуют методы front() и back():
	cout << v.front() << endl;
	cout << v.back() << endl;

	//Также мы можем получить само хранилище — указатель на массив, с помощью метода data()
	int* data = v.data();
	for (int i = 0; i < v.size(); ++i)
	{
		cout << data[i];
	}

	std::vector<int> v1{ 0,1,2,3,4 };
	std::vector<int> v2 = { 7,5,16,8 };

    return 0;
}