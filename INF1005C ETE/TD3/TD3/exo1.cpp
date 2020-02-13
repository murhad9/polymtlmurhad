#include <iostream>
using namespace std;

int main() {
	cout << "Entrer un nombre : ";
	int nombre;
	cin >> nombre;
	if (nombre % 2 == 0) {
		cout << "Ce nombre est pair";
	}
	else {
		cout << "Ce nombre est impair ";
	}

}