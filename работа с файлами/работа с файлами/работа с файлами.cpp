#include<string>
#include<fstream>//работа с файлами
#include<iostream>
#include<cstdlib>//для получения рандомных чисел
#include<ctime>
using namespace std;

void write_arr(const string& filename, const int* arr, const int n)
{
	fstream fs;

	fs.open(filename, fstream::out);
	if (fs.is_open ())//проверяем что фаил успешно открыт
	{
		fs << n << '\n';//записываем размер массива
		for (int i = 0; i < n; i++)
			fs << arr[i] << '    ';//записываем значения через пробел
		fs << '\n';
		fs.close();// закрываем фаил
	}
}

void read_arr(const string& filename, int*& arr, int& n)
{
	fstream fs;

	fs.open(filename, fstream::in);
	if (fs.is_open())// проверяем что фаил успешно открыт
	{
		fs >> n; //читаем размер массива
		arr = new int[n];
		for (int i = 0; i < n; i++)
			fs >> arr[i];// читаем из файла разделительные символы - пробелы и перенос строки

		fs.close();// закрываем фаил
	}
}



int main()
{
	string filename = "array_data.txt";
	const int size = 100;
	int* rand_arr = new int[size];

	srand(time(nullptr));// используем текущее время что бы сгенерировать рандомные значения
	int lef_border = 5;
	int range_len = 10;// правая граница range_len + lef_border
	for (int i = 0; i < size; i++)
		rand_arr[i] = lef_border + rand() % range_len; //генерируем число в 
	// указанном диапазоне и записываем массив в фаил
	write_arr(filename, rand_arr, size); //записываем массив в фаил

	int* array_from_file = nullptr;
	int n = 0;
	read_arr(filename, array_from_file, n);//читаем массив из файла

	delete[] rand_arr;
	delete[] array_from_file;

	/*
	string filename = "array_data.txt";
   const int size = 500000;
   int* rand_arr = new int[size];

   srand(time(nullptr)); // используем текущее время, чтобы сгенерировать рандомные значения
   int lef_border = 5;
   int range_len = 1000; // правая граница = range_len + left_border
   for (int i = 0; i < size; i++)
       rand_arr[i] = lef_border + rand() % range_len; // генерируем число в указанном диапазоне и записываем в массив

   write_arr(filename, rand_arr, size); // записываем массив в файл

   int* array_from_file = nullptr;
   int n = 0;
   read_arr(filename, array_from_file, n); // читаем массив из файла

   auto start = chrono::high_resolution_clock::now(); // сохраняем время начала работы алгоритма
   quickSort(array_from_file, 0, n); // запускаем сортировку
   auto finish = chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
   chrono::duration<double> elapsed = finish - start;
   cout << "Elapsed time: " << elapsed.count() << " sec" << endl; // вычисляем продолжительность работы в сек. и выводим на экран

   delete[] rand_arr;
   delete[] array_from_file;
   return 0;

	*/

	return 0;
}