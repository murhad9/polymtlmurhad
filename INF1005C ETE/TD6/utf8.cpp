////////////////////////////////////////////////////////////////////////////////
///  Programme qui contient les fonctions utilisées pour le traitement de textes en UTF-8.
/// \file   utf8.cpp
/// \author Annabelle Leblanc(1951018) et Murhad Masabbir(1991891)
/// \date    18 juin 2019
///  Créé le 12 juin 2019
////////////////////////////////////////////////////////////////////////////////

#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <string>

#include "cppitertools/range.hpp"

#include "constantes.hpp"
#include "utf16.hpp"

#include "utf8.hpp"


using namespace std;
using namespace iter;

#pragma endregion //}


#pragma region "Définitions" //{

#pragma region "Fonctions" //{

/**
*  Calcule le nombre d'octets nécessaires pour encoder un point de code en UTF-8.
*  \param  [in]   pointCode           Le point de code duquel on détermine le nombre d'octets nécessaires pour l'encoder.
*  \return        nOctetsNecessaires  Le nombre d'octets nécessaires pour l'encodage du point de code.
*/
int
calculerNbOctetsEncodageUtf8(uint32_t pointCode)
{
	// TODO: Compter le nombre de bits significatifs du point de code.
	//       On veut les bits avant que tout le reste soit à 0.
	//       Par exemple, le nombre 0b01011010 a 7 bits significatifs.
	//       Autre exemple, le nombre 0b00000010 a 2 bits significatifs.
	bool ok = false;
	int  decalage = 31;
	int  nBitsSignificatifs = 0;
	while (!ok && (decalage >= 0)) {
		if (((pointCode >> decalage) & 1) != 0) {
			nBitsSignificatifs = decalage + 1;
			ok = true;
		}
		decalage--;
	}

	// TODO: Déterminer le nombre d'octets nécessaire à l'encodage à partir du nb de
	//       bits à encoder calculé précédemment (voir tableau dans l'énoncé ou sur Wikipedia).
	int nOctetsNecessaires = 0;
	if (nBitsSignificatifs <= 7) {
		nOctetsNecessaires = 1;
	}
	else if (nBitsSignificatifs <= 11) {
		nOctetsNecessaires = 2;
	}
	else if (nBitsSignificatifs <= 16) {
		nOctetsNecessaires = 3;
	}
	else if (nBitsSignificatifs <= 21) {
		nOctetsNecessaires = 4;
	}
	// TODO: Retourner le nombre d'octets nécessaire
	return (nOctetsNecessaires);
}

/**
*  Détermine le préfixe du premier octet en UTF-8.
*  \param  [in]   nbOctetsEncodage   Le nombre d'octets qu'on veut utiliser pour l'encodage.
*  \return        prefixe            Le préfixe du premier octet de l'encodage en UTF-8.
*/
uint8_t
calculerPrefixePremierOctetUtf8(int nbOctetsEncodage)
{
	// TODO: Déterminer et retourner le préfixe du premier octet selon le nombre d'octets de l'encodage.
	//       Voir tableau (la colonne Octet 1) et page Wiki.
	uint8_t prefixe = 0b11111111;   //On initialise ici le préfixe pour éviter un avertissement. De plus, cette valeur peut permettre de signaler une erreur dans l'exécution de la fonction.
	switch (nbOctetsEncodage) {
	case 1: prefixe = 0b00000000;
		break;
	case 2: prefixe = 0b11000000;
		break;
	case 3: prefixe = 0b11100000;
		break;
	case 4: prefixe = 0b11110000;
		break;
	default: break;
	}
	return(prefixe);
}

/**
*  Calcule un point de code à partir d'une séquence de données en UTF-8.
*  \param  [in]        sequenceUtf8     La sequence de données en UTF-8 à traiter pour déterminer le point de code correspondant.
*  \param  [out]       nbOctetsTraites  Le nombre d'octets traités dans la fonction.
*  \return             resultat         Le point de code obtenu de la séquence de données en UTF-8.
*/
uint32_t
calculerPointDeCodeUtf8(const uint8_t* sequenceUtf8, int& nbOctetsTraites)
{
	uint32_t resultat = INVALIDE;
	nbOctetsTraites = 0;
	int nOctetsEncodes = 0;
	// TODO: Si le premier octet de la séquence est en ASCII (< 0x80), retourner
	//       le premier octet et mettre 1 dans nbOctetsTraites.
	bool estASCII = sequenceUtf8[0] < 0x80;
	if (estASCII) {
		nbOctetsTraites = 1;
		return(sequenceUtf8[0]);
	}
	else {
		// TODO: Sinon :
		// TODO: Déterminer le nombre d'octets encodés pour le caractère. Il faut
		//       compter le nombre de bits à 1 avant le premier 0 en partant du plus
		//       haut ordre.
		//       Donc, si le premier octet est de la forme 1110xxxx, alors il faut
		//       trois octets (incluant le premier) pour encoder le caractère.
		int  decalage = 7;
		bool estIdentifie = ((sequenceUtf8[0] >> decalage) & 1) == 0;
		while ((!estIdentifie) && (decalage > 0)) {
			decalage--;
			nOctetsEncodes++;
			estIdentifie = ((sequenceUtf8[0] >> decalage) & 1) == 0;
		}
		// TODO: Extraire les bits de code du premier et les affecter au résultat.
		switch (nOctetsEncodes) {
		case 1: resultat = (uint32_t)(sequenceUtf8[0] ^ 0b00000000);
			break;
		case 2: resultat = (uint32_t)(sequenceUtf8[0] ^ 0b11000000);
			break;
		case 3: resultat = (uint32_t)(sequenceUtf8[0] ^ 0b11100000);
			break;
		case 4: resultat = (uint32_t)(sequenceUtf8[0] ^ 0b11110000);
			break;
		default: break;
		}
		// TODO: Initialiser nbOctetsTraites à 1
		nbOctetsTraites = 1;
	}
	// TODO: Pour chaque octet *SUIVANT* du caractère :
	// TODO: Incrémenter nbOctetsTraites.
	for (int i = 1; i < nOctetsEncodes; i++) {
		nbOctetsTraites++;

		// TODO: Si l'octet n'est pas de la forme 10xxxxxx, affecter INVALIDE
		//       Au résultat et quitter la boucle.
		bool estConforme = ((sequenceUtf8[i] >> 6) & 2) == 2;
		if (!estConforme) {
			resultat = INVALIDE;
			return resultat;
		}
		// TODO: Faire un décalage à gauche de six bits du résultat et y ajouter
		//       les six bits faibles de l'octet courant.
		resultat = (resultat << 6) + (sequenceUtf8[i] ^ 0b10000000);
	}

	return resultat;
}

