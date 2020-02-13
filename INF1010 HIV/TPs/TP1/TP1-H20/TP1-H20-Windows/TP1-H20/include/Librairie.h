#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

#include <memory>
#include "Film.h"
#include "GestionnaireAuteurs.h"

class Librairie
{
public:
    Librairie();
    Librairie(const Librairie&) = delete;
    Librairie(Librairie&&) = delete;
    Librairie& operator=(const Librairie&) = delete;
    Librairie& operator=(Librairie&&) = delete;
    ~Librairie();

    void ajouterFilm(Film* film);
    void retirerFilm(const std::string& nomFilm);
    Film* chercherFilm(const std::string& nomFilm);
    bool chargerFilmsDepuisFichier(const std::string& nomFichier,
                                   GestionnaireAuteurs& gestionnaireAuteurs);
    bool chargerRestrictionsDepuisFichiers(const std::string& nomFichier);
    void afficher(std::ostream& stream) const;

    std::size_t getNbFilms() const;

private:
    void supprimerFilms();
    bool lireLigneRestrictions(const std::string& ligne);
    bool lireLigneFilm(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs);
    int trouverIndexFilm(const std::string& nomFilm) const;

    // Movies array
    Film** films_;
    std::size_t nbFilms_;
    std::size_t capaciteFilms_;
};

#endif // LIBRAIRIE_H