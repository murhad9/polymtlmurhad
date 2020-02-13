////////////////////////////////////////////////////////////////////////////////
/// N'OUBLIEZ PAS VOS ENTÊTES DE FICHIER!
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <cstdlib>
#include <iostream>
#include <string>

#include "CodeFourni.hpp"
#include "CodeDemande.hpp"


using namespace std;

#pragma endregion //}


int main ( )
{
	static const string NOMS_FICHIERS_SORTIE[3] = {"out_norm.wav",
	                                               "out_fade.wav",
	                                               "out_all.wav"};

	// TODO: Demander et lire le nom du fichier de la pièce.
	cout << "Entrer le nom du fichier a lire : ";
	string nomFichier;
	cin >> nomFichier;
	ifstream fichier(nomFichier);
	// TODO: Demander et lire la cible de normalisation (entre 0.0 et 1.0)
	cout << "Entrer la valeur de la cible de normalisation (entre 0.0 et 1.0) : ";
	double cibleNormalisation;
	cin >> cibleNormalisation;
	// TODO: Demander et lire le début et la durée du fondu décroissant.
	cout << "Entrer le debut et la duree du fondu croissant : ";

	// TODO: Lire le fichier audio et afficher un message d'erreur si échec d'ouverture.

	// TODO: Faire deux copies de la liste.

	// TODO: Écrire le résultat de la normalisation dans "out_norm.wav", celui du fondu
	//       dans "out_fade.wav" et celui des deux dans "out_all.wav" et afficher
	//       un message d'erreur si échec d'écriture.

	// Faites attention aux fuites de mémoire!

	return 0;
}

