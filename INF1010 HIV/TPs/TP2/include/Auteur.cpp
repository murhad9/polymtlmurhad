// !Fonction auteur qui crée la classe Auteur
//! \authors Étienne Tremblay et Murhad Masabbir
//! \matricule 2022614 et 1991891
//! \date 11 février 2020

#include "Auteur.h"
#include <iostream>

//! Constructeur de la classe Auteur
//! \param nom              Nom de l'auteur
//! \param anneeDeNaissance Année de naissance de l'auteur
Auteur::Auteur(const std::string& nom, unsigned int anneeDeNaissance)
    : nom_(nom)
    , anneeDeNaissance_(anneeDeNaissance)
    , nbFilms_(0)
{
}

//! Méthode qui retourne le nom de l'auteur
//! \return Le nom de l'auteur
const std::string& Auteur::getNom() const
{
    return nom_;
}

//! Méthode qui retourne l'année de naissance de l'auteur
//! \return L'année de naissance de l'auteur
unsigned int Auteur::getAnneeDeNaissance() const
{
    return anneeDeNaissance_;
}

//! Méthode qui retourne le nombre de films de l'auteur
//! \return Le nombre de films de l'auteur
unsigned int Auteur::getNbFilms() const
{
    return nbFilms_;
}

//! Méthode qui set le nombre de films de l'auteur
//! \param nbFilms  Le nombre de films de l'auteur
void Auteur::setNbFilms(unsigned int nbFilms)
{
    nbFilms_ = nbFilms;
}
//! Opérateur qui affiche l'auteur 
//! \param os Le ostream pour l'affichage
//!        auteur L'auteur à afficher
std::ostream& operator<<(std::ostream& os, const Auteur& auteur) 
{
    os << "Nom: " << auteur.nom_ << " | Date de naissance: " << auteur.anneeDeNaissance_
           << " | Nombre de films: " << auteur.nbFilms_;

	return os;
}
//! Opérateur qu va compparer un auteurs avec un nom (string)
//! \param auteur l'auteur à comparer
//!        nom Nom de l'auteur a vérifier en string
//! \return bool qui indique si le string est le nom de l'auteur
bool operator==(const Auteur& auteur, const std::string& nom)
{
    return auteur.getNom() == nom;
}
//! Opérateur qu va compparer un auteurs avec un nom (string)
//! \param auteur l'auteur à comparer
//!        nom Nom de l'auteur a vérifier en string
//! \return bool qui indique si le string est le nom de l'auteur
bool operator==(const std::string& nom, const Auteur& auteur)
{
    return nom == auteur.getNom();
}

