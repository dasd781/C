#include<iostream>
#pragma warning(disable: 4996) //щтключаем предупреждения Visual studio об использовании  функции открытия

using namespace std;

class file
{
public:
	file(const char* filename) : m_file_handle(fopen(filename, "w+"))
	{
		if (m_file_handle == NULL)
		{
			throw"file open error";
		}
	}
	~file()
	{
		fclose(m_file_handle);
	}
	// Запрещаем копирование и присваивание
	file(const file&) = delete;
	file& operator = (const file&) = delete;

	void write(const char* str)
	{
		if (fputs(str, m_file_handle) == EOF)
		{
			throw"Error writing to file";
	   }
	}
private:
	FILE* m_file_handle;
};
int main()
{
	file logfile("logfile.txt");
	logfile.write("hello logfile ! ");

	return 0;
}