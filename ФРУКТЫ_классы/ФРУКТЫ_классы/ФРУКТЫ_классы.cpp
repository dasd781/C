#include"Vegetable.h"
#include"Fruit.h"
#include"Avocado.h"

int main()
{
	IFood* grocery[5];

	grocery[0] = new Apple(50, string("Green"));
	grocery[1] = new Banana(50, 10);
	grocery[2] = new Potato(10, 10);
	grocery[3] = new Tomato(10, string("cherry"));
    grocery[4] = new Avocado(25, 30);

	bool open = true;
	while (open)
    {
        cout << "Выберите продукт : 1 - яблоко, 2 - банан, 3 - картофель, 4 - томат, 5 - авокадо 0 чтобы выйти" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            grocery[0]->Show();
            break;

        case 2:
            grocery[1]->Show();
            break;

        case 3:
            grocery[2]->Show();
            break;

        case 4:
            grocery[3]->Show();

        case 5:
            grocery[4]->Show();
            break;

        case 0:
            open = false;
            break;

        default:
            cout << "Выберите продукт от 1 до 5 или 0, чтобы выйти" << endl;
            break;
        }
    }

    delete grocery[0];
    delete grocery[1];
    delete grocery[2];
    delete grocery[3];
    delete grocery[4];

    return 0;
	
}