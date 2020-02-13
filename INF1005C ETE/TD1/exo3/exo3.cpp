#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	cout << "Entrer la valeur de a, b et c : ";
	double a, b, c;
	cin >> a >> b >> c;
	cout << "Entrer la valeur de x1, x2, et nPoints : ";
	double xMin, xMax, nPoints;
	cin >> xMin >> xMax >> nPoints;
	double bond = (xMax - xMin) / (nPoints - 1);
	cout << "Les valeurs (x,y) des " << nPoints << "points sont : " << endl;
	while (xMin <= xMax) {
	    double y = a * xMin * xMin + b * xMin + c;
		cout << xMin << "," << y << endl;
		xMin += bond;
	}
}