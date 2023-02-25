
template <typename T>
void func(T arg)
{
	cout << arg << endl;
}
template<typename T>
void wrapper(T arg)
{
	func<T>(arg);
}
/*В такой реализации при передаче аргумента arg  функции func будет происходить 
копирование аргумента. Нам бы хотелось избежать
излишнего копирования. Для этого мы можем передавать arg с помощью ссылки:*/
template <typename T>
void func(T arg)
{
	cout << arg << endl;
}
template <typename T>
void wrapper(const T& arg)
{
	func<T>(arg);
}


template<typename T>
void foo(T arg)
{
	T& a = arg;
}
int i = 1;
foo<int&>(i);