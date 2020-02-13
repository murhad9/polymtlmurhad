// TODO: Faire l'entête de fichier
//! Classe Librarie qui s'occupe principalement d'un tableau de films.
//! \author Étienne Tremblay et Murhad Masabbir
//! \date 27 janvier 2020

// TODO: Inclure la définition de la classe appropriée
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "debogageMemoire.h"
#include "typesafe_enum.h"
#include "Librairie.h"

namespace
{
    constexpr std::size_t CAPACITE_FILMS_INITIALE = 2;
    constexpr int FILM_INEXSISTANT = -1;
}

// TODO: Constructeur par défault en utilisant la liste d'initialisation
// Utiliser CAPACITE_FILMS_INITIALE pour la taille initiale de films_ (allocation dynamique!)

Librairie::Librairie() : nbFilms_(0), capaciteFilms_(CAPACITE_FILMS_INITIALE)
{
	films_ = new Film*[CAPACITE_FILMS_INITIALE];
	for (int i = 0; i < CAPACITE_FILMS_INITIALE; i++)
		films_[i] = nullptr;
}

// TODO: Destructeur
// Faire appel à la fonction supprimerFilms()
// Ne pas oublier de désallouer le tableau ET les films


Librairie::~Librairie()
{
	supprimerFilms();
	delete[] films_;
	films_ = nullptr;

}

//! Méthode qui ajoute un film à la liste des films.
//! \param film Le film alloué dynamiquement à ajouter à la liste. La classe devient propriétaire du
//!             film.
void Librairie::ajouterFilm(Film* film)
{
    static constexpr unsigned int AUGMENTATION_CAPACITE_FILMS = 2;

    // TODO
    // Verifier si assez de mémoire est allouée
	if (nbFilms_ >= capaciteFilms_)
	{
		size_t nouvelleCapacite = capaciteFilms_ * AUGMENTATION_CAPACITE_FILMS;
		Film** nouveauTableau = new Film*[nouvelleCapacite];

		for (int i = 0; i < nbFilms_; i++) {
			nouveauTableau[i] = films_[i];
		}

		delete[] films_;

		films_ = nouveauTableau;
		capaciteFilms_ = nouvelleCapacite;	
	}
	if (film != nullptr)
		films_[nbFilms_++] = film;
    // Si pas assez de mémoire, doubler la taille du tableau (AUGMENTATION_CAPACITE_FILMS)
    // Ajouter le film au tableau seulement si film n'est pas un nullptr
}



// TODO: retirerFilm(const std::string& nomFilm)
// Retirer un film ayant le même nom que celui envoyé en paramètre
// Si le film n'existe pas, ne rien faire
// Faire appel à la fonction trouverIndexFilm

void Librairie::retirerFilm(const std::string& nomFilm)
{
	int indexFilm = trouverIndexFilm(nomFilm);
	if (indexFilm != FILM_INEXSISTANT)
	{
		delete films_[indexFilm];
		films_[indexFilm] = films_[nbFilms_ - 1];
		nbFilms_--;
	}
}



// TODO chercherFilm(const std::string& nomFilm)
// Retourner un pointeur vers le film recherché
// Si le film n'existe pas, retourner nullptr
// Utiliser la fonction trouverIndexFilm

Film* Librairie::chercherFilm(const std::string& nomFilm)
{
	int indexFilm = trouverIndexFilm(nomFilm);
	if (indexFilm != FILM_INEXSISTANT)
	{
		return films_[indexFilm];
	}

	return nullptr;
}
//! Méthode qui charge les films à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour associer un film à un
//!                             auteur.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerFilmsDepuisFichier(const std::string& nomFichier,
                                          GestionnaireAuteurs& gestionnaireAuteurs)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
		supprimerFilms();
		std::string ligne;
		while (!ws(fichier).eof())
		{
			std::getline(fichier, ligne);
			if (lireLigneFilm(ligne, gestionnaireAuteurs) == false) {
				return false;
			}

		}
		return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez-vous de le mettre au bon endroit.\n";
    return false;
}

