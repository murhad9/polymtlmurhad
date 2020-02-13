#include <iostream>
using namespace std;

int main() {
	cout << "Entrer les valeurs de x et y du premier vecteur : ";
	double x1, y1;
	cin >> x1 >> y1;
	cout << "Entrer les valeurs de x et y du deuxieme vecteur : ";
	double x2, y2;
	cin >> x2 >> y2;
	if ((x1 * x2 + y1 * y2) == 0)
		cout << "Les vecteurs sont orthogonaux";
	else
		cout << "Les vecteurs ne sont pas orthogonaux";

}