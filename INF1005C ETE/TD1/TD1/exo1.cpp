#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Entrer la valeur du voltage ";
	double voltage;
	cin >> voltage;
	cout << "Entrer la valeur de la resistance ";
	double resistance;
	cin >> resistance;
	double puissanceDissipee = (voltage * voltage) / resistance;
	cout << "La puissance dissipee est " << setprecision(3) << puissanceDissipee << " watts."; //Pas necessaire de mettre un setprecision
}