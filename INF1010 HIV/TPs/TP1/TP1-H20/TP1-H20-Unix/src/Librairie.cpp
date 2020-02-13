// TODO: Faire l'entête de fichier

// TODO: Inclure la définition de la classe appropriée
#include "debogageMemoire.h"
#include "typesafe_enum.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace {
constexpr std::size_t CAPACITE_FILMS_INITIALE = 2;
constexpr int FILM_INEXSISTANT = -1;
} // namespace

// TODO: Constructeur par défault en utilisant la liste d'initialisation
// Utiliser CAPACITE_FILMS_INITIALE pour la taille initiale de films_
// (allocation dynamique!)

// TODO: Destructeur
// Faire appel à la fonction supprimerFilms()
// Ne pas oublier de désallouer le tableau ET les films

//! Méthode qui ajoute un film à la liste des films.
//! \param film Le film alloué dynamiquement à ajouter à la liste. La classe
//! devient propriétaire du
//!             film.
void Librairie::ajouterFilm(Film *film) {
  static constexpr unsigned int AUGMENTATION_CAPACITE_FILMS = 2;

  // TODO
  // Verifier si assez de mémoire est allouée
  // Si pas assez de mémoire, doubler la taille du tableau
  // (AUGMENTATION_CAPACITE_FILMS) Ajouter le film au tableau seulement si film
  // n'est pas un nullptr
}

// TODO: retirerFilm(const std::string& nomFilm)
// Retirer un film ayant le même nom que celui envoyé en paramètre
// Si le film n'existe pas, ne rien faire
// Faire appel à la fonction trouverIndexFilm

// TODO chercherFilm(const std::string& nomFilm)
// Retourner un pointeur vers le film recherché
// Si le film n'existe pas, retourner nullptr
// Utiliser la fonction trouverIndexFilm

//! Méthode qui charge les films à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour
//! associer un film à un
//!                             auteur.
//! \return                     Un bool représentant si le chargement a été un
//! succès.
bool Librairie::chargerFilmsDepuisFichier(
    const std::string &nomFichier, GestionnaireAuteurs &gestionnaireAuteurs) {
  std::ifstream fichier(nomFichier);
  if (fichier) {
    // TODO
  }
  std::cerr << "Le fichier " << nomFichier
            << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
  return false;
}

//! Méthode qui charge les restrictions des films à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \return                     Un bool représentant si le chargement a été un
//! succès.
bool Librairie::chargerRestrictionsDepuisFichiers(
    const std::string &nomFichier) {
  std::ifstream fichier(nomFichier);
  if (fichier) {
    // TODO
  }
  std::cerr << "Le fichier " << nomFichier
            << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
  return false;
}

//! Méthode qui affiche la liste des films.
//! \param stream Le stream dans lequel afficher.
void Librairie::afficher(std::ostream &stream) const {
  // Ne pas modifier cette méthode
  for (std::size_t i = 0; i < nbFilms_; i++) {
    films_[i]->afficher(stream);
    stream << '\n';
  }
}

// TODO getNbFilms() const: Retourner le nombre de films

// TODO supprimerFilms()
// Supprimer les films du tableau (delete)

//! Méthode qui ajoute les restrictions d'un film avec un string.
//! \param ligne Le string comportant les restrictions du film.
//! \return      Un bool représentant si l'opération est un succès.
bool Librairie::lireLigneRestrictions(const std::string &ligne) {
  std::istringstream stream(ligne);
  std::string nomFilm;
  // TODO
  // Pour extraire tout ce qui se trouve entre "" dans un stream,
  // il faut faire stream >> std::quoted(variable)
  // Utiliser l'opérateur d'extraction (>>) pour retrouver le nom du film
  // Trouver le film qui comporte le nom
  // Si le film n'existe pas, retourner false
  // Faire une boucle while (stream >> int), puis utiliser ce int pour appeler
  // la fonction film->ajouterPaysRestreint
}

//! Méthode qui ajoute un film avec un string comportant les attributs du film.
//! \param ligne                Le string comportant les attributs du film.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour
//! associer un film à un
//!                             auteur.
//! \return                     Un bool représentant si l'opération est un
//! succès.
bool Librairie::lireLigneFilm(const std::string &ligne,
                              GestionnaireAuteurs &gestionnaireAuteurs) {
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
  // Utiliser l'opérateur d'extraction (>>) pour retrouver les attributs du
  // films Si l'auteur n'existe pas, retourner false Utiliser la fonction
  // ajouter film
}

// TODO: trouverIndexFilm(const std::string& nomFilm) const
// Retourner l'indexe du film comportant le nom envoyé en paramètre
// Si le film n'existe pas, retourner -1 (FILM_INEXSISTANT)