// TODO: Faire l'entête de fichier
//! Classe Utlilisateur qui décrit les fonctions d'un utilisateur de CinéPoly.
//! \author Étienne Tremblay et Murhad Masabbir
//! \date 27 janvier 2020

// TODO: Inclure la définition de la classe appropriée
#include "Utilisateur.h"

// TODO: Constructeur utilisant la liste d'initialisation

Utilisateur::Utilisateur(const std::string& nom, unsigned int age, bool estPremium, Pays pays) : 
	nom_(nom), age_(age), estPremium_(estPremium), pays_(pays), nbFilmsVus_(0)
{
}

//! Méthode qui retourne si le film est disponible pour un utilisateur.
//! \param film Le film à évaluer.
//! \return Un bool représentant si un film est disponible à l'utilisateur.
bool Utilisateur::filmEstDisponible(const Film& film) const
{
    static constexpr unsigned int AGE_MINIMUM_POUR_FILMS_RESTREINTS = 16;
    // TODO
    // Vérifier que le film n'est pas restreint dans le pays de l'utilisateur
    // Vérifier que l'utilisateur a l'âge approprié pour regarder le film (s'il est est restreint
    // pour les moins de 16 ans).

	if (film.estRestreintParAge()) 
			return age_ >= AGE_MINIMUM_POUR_FILMS_RESTREINTS && !film.estRestreintDansPays(pays_);
		else
			return !film.estRestreintDansPays(pays_);
	
}

// TODO nbLimiteFilmsAtteint() const
// Retourner si l'utilisateur a atteint la limite de films qu'il peut regarder
// Si un utilisateur est premium, il n'y a pas de limite
// Si un utilisateur n'est pas premium, il peut regarder au maximum NB_FILMS_GRATUITS

bool Utilisateur::nbLimiteFilmsAtteint() const
{
	return !estPremium_ && nbFilmsVus_ >= NB_FILMS_GRATUITS;
	
}

// TODO regarderFilm(const Film& film)
// Vérifier que l'utilisateur n'a pas atteint la limite de films qu'il peut regarder
// Vérifier que le film est disponnible dans le pays de l'utilisateur
// Si ces deux conditions sont remplies, incrémenter nbFilmsVus_ et retourner true
// Sinon, retourner false
bool Utilisateur::regarderFilm(const Film& film)
{
	if (filmEstDisponible(film) && !nbLimiteFilmsAtteint())
	{
		nbFilmsVus_++;
		return true;
	}

	return false;
}


// TODO getNbFilmsVus() const: Retourner le nombre de films vus
unsigned int Utilisateur::getNbFilmsVus() const
{
	return nbFilmsVus_;
}