//! Méthode qui charge les restrictions des films à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerRestrictionsDepuisFichiers(const std::string& nomFichier)
{
	std::ifstream fichier(nomFichier);
	if (fichier)
	{
		// TODO
		for (int i = 0; i < nbFilms_; i++) {
			films_[i]->supprimerPaysRestreints();
		}
		std::string ligne;
		while (!ws(fichier).eof()) {
			
			std::getline(fichier, ligne);
			if (lireLigneRestrictions(ligne) == false) {
				return false;
			}
		}
		return true;
	}
		std::cerr << "Le fichier " << nomFichier
			<< " n'existe pas. Assurez-vous de le mettre au bon endroit.\n";
		return false;
}
//! Méthode qui affiche la liste des films.
//! \param stream Le stream dans lequel afficher.
void Librairie::afficher(std::ostream& stream) const
{
    // Ne pas modifier cette méthode
    for (std::size_t i = 0; i < nbFilms_; i++)
    {
        films_[i]->afficher(stream);
        stream << '\n';
    }
}



// TODO getNbFilms() const: Retourner le nombre de films
std::size_t Librairie::getNbFilms() const
{
	return nbFilms_;
}

// TODO supprimerFilms()
// Supprimer les films du tableau (delete)

void Librairie::supprimerFilms()
{
	for (int i = 0; i < nbFilms_; i++) {
		if (films_[i] != nullptr) {
			films_[i]->getAuteur()->setNbFilms(0);
			delete films_[i];
			films_[i] = nullptr;
		}
	}
	nbFilms_ = 0;
}

//! Méthode qui ajoute les restrictions d'un film avec un string.
//! \param ligne Le string comportant les restrictions du film.
//! \return      Un bool représentant si l'opération est un succès.
bool Librairie::lireLigneRestrictions(const std::string& ligne)
{
    std::istringstream stream(ligne);
    std::string nomFilm;
    // TODO
    // Pour extraire tout ce qui se trouve entre "" dans un stream,
    // il faut faire stream >> std::quoted(variable)
    // Utiliser l'opérateur d'extraction (>>) pour retrouver le nom du film
    // Trouver le film qui comporte le nom
    // Si le film n'existe pas, retourner false
    // Faire une boucle while (stream >> int), puis utiliser ce int pour appeler la fonction
    // film->ajouterPaysRestreint

	stream >> std::quoted(nomFilm);
	int indexFilm = trouverIndexFilm(nomFilm);
	if (indexFilm == FILM_INEXSISTANT) {
		return false;
	}
	int restriction;
	while (stream >> restriction) {
		films_[indexFilm]->ajouterPaysRestreint(to_enum<Pays>(restriction));
	}
	return true;

}

//! Méthode qui ajoute un film avec un string comportant les attributs du film.
//! \param ligne                Le string comportant les attributs du film.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour associer un film à un
//!                             auteur.
//! \return                     Un bool représentant si l'opération est un succès.
bool Librairie::lireLigneFilm(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs)
{
    std::istringstream stream(ligne);
    std::string nomFilm;
    unsigned int anneeSortie;
    int genreValeurEnum;
    int paysValeurEnum;
    bool estRestreintParAge;
    std::string nomAuteur;
	

    // TODO
    // Pour extraire tout ce qui se trouve entre "" dans un stream,
    // il faut faire stream >> std::quoted(variable)
    // Utiliser l'opérateur d'extraction (>>) pour retrouver les attributs du films
    // Si l'auteur n'existe pas, retourner false
    // Utiliser la fonction ajouter film

	stream >> std::quoted(nomFilm) >> anneeSortie >> 
				genreValeurEnum >> paysValeurEnum >> 
				estRestreintParAge >> std::quoted(nomAuteur);

	Auteur* auteur = gestionnaireAuteurs.chercherAuteur(nomAuteur);
	if (auteur == nullptr)
	{
		return false;
	}
	if (auteur != nullptr) {
		Film* film = new Film(nomFilm, anneeSortie, to_enum<Film::Genre>(genreValeurEnum),
			to_enum<Pays>(paysValeurEnum), estRestreintParAge, auteur);
		ajouterFilm(film);
		auteur->setNbFilms(auteur->getNbFilms()+1);
		return true;
	}

	return true;

}


// TODO: trouverIndexFilm(const std::string& nomFilm) const
// Retourner l'indexe du film comportant le nom envoyé en paramètre
// Si le film n'existe pas, retourner -1 (FILM_INEXSISTANT)

int Librairie::trouverIndexFilm(const std::string& nomFilm) const
{
	for (int i = 0; i < nbFilms_; i++)
	{
		if (films_[i]->getNom() == nomFilm) {
			return i;
		}
	}
	return FILM_INEXSISTANT;
}
