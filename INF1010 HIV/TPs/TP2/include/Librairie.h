#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

#include <memory>
#include "Film.h"
#include "GestionnaireAuteurs.h"
#include <vector>

class Librairie
{
public:
    Librairie() = default;
    Librairie(const Librairie& librairieCopie);//Constructeur pas copie
    ~Librairie();
    //Declaration des operateurs
    Librairie& operator=(const Librairie& librairie);
    Librairie& operator+=(Film* film);
    Librairie& operator-=(const std::string& nomFilm);
    Film* chercherFilm(const std::string& nomFilm) const;
    bool chargerFilmsDepuisFichier(const std::string& nomFichier,
                                   GestionnaireAuteurs& gestionnaireAuteurs);
    bool chargerRestrictionsDepuisFichiers(const std::string& nomFichier);
    friend std::ostream& operator<<(std::ostream& os,
                                    const Librairie& librairie);

	 const std::vector<std::unique_ptr<Film>>& getFilms() const;
    std::size_t getNbFilms() const;

private:
    void supprimerFilms();
    bool lireLigneRestrictions(const std::string& ligne);
    bool lireLigneFilm(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs);
    int trouverIndexFilm(const std::string& nomFilm) const;

	std::vector<std::unique_ptr<Film>> films_;//Un vecteur de unique_ptr de films comme attribut
};

#endif // LIBRAIRIE_H