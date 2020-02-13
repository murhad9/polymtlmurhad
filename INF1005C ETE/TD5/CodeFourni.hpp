////////////////////////////////////////////////////////////////////////////////
/// \file   CodeFourni.hpp
/// \author Charles Hosson
/// \version Dernière entrée : 2017-03-20
/// \since   Création : 2017-01-27
///
/// Le code fourni aux élèves est constitué des structures d'enregistrement
/// et de fonctions utilitaires pour les fichiers WAVE.
////////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <istream>
#include <ostream>
#include <string>


using namespace std;

#pragma endregion //}


#pragma region "Déclarations" //{

#pragma region "Constantes" //{

static const uint32_t ID_FICHIER_RIFF = 0x46464952; // "RIFF"
static const uint32_t ID_FORMAT_WAVE = 0x45564157;  // "WAVE"
static const uint32_t ID_BLOC_FORMAT = 0x20746D66;  // "fmt "
static const uint32_t ID_BLOC_DONNEES = 0x61746164; // "data"

static const uint32_t TAILLE_BLOC_FORMAT = 16;
static const uint16_t ID_PCM = 1;
static const uint16_t NB_CANAUX_STEREO = 2;
static const uint32_t FREQUENCE_ECHANTILLONNAGE_CD = 44100;
static const uint16_t BITS_PAR_ECHANTILLON_CD = 16;

#pragma endregion //}


#pragma region "Structures" //{

/**
 * \struct Echantillon
 * \brief  Un échantillon LPCM stéréo
 * 
 * Un échantillon est un point quantifié d'une courbe d'onde sonore. Nous
 * utilisons ici une modulation d'impulsion codée linéaire sur 16 bits.
 * Cela signifie que chaque échantillon est composé de deux valeurs (droite et
 * gauche) allant de 0 à ±32767.
 * <p>
 * Le format utilisé ici est un LPCM à 16 bits signé en stéréo avec une fréquence
 * d'échantillonnage de 44.1 kHz. Ceci correspond au format des CD audio.
 */
struct Echantillon
{
	int16_t gauche;
	int16_t droite;
};


/**
 * \struct ListeEchantillons
 * \brief  Une liste d'échantillons
 * 
 * Une liste de données sous forme d'un tableau (pointeur) de \c Echantillon,
 * dont la capacité indique l'espace alloué, donc la taille maximale de la
 * liste. \c nbElements donne le nombre d'échantillons contenus dans la
 * liste (pas la taille du tableau).
 */
struct ListeEchantillons
{
	size_t       nbElements;
	size_t       capacite;
	Echantillon* elements;
};


/**
 * \struct EnteteRiff
 * \brief  L'entête d'un fichier RIFF
 * 
 * Les fichiers WAVE sont des instances de Ressource Interchange File Format (RIFF),
 * un conteneur générique de données.
 */
struct EnteteRiff
{
	uint32_t idBloc;
	uint32_t tailleFichier; 
	uint32_t formatFichier;
};


/**
 * \struct EnteteFormat
 * \brief  Le bloc de format
 * 
 * Le bloc de format donne des informations sur les caractéristiques audio d'un
 * fichier WAVE : fréquence, encodage, nombre de canaux, etc.
 */
struct EnteteFormat
{
	uint32_t idBloc;
	uint32_t tailleBloc;
	uint16_t formatAudio;
	uint16_t nbCanaux;
	uint32_t frequence;
	uint32_t octetsParSeconde;
	uint16_t tailleEchantillon;
	uint16_t bitsParEchantillon;
};


/**
 * \struct EnteteDonnees
 * \brief  Le bloc d'entête des données
 * 
 * Cet entête marque le début du tableau d'échantillons (les données) dans le
 * fichier. Le membre \c tailleBloc indique le nombre d'octets d'échantillon,
 * pas le nombre d'échantillons.
 */
struct EnteteDonnees
{
	uint32_t idBloc;
	uint32_t tailleBloc;
};


/**
 * \struct EntetesFichierWave
 * \brief  L'ensemble des entêtes d'un fichier WAVE
 * 
 * Un fichier WAVE est un conteneur de données audio qui déclare beaucoup
 * d'information dans ses entêtes. Les entêtes sont dans le fichier binaire juste
 * avant les échantillons.
 * <p>
 * Pour créer un \c EntetesFichierWave à partir d'une liste d'échantillons et
 * des caractéristiques audio du format utilisé dans le TD, il faut utiliser la
 * fonction \c creerEntetes().
 */
struct EntetesFichierWave
{
	EnteteRiff    riff;
	EnteteFormat  format;
	EnteteDonnees donnees;
};

#pragma endregion //}


#pragma region "Fonctions" //{

EntetesFichierWave creerEntetes ( const ListeEchantillons& );

size_t calculerNbEchantillons ( double );

#pragma endregion //}

#pragma endregion //}

