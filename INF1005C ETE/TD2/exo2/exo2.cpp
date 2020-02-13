////////////////////////////////////////////////////////////////////////////////
/**
* Programme qui demande trois noms d'animaux, trois adjectifs ainsi que trois noms de fruits et qui choisit aléatoirement
une entrée de chaque catégorie et les place dans la phrase suivante: «Aujourd’hui, j’ai vu un <animal> s’emparer d’un panier <adjectif> plein de <fruit>.»
* \file   Exercice2.cpp
* \author Annabelle Leblanc (1951018) et Murhad Masabbir (???)
* \date   15 mai 2019
* Créé le 13 mai 2019
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>    
#include <cstdlib>  
#include <string>   
using namespace std;
	
	int numeroAleatoire(int a)
	{
		return rand() % a;
		
	}
int main()
{
	srand(time(0));
	cout << "Entrez trois noms d'animaux : ";
	string animal[3];
	getline(cin, animal[0]);
	getline(cin, animal[1]);
	getline(cin, animal[2]);

	cout << "Entrer trois adjectifs masculins : ";
	string adjectif[3];
	getline(cin, adjectif[0]);
	getline(cin, adjectif[1]);
	getline(cin, adjectif[2]);

	cout << "Entrez trois noms de fruit : ";
	string fruit[3];
	getline(cin, fruit[0]);
	getline(cin, fruit[1]);
	getline(cin, fruit[2]);

	int x = 3;
	cout << "Aujourd'hui, j'ai vu un " << animal[numeroAleatoire(x)] << " s'emparer d'un panier " << adjectif[numeroAleatoire(x)] << " plein de " << fruit[numeroAleatoire(x)];
}


