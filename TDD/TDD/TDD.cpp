//класс для представления массива байт
class ByteArray
{};

//класс гипотетических команд
class SomeProtocolCommand
{};

//класс ответа
class SomeProtocolResponce
{};


//класс канала, по которому происходит обмен
class SomeExchangeChanel
{};

//класс, представляющий протокол
class SomeRealProtocol
{
public:
    SomeRealProtocol()
    {}

    virtual ~SomeRealProtocol()
    {}

    //метод, преобразующий команду в массив байт
    virtual ByteArray cmd2raw(const SomeProtocolCommand& cmd)
    {
        return ByteArray();
    }

    //метод, преобразующий полученные данные в ответ
    virtual SomeProtocolResponce data2Responce(const ByteArray& data)
    {
        return SomeProtocolResponce();
    }


    //метод, который выполняет сложный обмен со второй стороной
    virtual SomeProtocolResponce makeExchange(const SomeProtocolCommand& cmd)
    {
        return SomeProtocolResponce();
    }

};


/*
Отлично, у нас есть основные участники, теперь, в соответствии с философией TDD, нам нужно написать тесты, под которые мы потом будем писать код:
*/

class SomeTestSuite : public ::testing::Test
{
protected:
    void SetUp()
    {
        someProtocol = new SomeRealProtocol();
    }

    void TearDown()
    {
        delete someProtocol;
    }

protected:
    SomeRealProtocol* someProtocol;
};


TEST_F(SomeTestSuite, testcase1)
{
    //тестируем преобразование некой команды в бинарные данные, которые отправляются по каналам связи
    SomeProtocolCommand cmd;
    //преобразуем команду в бинарные данные в соответствии с протоколом
    ByteArray data = someProtocol->cmd2raw(cmd);
    //референс данных, которые должны быть получены
    ByteArray reference("\x21\x21\x32\x12\x12");
    //сравниваем полученное значение с референсом
    ASSERT_EQ(data, reference);
}

TEST_F(SomeTestSuite, testcase2)
{
    //тестируем разбор возвращаемых данных в соответствии с протоколом 
    //и превращение их в объект-ответ
    SomeProtocolResponce reference;
    //тестовые данные — гипотетический ответ
    ByteArray responceData("\x21\x21\x32\x12\x12");
    SomeProtocolResponce responce = someProtocol->data2Responce(responceData);
    //сравниваем полученное значение с референсом
    ASSERT_EQ(reference, responce);
}

TEST_F(SomeTestSuite, testcase3)
{
    //тут должна была быть проверка алгоритма при помощи мок’ов
}
