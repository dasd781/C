#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // Откроем файл для записи, если его не было, то он создастся
    ofstream file_writer("hello_file.txt");
    if (!file_writer.is_open()) {
        cout << "Could not open file!" << '\n';
        return 0;
    }

    // Запишем в файл строку hello, world
    file_writer << "hello, world";
    // Скорректируем строку, чтобы в файле получилось 
    // строка Hello, Linux!
    file_writer.seekp(7);
    file_writer << "Linux";
    file_writer.seekp(0, ios_base::beg);
    file_writer << 'H';
    file_writer.seekp(0, std::ios_base::end);
    file_writer << '!';
    file_writer.close();
}