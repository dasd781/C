#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // для утверждения()

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length) :
        m_length{ length }
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length] {};
    }

    IntArray(const IntArray& a)
    {
        // Задайте размер нового массива соответствующим образом
        reallocate(a.getLength());

        // Затем скопируйте элементы
        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];
    }

    ~IntArray()
    {
        delete[] m_data;
        //  Здесь не нужно устанавливать m_data в null или m_length в 0, 
        // так как 
        //объект все равно будет уничтожен сразу после этой функции
    }

    void erase()
    {
        delete[] m_data;
        // Нам нужно убедиться, что мы установили m_data в nullptr здесь,
        //  иначе это будет
        //  быть оставленным указывающим на освобожденную память!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // перераспределение изменяет размер массива.  
    // Любые существующие элементы будут уничтожены.  
    //Эта функция работает быстро.
    void reallocate(int newLength)
    {
        // Сначала мы удаляем все существующие элементы
        erase();

        // Если наш массив теперь будет пустым, вернитесь сюда
        if (newLength <= 0)
            return;

        // Затем мы должны выделить новые элементы
        m_data = new int[newLength];
        m_length = newLength;
    }

    // изменение размера изменяет размер массива. 
    // Все существующие элементы будут сохранены.
    //Эта функция работает медленно.
    void resize(int newLength)
    {
        // Если массив уже имеет правильную длину, все готово
        if (newLength == m_length)
            return;

        // Если мы изменяем размер до пустого массива, сделайте это и верните
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь мы можем предположить, что newLength составляет не менее
        //  1 элемента.  Этот алгоритм
        // Работает следующим образом: Сначала мы выделим новый массив.  Тогда мы
        // собираются скопировать элементы из существующего массива в новый массив.
        // Как только это будет сделано, мы сможем уничтожить старый массив
        //  и сделать m_data
        // наведите указатель мыши на новый массив.

        // Сначала мы должны выделить новый масси
        int* data{ new int[newLength] };

        // Затем мы должны выяснить, сколько элементов копировать из существующих
        // массив в новый массив.  Мы хотим скопировать столько элементов, сколько есть
        // в меньшем из двух массивов.
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            // Теперь скопируйте элементы один за другим
            for (int index{ 0 }; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // Теперь мы можем удалить старый массив, потому что он нам больше не нужен.
        delete[] m_data;

        // И используйте вместо этого новый массив! 
        // Обратите внимание, что это просто делает m_data точку зрения.
        // на тот же адрес, что и новый массив, который мы динамически выделяли. 
        // Потому что
        // данные были динамически распределены, 
        //они не будут уничтожены, когда выйдут за рамки.
        m_data = data;
        m_length = newLength;
    }

    IntArray& operator=(const IntArray& a)
    {
        // Самостоятельная проверка назначения
        if (&a == this)
            return *this;

        //  Задайте размер нового массива соответствующим образом
        reallocate(a.getLength());

        // Затем скопируйте элементы
        for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];

        return *this;
    }

    void insertBefore(int value, int index)
    {
        // Здравомыслие проверьте значение нашего индекса
        assert(index >= 0 && index <= m_length);

        // Сначала создайте новый массив на один элемент больше старого массива
        int* data{ new int[m_length + 1] };

        // Скопируйте все элементы в индекс
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        // Вставьте наш новый элемент в новый массив
        data[index] = value;

        // Копирование всех значений после вставленного элемента
        for (int after{ index }; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Наконец, удалите старый массив и используйте вместо него новый массив
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        // Здравомыслие проверьте значение нашего индекса
        assert(index >= 0 && index < m_length);

        // Если мы удаляем последний элемент в массиве, мы можем просто стереть массив and return early
        if (m_length == 1)
        {
            erase();
            return;
        }

        // Сначала создайте новый массив на один элемент меньше старого массива
        int* data{ new int[m_length - 1] };

        // Скопируйте все элементы в индекс
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        // Скопируйте все значения после удаленного элемента
        for (int after{ index + 1 }; after < m_length; ++after)
            data[after - 1] = m_data[after];

        //  Наконец, удалите старый массив и используйте вместо него новый массив
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // Пара дополнительных функций просто для удобства
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    int getLength() const { return m_length; }
};

#endif