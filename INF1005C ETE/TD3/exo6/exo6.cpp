#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int detecterLettre(string &str) {
	int longueur = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			longueur++;
		}
		}
		return longueur;
	}


int main() {
	cout << "Entrez le nom du fichier : ";
	string nomFichier;
	cin >> nomFichier;
	ifstream fichier(nomFichier);
	while (fichier.fail()) {
		cout << "Le fichier n'existe pas ";
		cin >> nomFichier;
	}
	 
	while (!ws(fichier).eof()) {
		string mot;
		fichier >> mot;


	}
	
	
	
	
	
	}
}