#include <iostream>
#include <fstream>               
#include <string>

using namespace std;

int main() {
	cout << "Entrez le nom du fichier : ";
	string nomFichier;
	cin >> nomFichier;
	ifstream fichier(nomFichier);
	if (fichier.fail()) {
		cout << "Probleme d'ouverture ";
	}
	else {
		cout << "Entrez un caractere a detecter : ";
		char charADetecter;
		cin >> charADetecter;
		while (!ws(fichier).eof()) {
			string mot;
			fichier >> mot;
			bool caractereDetectee = false;
			for (int i = 0; i < mot.size(); i++) {
				int j = 0;
				if (mot[i] == charADetecter) {
					caractereDetectee = true;
				}
				else {
					caractereDetectee = false;
				}

				if (caractereDetectee == true) {
					cout << mot << endl;
			}
			}

		}
		fichier.close();
	}
}