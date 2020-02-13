#ifndef AUTEUR_H
#define AUTEUR_H

#include <string>

class Auteur
{
public:
    Auteur() = default;
    Auteur(const std::string& nom, unsigned int anneeDeNaissance);

    friend std::ostream& operator<<(std::ostream& os, const Auteur& auteur) ;
    friend bool operator==(const Auteur& auteur, const std::string& nom);
    friend bool operator==(const std::string& nom, const Auteur& auteur);

    const std::string& getNom() const;
    unsigned int getAnneeDeNaissance() const;
    unsigned int getNbFilms() const;

    void setNbFilms(unsigned int nbFilms);

private:
    std::string nom_;
    unsigned int anneeDeNaissance_;
    unsigned int nbFilms_;
};

#endif // AUTEUR_H