////////////////////////////////////////////////////////////////////////////////
/// \file   CodeFourni.Cpp
/// \author Charles Hosson
/// \version Dernière entrée : 2018-06-04
/// \since   Création : 2017-01-27
///
/// Implémentation du code fourni.
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <fstream>
#include <string>

#include "CodeFourni.hpp"


using namespace std;

#pragma endregion //}


#pragma region "Définitions" //{

#pragma region "Fonctions" //{

/**
 * Crée un ensemble d'entêtes de fichier WAVE prêt à l'écriture à partir des
 * constantes du format du TD et d'une liste d'échantillons.
 *
 * \param [in] echantillons
 *        La liste d'échantillons que représentent les entêtes.
 *
 * \return Un \c EntetesFichierWave prêt à l'écriture.
 */
EntetesFichierWave
creerEntetes ( const ListeEchantillons& echantillons )
{
	EntetesFichierWave resultat;

	size_t nbOctetsDonnees = echantillons.nbElements * sizeof(Echantillon);

	resultat.riff = {ID_FICHIER_RIFF,
	                 sizeof(uint32_t) + sizeof(EnteteFormat) +
	                 sizeof(EnteteDonnees) + nbOctetsDonnees,
	                 ID_FORMAT_WAVE};

	resultat.format = {ID_BLOC_FORMAT,
	                   TAILLE_BLOC_FORMAT,
	                   ID_PCM,
	                   NB_CANAUX_STEREO,
	                   FREQUENCE_ECHANTILLONNAGE_CD,
	                   FREQUENCE_ECHANTILLONNAGE_CD * sizeof(Echantillon),
	                   sizeof(Echantillon),
	                   BITS_PAR_ECHANTILLON_CD};

	resultat.donnees = {ID_BLOC_DONNEES,
	                    nbOctetsDonnees};

	return resultat;
}


/**
 * Calcule un nombre d'échantillons à partir d'un temps en secondes et de la
 * fréquence d'échantillonnage.
 *
 * \param [in] temps
 *        La durée en secondes.
 *
 * \return Le nombre d'échantillons correspondant à la durée donnée.
 */
size_t
calculerNbEchantillons ( double temps )
{
	if ( temps >= (double)(size_t)-1 )
		return (size_t)-1;
	else
		return (size_t)(temps * FREQUENCE_ECHANTILLONNAGE_CD);
}

#pragma endregion //}

#pragma endregion //}

