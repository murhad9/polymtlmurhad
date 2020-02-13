////////////////////////////////////////////////////////////////////////////////
/// \file   main.cpp
/// \author Charles Hosson
///
/// Fonction principale du programme.
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include "cppitertools/range.hpp"

#include "debogageMemoire.hpp"
#include "unicode.hpp"

#include "constantes.hpp"
#include "utf8.hpp"
#include "utf16.hpp"


using namespace std;
using namespace iter;

#pragma endregion //}


void exempleAffichageUnicode();

int main()
{
	initDebogageMemoire(); // Affichera dans la "Sortie" de VisualStudio les fuites de mémoire.
	initUnicode();


	const string nomsFichiersEntree[3] = { "TroisMousquetaires.txt",
										  "CaracteresAnciens.txt",
										  "Katyusha.txt" };
	const string nomsFichiersSortieUtf16[3] = { "TroisMousquetaires_UTF-16.txt",
											   "CaracteresAnciens_UTF-16.txt",
											   "Katyusha_UTF-16.txt" };
	const string nomsFichiersSortieUtf8[3] = { "TroisMousquetaires_UTF-8.txt",
											   "CaracteresAnciens_UTF-8.txt",
											   "Katyusha_UTF-8.txt" };

	// TODO: Lire chaque fichier (en UTF-8), le convertir en UTF-16 puis l'écrire
	//       dans un fichier avec le nom correspondant dans nomsFichiersSortieUtf16.
	//       N'oubliez pas le Byte Order Mark qui est sur deux octets.
	for (int i = 0; i < 3; i++) {
		ifstream fichierUtf8Lecture(nomsFichiersEntree[i], ios::binary);
		if (fichierUtf8Lecture.fail()) {
			wcout << "Le fichier de lecture " << nomsFichiersEntree[i] << " est introuvable." << endl;
		}
		ofstream fichierUtf16Ecriture(nomsFichiersSortieUtf16[i], ios::binary);
		if (fichierUtf16Ecriture.fail()) {
			wcout << "L'écriture du fichier " << nomsFichiersSortieUtf16[i] << " est impossible." << endl;
		}
		if (!(fichierUtf8Lecture.fail() || fichierUtf16Ecriture.fail())) {
			fichierUtf8Lecture.seekg(0, ios::beg);
			fichierUtf16Ecriture.seekp(0, ios::beg);
			u16string resultatUtf16;
			string    texteUtf8;
			while (fichierUtf8Lecture.peek() != EOF) {
				char caractereUtf8;
				fichierUtf8Lecture.read((char*)& caractereUtf8, sizeof(caractereUtf8));
				texteUtf8 += caractereUtf8;
			}
			uint16_t pointCodeBOM = BOM;
			fichierUtf16Ecriture.write((char*)& pointCodeBOM, sizeof(pointCodeBOM));
			resultatUtf16 = convertirStringVersUtf16(texteUtf8);
			fichierUtf16Ecriture.write((char*)& resultatUtf16[0], 2 * resultatUtf16.size());
		}
	}
	// TODO: Lire chaque fichier précédement créés en UTF-16, puis les retraduire
	//       en UTF-8 dans un fichier avec le nom correspondant dans nomsFichiersSortieUtf8.
	//       Faites attention de sauter le BOM (deux octets) en lisant les caractères.
	for (int i = 0; i < 3; i++) {
		ifstream fichierUtf16Lecture(nomsFichiersSortieUtf16[i], ios::binary);
		if (fichierUtf16Lecture.fail()) {
			wcout << "Le fichier de lecture " << nomsFichiersSortieUtf16[i] << " est introuvable." << endl;
		}
		ofstream fichierUtf8Ecriture(nomsFichiersSortieUtf8[i], ios::binary);
		if (fichierUtf8Ecriture.fail()) {
			wcout << "L'écriture du fichier " << nomsFichiersSortieUtf8[i] << " est impossible." << endl;
		}
		if (!(fichierUtf16Lecture.fail() || fichierUtf8Ecriture.fail())) {
			fichierUtf16Lecture.seekg(sizeof(char16_t), ios::beg);
			fichierUtf8Ecriture.seekp(0, ios::beg);
			char16_t  caractereUtf16;
			u16string texteUtf16;
			while (fichierUtf16Lecture.peek() != EOF) {
				fichierUtf16Lecture.read((char*)& caractereUtf16, sizeof(caractereUtf16));
				texteUtf16.push_back(caractereUtf16);
			}
			string resultatUtf8 = convertirStringVersUtf8(texteUtf16);
			fichierUtf8Ecriture.write((char*)& resultatUtf8[0], resultatUtf8.size());
		}

	}

	return 0;
}


void exempleAffichageUnicode()
{
	// Après avoir initialisé Unicode, vous devez absolument utiliser wcout au lieu de cout.  L'utilisation de cout vous donnera une erreur de "symbole ambigu".
	// Vous pouvez tout de même utiliser des chaînes de caractères non Unicode et les afficher sur wcout.

	// Exemples de chaînes C non Unicode:
	static const char texteNonUnicode[] = "Un texte pas Unicode permet l'affichage des caractères Latin-1, àâéèêïùç...\n";
	wcout << "Une chaine de 'char' est considérée en Latin-1 (pas Unicode):" << endl
		<< texteNonUnicode << endl;

	// Exemples de chaînes C Unicode, noter l'utilisation de wchar_t (un caractère Unicode sur 16 bits) au lieu de char (un caractère sur 8 bits), et l'utilisation du L devant les guillemets:
	// (si vous oubliez le L et que vous utilisez des caractères spéciaux, vous aurez l'avertissement "le caractère ... ne peut pas être représenté dans la page de codes actuelle")
	static const wchar_t texteUnicode[] = L"Russe: Добрый день\nGrec: Γεια σας\nTeintes de gris: ░▒▓█\n";
	wcout << L"Une chaine de 'wchar_t' est Unicode et permet les caractères plus spéciaux ♪♫:" << endl
		<< texteUnicode << endl;

	// Exemple de string (pas Unicode) et wstring (Unicode):
	static const string stringNonUnicode = "Une string avec caractères Latin-1.";
	static const wstring stringUnicode = L"Une string Unicode ░▒▓█♪♫.";
	wcout << stringNonUnicode << endl // Nous avons fourni une fonction qui permet d'afficher des 'string' sur wcout.
		<< stringUnicode << endl;

	// Vous pouvez utilise cin comme d'habitude; ce programme le ne configure pas pour être en unicode.
}

