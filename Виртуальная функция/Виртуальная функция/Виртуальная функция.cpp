#include<iostream>
using namespace std;

class Basse
{
public:
	void Show()
	{
		cout << "Dasse Class" << endl;
	}
};
class Derived : public Basse
{
public:
	void Show()
	{
		cout << "Derived Class" << endl;
	}
};
int main()
{
	Basse basse;
	Derived derived;
	Basse* pbasse = &basse;
	Basse* pderived = &derived;
	pbasse->Show();
	pderived->Show();

	return 0;
}