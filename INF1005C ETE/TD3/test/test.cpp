/**
* Programme qui lit un fichier et qui affiche un histogramme des longueurs de mots
ainsi que le nombre d'occurrence de chaque longueur de mot.
* \file   exo6.cpp
* \author Annabelle Leblanc (1951018) et Murhad Masabbir (1991891)
* \date   26 mai 2019
* Créé le 15 mai 2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string nomDuFichier;
	cout << "Entrez le nom du fichier :";
	cin >> nomDuFichier;
	fstream fichier(nomDuFichier);
	while (fichier.fail()) {
		cout << "Le fichier est introuvable. Veuillez saisir de nouveau le nom du fichier :";
		cin >> nomDuFichier;
	}
	string mot;
	int occurrence[30] = { 0 };
	int taille;
	int i;
	while (!(fichier.eof())) {
		fichier >> mot;
		taille = mot.length();
		i = 0;
		while (i < mot.length()) {
			if (!isalpha(mot[i])) {
				taille--;
			}
			i++;
		}
		for (int j = 0; j < 30; j++) {
			if (taille == (j + 1)) {
				occurrence[j]++;
			}
		}


	}
	static const int nbLongueurs = 30;
	for (int j = 0; j < nbLongueurs; j++) {
		int longueur = j + 1;
		cout << longueur << " :" << occurrence[j];
		cout << endl;
	}
}


