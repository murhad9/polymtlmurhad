#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include "Film.h"
#include "Pays.h"

class Utilisateur
{
public:
    Utilisateur(const std::string& nom, unsigned int age, bool estPremium, Pays pays);

    // Functions
    bool filmEstDisponible(const Film& film) const;
    bool nbLimiteFilmsAtteint() const;
    bool regarderFilm(const Film& film);

    // Getters
    unsigned int getNbFilmsVus() const;

    static constexpr unsigned int NB_FILMS_GRATUITS = 3;

private:
    std::string nom_;
    unsigned int age_;
    unsigned int nbFilmsVus_;
    bool estPremium_;
    Pays pays_;
};

#endif // UTILISATEUR_H