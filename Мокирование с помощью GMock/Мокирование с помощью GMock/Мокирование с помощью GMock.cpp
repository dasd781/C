// определяем интерфейс объекта, который далее будем использовать в алгоритме
class PainterInterface
{
public:
    PainterInterface()
    {}

    // как и положено, не забудем виртуальный деструктор
    virtual ~PainterInterface()
    {}


    // несколько виртуальных методов, которыми будем пользоваться
    virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
    virtual void drawRect(double xtl, double ytl, double xbr, double ybr) = 0;
    virtual void drawEllipse(double centerx, double centery, double ar, double br) = 0;

    virtual void saveState() = 0;
    virtual void restoreState() = 0;

};


// алгоритм, который в дальнейшем можно исследовать
// при помощи мок-объектов
void drawSomething(PainterInterface* painter)
{
    // сохраняем состояние painter’а
    painter->saveState();

    // рисуем нужную фигуру — 
    // окружность радиуса 5 вписанную в квадрат
    painter->drawLine(0, 0, 0, 10);
    painter->drawLine(0, 10, 10, 10);
    painter->drawLine(10, 10, 10, 0);
    painter->drawLine(10, 0, 0, 0);

    painter->drawEllipse(5, 5, 5, 5);

    // восстанавливаем состояние painter’а
    // СПЕЦИАЛЬНО закомментировали restoreState для демонстрации
    //   painter->restoreState();
}

// определяем класс мок-объекта на основе нужного нам интерфейса
class MockPainter : public PainterInterface {
public:
    // пользуемся макросами GTest для определения мок-методов в объекте
    MOCK_METHOD(void, drawLine, (double x1, double y1, double x2, double y2), (override));
    MOCK_METHOD(void, drawRect, (double xtl, double ytl, double xbr, double ybr), (override));
    MOCK_METHOD(void, drawEllipse, (double centerx, double centery, double ar, double br), (override));
    MOCK_METHOD(void, saveState, (), (override));
    MOCK_METHOD(void, restoreState, (), (override));
};


// наш тест
TEST(PainterTest, test1)
{
    MockPainter mpainter;


    // указываем «ожидания» по использованию — методы будут вызваны хотя бы N раз
    EXPECT_CALL(mpainter, saveState).Times(::testing::AtLeast(1));
    EXPECT_CALL(mpainter, restoreState).Times(::testing::AtLeast(1));

    EXPECT_CALL(mpainter, drawLine).Times(::testing::AtLeast(2));

    //указываем «ожидания» по использованию — методы будут вызваны точно N раз
    EXPECT_CALL(mpainter, drawEllipse).Times(1);
    EXPECT_CALL(mpainter, drawRect).Times(0);


    // запускаем алгоритм на выполнение
    drawSomething(&mpainter);
}

int main(int argc, char* argv[])
{
    // инициализация и запуск как обычно
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

