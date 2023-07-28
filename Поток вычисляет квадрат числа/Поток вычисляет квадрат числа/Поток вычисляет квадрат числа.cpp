#include <iostream>
#include <windows.h>

struct Param
{
    int value;
    int result;
    Param(int _value) : value(_value), result(0) {}
    Param() : value(0), result(0) {}
};

//calculateSqr — функция, вычисляющая квадрат числа
DWORD WINAPI calculateSqr(LPVOID lpParam)
{
    Sleep(3000);        //добавляем задержку выполнения потока на 3 сек
    Param* param = (Param*)lpParam;
    param->result = param->value * param->value;
    return 0;
}

int main()
{
    DWORD threadId;
    Param  param(5);
    HANDLE hThread;

    //создаем поток
    //calculateSqr — функция потока
    //param — аргумент функции потока
    //threadId — возвращает идентификатор потока
    hThread = CreateThread(NULL, 0, calculateSqr, &param, 0, &threadId);

    //проверяем дескриптор созданного потока
    if (hThread == NULL)
    {
        //произошла ошибка при создании потока
        std::cout << "CreateThread failed" << std::endl;
        return 1;
    }
    else
    {
        //поток создан
        //ждем, пока поток завершится
        WaitForSingleObject(hThread, INFINITE);
        //после завершения потока выводим результат
        std::cout << "SQR(" << param.value << ") = " <<
            param.result << std::endl;
        CloseHandle(hThread);
    }

    system("pause");
    return 0;
}