#ifndef GESTIONNAIREAUTEURS_H
#define GESTIONNAIREAUTEURS_H

#include <string>
#include "Auteur.h"

class GestionnaireAuteurs
{
public:
    GestionnaireAuteurs();

    bool ajouterAuteur(const Auteur& auteur);
    Auteur* chercherAuteur(const std::string& nomAuteur);
    bool chargerDepuisFichier(const std::string& nomFichier);
    void afficher(std::ostream& stream) const;

    std::size_t getNbAuteurs() const;

    static constexpr std::size_t NB_AUTEURS_MAX = 16;

private:
    bool lireLigneAuteur(const std::string& ligne);

    Auteur auteurs_[NB_AUTEURS_MAX];
    std::size_t nbAuteurs_;
};

#endif // GESTIONNAIREAUTEURS_H