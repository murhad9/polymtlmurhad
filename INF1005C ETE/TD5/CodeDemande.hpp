////////////////////////////////////////////////////////////////////////////////
/// N'OUBLIEZ PAS VOS ENTÊTES DE FICHIER!
////////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <fstream>
#include <string>

#include "CodeFourni.hpp"


using namespace std;

#pragma endregion //}


#pragma region "Déclarations" //{

#pragma region "Fonctions" //{

void ajouterElement ( ListeEchantillons&, const Echantillon& );

EntetesFichierWave lireEntetes ( istream& );

void lireEchantillons ( istream&, ListeEchantillons& );

void ecrireEchantillons ( ostream&, const ListeEchantillons& );

void ecrireFichierWave ( const string&, const ListeEchantillons&, bool& );

ListeEchantillons allouerListe ( size_t );

void desallouerListe ( ListeEchantillons& );

ListeEchantillons copierListe ( const ListeEchantillons& );

ListeEchantillons lireFichierWave ( const string&, bool& );

void normaliserVolume ( ListeEchantillons&, double );

void appliquerFonduDecroissant ( ListeEchantillons&, double, double );

#pragma endregion //}

#pragma endregion //}

