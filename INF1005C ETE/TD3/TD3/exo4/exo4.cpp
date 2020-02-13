#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Entrez une chaine de caracteres : ";
	string chaine;
	getline(cin, chaine);
	cout << "Entrez le caractere a detecter : ";
	char char1;
	cin >> char1;
	cout << "Entrez le caractere qui va remplacer ";
	char char2;
	cin >> char2;
	for (int i = 0; i < chaine.size(); i++) {
		if (chaine[i] == char1) {
			chaine[i] = char2;
		}
	}
	cout << chaine;
}