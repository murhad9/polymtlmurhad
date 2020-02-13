////////////////////////////////////////////////////////////////////////////////
/// N'OUBLIEZ PAS VOS ENTÊTES DE FICHIER!
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <string>

#include "constantes.hpp"
#include "utf8.hpp"

#include "utf16.hpp"


using namespace std;

#pragma endregion //}


#pragma region "Définitions" //{

#pragma region "Fonctions" //{

uint32_t
calculerPointDeCodeUtf16 ( const char16_t* sequenceUtf16, int& nbCodetsTraites )
{
	uint32_t resultat = INVALIDE;
	nbCodetsTraites = 0;
	
	bool estMultiCodet = MULTI_CODET_UTF16_HAUT <= sequenceUtf16[0] and sequenceUtf16[0] <= 0xDFFF;
	
	if ( not estMultiCodet ) {
		resultat = (uint32_t)sequenceUtf16[0];
		nbCodetsTraites = 1;
	}
	else {
		bool estMultiCodetValide = estMultiCodet and
		                           (sequenceUtf16[0] & 0b1111110000000000) == MULTI_CODET_UTF16_HAUT and
		                           (sequenceUtf16[1] & 0b1111110000000000) == MULTI_CODET_UTF16_BAS;
		if ( estMultiCodetValide ) {
			resultat = (uint32_t)((sequenceUtf16[0] & 0b1111111111) << 10) | (sequenceUtf16[1] & 0b1111111111);
			resultat += 0x010000;
			nbCodetsTraites = 2;
		}
	}
	
	return resultat;
}


void
encoderCaractereUtf16 ( uint32_t pointCode, u16string& resultat )
{
	if ( pointCode <= UINT16_MAX ) {
		resultat.push_back((char16_t)pointCode);
	}
	else {
		static const int MASQUE_10_BITS = 0b1111111111;
		pointCode -= UINT16_MAX + 1;
		char16_t codetBas = (pointCode & MASQUE_10_BITS) + MULTI_CODET_UTF16_BAS;
		char16_t codetHaut = ((pointCode >> 10) & MASQUE_10_BITS) + MULTI_CODET_UTF16_HAUT;
		resultat.push_back(codetHaut);
		resultat.push_back(codetBas);
	}
}


u16string
convertirStringVersUtf16 ( const string& str )
{
	u16string resultat;
	
	const uint8_t* octetCourant = (const uint8_t*)&str[0];
	while ( octetCourant < (const uint8_t*)(&str[0] + str.size()) ) {
		int nbOctetsTraites = 0;
		uint32_t pointCode = calculerPointDeCodeUtf8(octetCourant, nbOctetsTraites);
		octetCourant += nbOctetsTraites;
		
		if ( pointCode != INVALIDE )
			encoderCaractereUtf16(pointCode, resultat);
	}
	
	return resultat;
}

#pragma endregion //}

#pragma endregion //}

