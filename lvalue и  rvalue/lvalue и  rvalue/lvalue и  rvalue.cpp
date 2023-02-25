int a = 42; // a - lvalue
int b = 45; // b - lvalue
b = 17; // присваивание нового значения lvalue b
int c = a * b;// c -lvalue присваиваем значение умножения a * b
a + b = 19; // a + b rvalue не можем присвоить значение

int foo()
{
	return 42;
}
int& bar()
{
	static int i = 0;
	return i;
}
int a = foo();// foo возвращает rvalue можем присвоить значение переменной а
bar() = 1;// bar() возвращает lvalue можем присвоить значение
foo() = 9; //ошибка foo() возвращает rvalue 

int& // lvalue ссылка 

int&& //rvalue ссылка

void foo(int& a);// foo принимает lvalue- ссылку
void foo(int&& a); //foo принимает rvalue - ссылку


