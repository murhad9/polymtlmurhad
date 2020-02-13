////////////////////////////////////////////////////////////////////////////////
/**
* Programme qui génère aléatoirement un nombre réel entre 1000.0 et 999999.99 et affiche celui-ci avec deux décimales
et un espace séparant les centaines des milliers.
* \file   Exercice3.cpp
* \author Annabelle Leblanc (1951018) et Murhad Masabbir (???)
* \date   15 mai 2019
* Créé le 13 mai 2019
*/
////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <ctime> 
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(0));
	const double min = 1000.0, max = 999999.99;
    double nombreAleatoire= (max - min) * ((double)rand() / RAND_MAX);
	cout << "Le nombre genere est " << int(nombreAleatoire - fmod(nombreAleatoire, 1000))/1000 << " " <<  fixed << setprecision(2) << fmod(nombreAleatoire, 1000);

}
