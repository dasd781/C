#include <algorithm>
#include <iostream>

using namespace std;

void merge(int* arr, int l, int m, int r)
{
    const int nl = m - l + 1;
    const int nr = r - m;

    // создаем временные массивы
    int* left = new int[nl];
    int* right = new int[nr];

    // копируем данные во временные массивы
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;  // начало левой части

    while (i < nl && j < nr) {
        // копируем данные во временные массивы
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl) 
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr) 
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void insertionSort(int* arr, int l, int r)
{
    for (int i = l + 1; i <= r; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        // сдвигаем элементы arr[0....i-1]
        // которые больше чем key на одну позицию в перед
        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void timSort(int* arr, int n)
{
    const int RUN = 16;
    // сортируем отдельные подмассивы размера RUN
    for (int i = 0; i < n; i += RUN) 
    {
        int l = i;
        int r = i + RUN - 1;

        if (r >= n)
            insertionSort(arr, l, n - 1);
        else
            insertionSort(arr, l, r);


    }
    // ваш код вызывающий сортировку вставками с правильными аргументами

// Обьединяем все отсортированные массивы
    for (int size = RUN; size < n; size = 2 * size)
    {
        // Объединяем arr [left..left + size-1] и arr [left + size, left + 2 * size-1]
        // После каждого слияния мы увеличиваем левый размер на 2
        for (int left = 0; left < n; left += 2 * size)
        {
            // находим среднюю и правую границу
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid > right)
                mid = left;
            // соединяем подмассивы arr[left.....mid] и arr[mid+1....right]
            merge(arr, left, mid, right);
        }
    }
}
int main() {
    int arr[]{ 38, 30, 14, 30, -1, 21, 9, 26, 22, -5, 34, -6, 19, 9, 13, 16, -10, -5, 0, 32, 19, 24, 33, -5, 11, 7, -6, 3, 1, -6, 16, -1, 34, -8, -8, -4, 24, 11, 32, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    timSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}