/**
*  Encode un point de  code  en chaîne de caractères UTF-8.
*  \param  [in]       pointCode   Le point de code duquel on détermine son équivalent en chaîne de caractères UTF-8.
*  \param  [in/out]   resultat    La chaîne de caractères UTF-8 obtenue de la conversion.
*  \return  Aucun retour
*/
void
encoderCaractereUtf8(uint32_t pointCode, string& resultat)
{
	// TODO: Si le point de code est en ASCII (< 0x80), l'ajouter (push_back()) au résultat en convertissant en char.
	bool estASCII = pointCode < 0x80;
	if (estASCII) {
		resultat.push_back((char)pointCode);
	}
	else {
		// TODO: Sinon :
		// TODO: Compter le nombre de bits significatifs du point de code.
		bool ok = false;
		int  decalage = 31;
		int  nBitsSignificatifs = 0;
		while (!ok && (decalage >= 0)) {

			if (((pointCode >> decalage) & 1) != 0) {
				nBitsSignificatifs = decalage + 1;
				ok = true;
			}
			decalage--;
		}
		// TODO: Déterminer le nombre d'octets nécessaire à l'encodage (tableau dans l'énoncé ou sur Wikipedia).
		int nOctetsEncodage = calculerNbOctetsEncodageUtf8(pointCode);
		// TODO: Déterminer le préfixe du premier octet. Voir tableau et page Wiki.
		uint8_t prefixePremierOctet = calculerPrefixePremierOctetUtf8(nOctetsEncodage);
		// TODO: Déclarer un tableau de 4 octets (uint8_t).
		uint8_t octets[4];
		// TODO: Pour chaque octet sauf le premier, extraire les 6 bits faibles du
		//       point de code et les ajouter comme octet au tableau ave le préfixe 10xxxxxx,
		//       puis décaler le point de code de 6 bits.
		decalage = 0;
		for (int i = 0; i < (nOctetsEncodage - 1); i++) {
			uint8_t prefixe = 0b10000000;
			octets[i] = prefixe + (uint8_t)((pointCode >> decalage) & 0b0111111);
			decalage += 6;
		}
		// TODO: Ajouter au tableau l'octet avec les bits restant et le préfixe
		//       précédemment déterminé.
		octets[nOctetsEncodage - 1] = prefixePremierOctet + (uint8_t)(pointCode >> decalage);
		// TODO: Ajouter à la string les octets dans l'ordre inverse qu'il viennent
		//       d'être calculés.
		for (int i = (nOctetsEncodage - 1); i >= 0; i--) {
			resultat.push_back(octets[i]);
		}
	}

}

/**
*  Convertit une chaîne de caractères UTF-16 en chaîne de caractères UTF-8.
*  \param  [in]     str   La chaîne de caractères UTF-16 à convertir.
*  \return resultat       La chaîne de caractères en UTF-8 obtenue de la conversion.
*/
string
convertirStringVersUtf8(const u16string& str)
{
	string resultat;

	// TODO: Tant qu'il reste des codets dans str :
		// TODO: Calculer le point de code du caractère courant (fonction précédemment
		//       définie) et sauter le nombre de codet indiqué par nbCodetTraites (2e paramètre).
	const char16_t* codetCourant = (const char16_t*)&str[0];
	while (codetCourant < (const char16_t*)(&str[0] + str.size())) {
		int      nCodetsTraites;
		uint32_t pointCode = calculerPointDeCodeUtf16(codetCourant, nCodetsTraites);
		codetCourant += nCodetsTraites;
		// TODO: Si le point de code n'est pas invalide, l'encoder en UTF-8 dans la string de résultat.
		if (pointCode != INVALIDE) {
			encoderCaractereUtf8(pointCode, resultat);
		}
	}

	return resultat;
}

#pragma endregion //}

#pragma endregion //}

