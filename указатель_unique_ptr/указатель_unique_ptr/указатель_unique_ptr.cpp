#include<iostream>
#include<memory>//для std::unique_ptr

class Item
{
public:
	Item()
	{
		std::cout << "Item acquired\n";
	}
	~Item()
	{
		std::cout << "Item destroyed\n";
	}
	friend std::ostream& operator << (std::ostream& out, const Item &iteam)
	{
		out << "I am an Iteam!\n";
		return out;
	}
};

int main()
{
	std::unique_ptr<Item> item1(new Item);// выделение Item
	std::unique_ptr<Item> item2;//присваивание значения nullptr

	std::cout << "item1 is  " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
	std::cout << "item2 is  " << (static_cast<bool>(item2) ? "not null\n" : "null\n");

	// item2 = item1; не скомпелируется семантика копирования отключена
	item2 = std::move(item1);//item2 теперь владеет item1 присваевает значение null

	std::cout << "Ownership transferred\n";
	return 0;
}