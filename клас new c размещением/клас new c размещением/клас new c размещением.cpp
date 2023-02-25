//создадим класс
class ClassData
{
public:
	//внутри поля
	//поленимся и не будем заботится о стилистическом 
	//оформлении класса
	int a;
	int b;
	//конструктор
	ClassData()
	{
		a = 5;
		b = 10;
	}
	//метод чтобы получить a
	int getA()const
	{
		return a;
	}
	//метод чтобы получить b
	int getB()const
	{
		return b;
	}

};
int main(int argc, char* argv[])
{
	//выделим память на стэке для 10 обьектов
	unsigned char buff[sizeof(ClassData) * 10];
		//обнулим память для чистоты эксперемента
	memset(buff, 0, sizeof(ClassData) * 10);
	// длятого чтобы обькты создавались в сырой памяти
	//(смотрите выше мы выделяли именно нужное колличество байт
	// а не обьекты ClassData
	ClassData* cursor = new(buff) ClassData[10];
	ClassData* classData2 = cursor + 2;
	//теперь при выводе значения А мы увидем 5 (а не 0)
	//как и должно быть поскольку в конструкторе по 
	//умолчанию мы задаем значение а равное 5
	std::cout << classData2->getA() << std::endl;
}
