
#ifndef FILM_H
#define FILM_H

#include <memory>
#include <string>
#include "Auteur.h"
#include "Pays.h"

class Film
{
public:
    enum class Genre
    {
        first_ = -1,
        Action,
        Aventure,
        Comedie,
        Horreur,
        Romance,
        last_
    };

    Film() = default;
    Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
         bool estRestreintParAge, Auteur* auteur);

    void ajouterPaysRestreint(Pays pays);
    void supprimerPaysRestreints();
    bool estRestreintDansPays(Pays pays) const;
    void afficher(std::ostream& stream) const;

    Genre getGenre() const;
    bool estRestreintParAge() const;
    const std::string& getNom() const;
    Auteur* getAuteur();

private:
    // Attributs
    std::string nom_;
    unsigned int anneeDeSortie_;
    Genre genre_;
    Pays pays_;
    bool estRestreintParAge_;
    Auteur* auteur_;

    std::unique_ptr<Pays[]> paysRestreints_;
    std::size_t nbPaysRestreints_;
    std::size_t capacitePaysRestreints_;
};

#endif // FILM_H