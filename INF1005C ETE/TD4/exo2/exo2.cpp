#include <iostream>
using namespace std;

void testeAdresses()
{
	//[
	int x = 5; // x est une variable qui contient un entier.
	int* pointeur; // pointeur est une variable qui contient l'adresse mémoire d'un entier.

	pointeur = &x; // Met l'adresse de x dans pointeur;
				   // x doit exister, mais n'a pas besoin d'avoir de valeur.

	cout << "L'adresse de x est " << &x << endl;
	cout << "Le contenu de x est " << x << endl;
	cout << "L'adresse de pointeur est " << &pointeur << endl;
	cout << "Le contenu de pointeur est " << pointeur << endl;
	cout << "Le contenu pointé par pointeur est " << *pointeur << endl;
	// Affichage:
	// L'adresse de x est 0013FF3C
	// Le contenu de x est 5
	// L'adresse de pointeur est 0013FF38
	// Le contenu de pointeur est 0013FF3C
	// Le contenu pointé par pointeur est 5
//]
	cout << endl;
	cout << "Changement du contenu pointé par pointeur." << endl;
	*pointeur = 12;
	cout << "L'adresse de x est " << &x << endl;
	cout << "Le contenu de x est " << x << endl;
	cout << "L'adresse de pointeur est " << &pointeur << endl;
	cout << "Le contenu de pointeur est " << pointeur << endl;
	cout << "Le contenu pointé par pointeur est " << *pointeur << endl;
	cout << endl;
	cout << "Changement du contenu de pointeur." << endl;
	pointeur = nullptr; // nullptr est nouveau à C++11, il faut utiliser NULL dans les anciennes versions de C++.
	cout << "L'adresse de pointeur est " << &pointeur << endl;
	cout << "Le contenu de pointeur est " << pointeur << endl;
	//cout << "Le contenu pointé par pointeur est " << *pointeur << endl; // Déréférencer un pointeur null fait une erreur.
	cout << endl;
	//[
	cout << "Changement du contenu de pointeur." << endl;
	pointeur = new int;  // Adresse d'un emplacement vide pour un entier.
	cout << "L'adresse de pointeur est " << &pointeur << endl;
	cout << "Le contenu de pointeur est " << pointeur << endl;
	cout << "Le contenu pointé par pointeur est " << *pointeur << endl;
	cout << endl;
	cout << "Changement du contenu pointé par pointeur." << endl;
	// Un pointeur doit contenir une adresse valide avant de le déréférencer.
	// Un pointeur non initialisé ne pointe pas vers une adresse valide.
	*pointeur = 1234;
	cout << "L'adresse de pointeur est " << &pointeur << endl;
	cout << "Le contenu de pointeur est " << pointeur << endl;
	cout << "Le contenu pointé par pointeur est " << *pointeur << endl;
	delete pointeur; // Recycle l'emplacement alloué.
	// Affichage:
	// Changement du contenu de pointeur.
	// L'adresse de pointeur est 0013FF38
	// Le contenu de pointeur est 00032F30
	// Le contenu pointé par pointeur est 0
	//
	// Changement du contenu pointé par pointeur.
	// L'adresse de pointeur est 0013FF38
	// Le contenu de pointeur est 00032F30
	// Le contenu pointé par pointeur est 1234
//]
	cout << endl;
}

int main()
{
	testeAdresses();
	//[
	int     ageAlex = 7, ageSandie = 27;
	double  x = 1.2345, y = 32.14;

	int* ptrEntier = &ageAlex;
	*ptrEntier += ageSandie;
	cout << "ageAlex est " << *ptrEntier << endl;

	double* ptrReel = &x;
	y += 5 * (*ptrReel);
	cout << "Y contient la valeur " << y << endl;

	char a[] = "A";
	const char* car1 = a;  // La valeur *car1 ne peut être modifiée
	char* const car2 = a;  // Le pointeur car2 ne peut être modifié
	cout << car1 << car2 << endl;

	// Affichage:
	// ageAlex est 34
	// Y contient la valeur 38.3125
	// AA
//]
}
