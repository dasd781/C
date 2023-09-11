//=============================================
#include <gtest/gtest.h>
#include<iostream>

//---------------------------------------------
//Класс, методы которого мы хотим протестировать
class ClassUnderTesting
{
public:
    ClassUnderTesting()
    {
        std::cout << "ClassUnderTesting()" << std::endl;
    }

    ~ClassUnderTesting()
    {
        std::cout << "~ClassUnderTesting()" << std::endl;
    }

public:
    int i = 0; //C++11 feature
};

//--------------------------------------------
class MyTestSuite : public ::testing::Test
{
protected:
    //Фикстура:
    //создаём и настраиваем условия, в которых будем прогонять тесты
    void SetUp()
    {
        //в нашем случае просто создаём объект для тестирования
        //и присваиваем начальное значение
        std::cout << "local setup" << std::endl;
        objUnderTesting = new ClassUnderTesting;
        objUnderTesting->i = 10;
    }


    //Тирдаун:
    //очищаем ресурсы, выделенные и задействованные во время тестирования
    void TearDown()
    {
        //в нашем случае просто удаляем объект, с которым проводим тестирование
        std::cout << "local teardown" << std::endl;
        delete objUnderTesting;
    }

protected:
    ClassUnderTesting* objUnderTesting;
};


//Тест-кейс 1
TEST_F(MyTestSuite, testcase1)
{
    ASSERT_EQ(objUnderTesting->i, 10); //проверка — значение в объекте должно быть 10
    objUnderTesting->i = 20;
}


//Тест-кейс 2
TEST_F(MyTestSuite, testcase2)
{
    ASSERT_EQ(objUnderTesting->i, 10); //проверка — значение в объекте должно быть 10
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set - up.
[----------] 2 tests from MyTestSuite
[RUN] MyTestSuite.testcase1
local setup
ClassUnderTesting()
local teardown
~ClassUnderTesting()
[OK] MyTestSuite.testcase1(0 ms)
[RUN] MyTestSuite.testcase2
local setup
ClassUnderTesting()
local teardown
~ClassUnderTesting()
[OK] MyTestSuite.testcase2(0 ms)
[----------] 2 tests from MyTestSuite(0 ms total)

[----------] Global test environment tear - down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[PASSED] 2 tests.