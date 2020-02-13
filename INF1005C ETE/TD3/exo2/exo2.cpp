#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    bool prixCorrecte = false;
	while (prixCorrecte == false) {
	cout << "Entrez le prix d'un article avant taxes : ";
	double prixArticle;
	cin >> prixArticle;
		if (prixArticle < 0) {
			prixCorrecte = false;
		}
		else {
			double TPS = prixArticle * 0.05;
			double TVQ = prixArticle * 0.09975;
			cout << fixed << setprecision(2)
				<< "TPS " << TPS << endl
				<< "TVQ " << TVQ << endl
				<< "Solde total " << prixArticle + TPS + TVQ;
			prixCorrecte = true;
		}
	
	}

}