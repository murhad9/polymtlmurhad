/**
* Programme qui qui permet de déterminer pour un entier n donné par l’utilisateur le plus petit entier a tel que
Sn est plus petit ou égal à a où Sn est la somme des termes 1/k pour k allant de 1 jusqu'à n.
* \file   exo7.cpp
* \author Annabelle Leblanc (1951018) et Murhad Masabbir (1991891)
* \date   26 mai 2019
* Créé le 15 mai 2019
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

int f1(int t[]) {
	string mot = "aababbccb";
	int m = 0;
	for (unsigned i = 0; i < mot.size(); i++) {
		int d = mot[i] - 'a';
		if (d >= m) {
			t[d]++;
			m = d;
		}
	}
	return m;
}

int main() {
	static const int TAILLE = 10;
	int f[TAILLE] = { };
	cout << f1(f) << ' ';
	for (int i = 0; i < TAILLE; i++)
		if (f[i] != 0)
			cout << i << ':' << f[i] << ' ';
	/*[*/ return 0; /*]*/
}