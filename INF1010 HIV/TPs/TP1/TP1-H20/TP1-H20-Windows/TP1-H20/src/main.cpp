//! Fonction main qui test le programme
//! \author Simon Gauvin
//! \date 15 janvier 2020

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include "GestionnaireAuteurs.h"
#include "Librairie.h"
#include "Utilisateur.h"
#include "debogageMemoire.h"

// NOTE: Pour que le programme compile, vous pouvez changer tous les #if true à des #if false,
// et mettre en commentaire tout le code qui a été écrit pour vous. Ainsi, vous pourrez
// graduellement les #if true et tester des petits blocs de code à la fois. Commencez par
// écrire vos constructeurs!

int main()
{
    initDebogageMemoire();

    GestionnaireAuteurs gestionnaireAuteurs;
    Librairie librairie;

    std::vector<bool> tests;

#if true
    // Test 1 et 2: Lecture des fichiers et affichage.
    // Assurez-vous de mettre les fichiers à la bonne place pour que
    // le programme puisse les trouver.
    // Chaque fichier se fait charger deux fois, mais le résultat devrait
    // être le même que si chaque fichier se faisait charger une fois.
    // N'oubliez pas de reset les variables nécessaires dans vos méthodes
    // pour que le double chargement ne change rien!
    
    // Si vous rencontrez des problèmes ici, comparez votre sortie de console
    // à celle de l'énoncé.
    bool resultatLectureAuteurs = gestionnaireAuteurs.chargerDepuisFichier("auteurs.txt") &&
                                  gestionnaireAuteurs.chargerDepuisFichier("auteurs.txt");

    bool resultatLectureFilms =
        librairie.chargerFilmsDepuisFichier("films.txt", gestionnaireAuteurs) &&
        librairie.chargerFilmsDepuisFichier("films.txt", gestionnaireAuteurs);
    bool resultatLectureRestrictions =
        librairie.chargerRestrictionsDepuisFichiers("restrictionsPays.txt") &&
        librairie.chargerRestrictionsDepuisFichiers("restrictionsPays.txt");

    // Test 1: Affichage des auteurs
    std::stringstream auteursStream;
    gestionnaireAuteurs.afficher(auteursStream);
    std::string auteurString = auteursStream.str();
    std::cout << auteurString <<'\n'; // Affichage dans la console
    const std::string sortieAttendueAuteurs =
        "Nom:GeorgeLucas|Datedenaissance:1944|Nombredefilms:6Nom:JohnRonaldReuelTolkien|"
        "Datedenaissance:1892|Nombredefilms:3";

    auteurString.erase(
      std::remove_if(auteurString.begin(), auteurString.end(),
                     [](unsigned char c) { return std::isspace(c); }),
      auteurString.end());
    
     tests.push_back(sortieAttendueAuteurs == auteurString && resultatLectureAuteurs == true &&
                    gestionnaireAuteurs.getNbAuteurs() == 2);

    // Test 2: Affichage des films et des restrictions
	    std::stringstream librairieStream;
    librairie.afficher(librairieStream);
    std::string librairieString = librairieStream.str();
    std::cout << librairieString; // Affichage dans la console
    const std::string sortieAttendueLibrairie =
        "ANewHopeDatedesortie:1977Genre:ActionAuteur:GeorgeLucasPays:EtatsUnisAucunpaysrestreint."
        "TheEmpireStrikesBackDatedesortie:1980Genre:ActionAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.ReturnoftheJediDatedesortie:1983Genre:ActionAuteur:"
        "GeorgeLucasPays:EtatsUnisAucunpaysrestreint.RaidersoftheLostArkDatedesortie:1981Genre:"
        "AventureAuteur:GeorgeLucasPays:EtatsUnisPaysrestreints:"
        "BresilCanadaChineEtatsUnisFranceJaponRoyaumeUniRussieMexiqueIndianaJonesandtheTempleofDoom"
        "Datedesortie:1984Genre:AventureAuteur:GeorgeLucasPays:EtatsUnisAucunpaysrestreint."
        "IndianaJonesandtheLastCrusadeDatedesortie:1989Genre:AventureAuteur:GeorgeLucasPays:"
        "EtatsUnisAucunpaysrestreint.TheLordoftheRings:TheFellowshipoftheRingDatedesortie:"
        "2001Genre:AventureAuteur:JohnRonaldReuelTolkienPays:RoyaumeUniAucunpaysrestreint."
        "TheLordoftheRings:TheTwoTowersDatedesortie:2002Genre:AventureAuteur:"
        "JohnRonaldReuelTolkienPays:RoyaumeUniAucunpaysrestreint.TheLordoftheRings:"
        "TheReturnoftheKingDatedesortie:2003Genre:AventureAuteur:JohnRonaldReuelTolkienPays:"
        "RoyaumeUniPaysrestreints:ChineFranceJaponRussie";

    librairieString.erase(
      std::remove_if(librairieString.begin(), librairieString.end(),
                     [](unsigned char c) { return std::isspace(c); }),
      librairieString.end());
      
    tests.push_back(sortieAttendueLibrairie == librairieString && resultatLectureFilms == true &&
                    resultatLectureRestrictions && librairie.getNbFilms() == 9);
#else
    tests.push_back(false);
    tests.push_back(false);
#endif

#if true
    // Test 3: Fonction d'ajout d'auteurs
    bool test3Reussi = true;
    // Remplir le tableau des auteurs
    for (auto i = gestionnaireAuteurs.getNbAuteurs(); i < GestionnaireAuteurs::NB_AUTEURS_MAX; i++)
    {
        bool succes = gestionnaireAuteurs.ajouterAuteur(Auteur("", 0));
        if (succes == false)
        {
            test3Reussi = false;
            tests.push_back(false);
            break;
        }
    }
    // Ajouter un autre auteur devrait retourner false puisque le tableau est etre plein
    if (test3Reussi == true)
    {
        bool succes = gestionnaireAuteurs.ajouterAuteur(Auteur("", 0));
        tests.push_back(!succes);
    }
#else
    tests.push_back(false);
#endif

#if true
    // Test 4: Fonction recherche d'auteurs
    const Auteur* auteurTest = gestionnaireAuteurs.chercherAuteur("George Lucas");
    const Auteur* auteurInexsistant = gestionnaireAuteurs.chercherAuteur("qwerty");
    if (auteurTest == nullptr || auteurInexsistant != nullptr)
        tests.push_back(false);
    else
        tests.push_back(auteurTest->getAnneeDeNaissance() == 1944);
#else
    tests.push_back(false);
#endif

#if true
    // Test 5: Ajouter des films
    std::size_t nbFilmsAvantTest8 = librairie.getNbFilms();
    static constexpr unsigned int test8NbFilmsAjouter = 200;
    Auteur auteurTest8("auteur test8", 1234);
    for (unsigned int i = 0; i < test8NbFilmsAjouter; i++)
    {
        librairie.ajouterFilm(
            new Film("test", 1, Film::Genre::Action, Pays::Canada, false, &auteurTest8));
    }
    // Ajouter un film nullptr ne devrait rien faire
    librairie.ajouterFilm(nullptr);
    tests.push_back(librairie.getNbFilms() == nbFilmsAvantTest8 + test8NbFilmsAjouter);
#else
    tests.push_back(false);
#endif

#if true
    // Test 6: Supprimer des films
    // On supprime tous les films ajoutés au test 8
    std::size_t nbFilmsAvantTest9 = librairie.getNbFilms();
    for (unsigned int i = 0; i < test8NbFilmsAjouter; i++)
    {
        librairie.retirerFilm("test");
    }
    // Et on supprime un film qui n'existe pas
    librairie.retirerFilm("asdf");
    tests.push_back(librairie.getNbFilms() + test8NbFilmsAjouter == nbFilmsAvantTest9 &&
                    librairie.getNbFilms() == nbFilmsAvantTest8);

#else
    tests.push_back(false);
#endif

#if true
    // Test 7: Recherche film
    Film* raidersOfTheLostArk = librairie.chercherFilm("Raiders of the Lost Ark");
    tests.push_back(raidersOfTheLostArk != nullptr &&
                    raidersOfTheLostArk->getGenre() == Film::Genre::Aventure &&
                    raidersOfTheLostArk->getNom() == "Raiders of the Lost Ark" &&
                    librairie.chercherFilm("asdf") == nullptr);
#else
    tests.push_back(false);
#endif

#if true
    // Test 8: Utilisateur non premium limite de films
    Auteur auteur("Test", 23);
    Film film("film1", 1990, Film::Genre::Comedie, Pays::Mexique, false, &auteur);
    film.ajouterPaysRestreint(Pays::Russie);
    Utilisateur utilisateurNonPremium("Jean", 20, false, Pays::Japon);
    for (unsigned int i = 0; i < 5; i++)
    {
        utilisateurNonPremium.regarderFilm(film);
    }
    tests.push_back(utilisateurNonPremium.getNbFilmsVus() == Utilisateur::NB_FILMS_GRATUITS);

    // Test 9: Utilisateur premium avec restrictions pays
    Utilisateur utilisateurPremium("Claudette", 20, true, Pays::Chine);
    film.ajouterPaysRestreint(Pays::Chine);
    utilisateurPremium.regarderFilm(film);
    Film film2("film2", 1990, Film::Genre::Aventure, Pays::France, true, &auteur);
    unsigned int nbFilmARegarder = 10;
    for (unsigned int i = 0; i < nbFilmARegarder; i++)
    {
        utilisateurPremium.regarderFilm(film2);
    }
    tests.push_back(utilisateurPremium.getNbFilmsVus() == nbFilmARegarder);

    // Test 10: Utilisateur premium avec restrictions age
    Utilisateur utilisateurPremium2("Guillaume", 12, true, Pays::Japon);
    Film film3("film3", 1995, Film::Genre::Aventure, Pays::France, false, &auteur);
    auto result1 = utilisateurPremium2.regarderFilm(film2);
    auto result2 = utilisateurPremium2.regarderFilm(film3);
    tests.push_back(utilisateurPremium2.getNbFilmsVus() == 1 && !result1 && result2);

#else
    tests.push_back(false);
    tests.push_back(false);
    tests.push_back(false);
#endif

    std::vector<float> ponderationTests = {1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5};

    // Affichage
    float totalPoints = 0;
    for (std::size_t i = 0; i < tests.size(); i++)
    {
        std::string output = "Test " + std::to_string(i + 1) + ": ";
        if (tests[i] == true)
        {
            output += "OK!";
            std::stringstream stream;
            stream << ponderationTests[i] << '/' << ponderationTests[i];
            std::cout << std::left <<  std::setw(15) << std::left << output << stream.str() << '\n';
            totalPoints += ponderationTests[i];
        }
        else
        {
            output += "ECHEC!";
            std::stringstream stream;
            stream << '0' << '/' << ponderationTests[i];
            std::cerr << std::left <<  std::setw(15) << output << "0/" << ponderationTests[i] << '\n';
        }
    }
    std::stringstream stream;
    stream << totalPoints << "/"
           << std::accumulate(ponderationTests.begin(), ponderationTests.end(), 0.0f);
    std::cout << std::left << std::setw(16) << "TOTAL: " << stream.str() << '\n';
}
