// TODO: Faire l'entête de fichier

// TODO: Inclure la définition de la classe appropriée
#include <iostream>

// TODO: Constructeur par paramètre en utilisant la liste d'initialisation

//! Méthode qui affiche un auteur.
//! \param stream Le stream dans lequel afficher.
void Auteur::afficher(std::ostream &stream) const {
  // Ne modifiez pas cette fonction
  stream << "Nom: " << nom_ << " | Date de naissance: " << anneeDeNaissance_
         << " | Nombre de films: " << nbFilms_;
}

// TODO getNom() const: Retourner le nom

// TODO getAnneeDeNaissance() const: Retourner l'annee de naissance

// TODO getNbFilms() const: Retourner le nombre de films de l'auteur

// TODO setNbFilms(unsigned int nbFilms): Set le nombre de films de l'auteur
