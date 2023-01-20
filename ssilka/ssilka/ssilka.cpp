#include<iostream>
using namespace std;

void square( int &x ) {
	x = x * x;
}

int main() {
	int y = 3;
	square(y);
	cout << " y - " << y << endl;
	return 0;


}