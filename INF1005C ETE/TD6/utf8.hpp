////////////////////////////////////////////////////////////////////////////////
/// \file   utf8.hpp
/// \author Charles Hosson
///
/// Déclaration des fonctions pour encoder et décoder l'UTF-8.
////////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <string>


using namespace std;

#pragma endregion //}


#pragma region "Déclarations" //{

#pragma region "Fonctions" //{

int calculerNbOctetsEncodageUtf8 ( uint32_t );

uint8_t calculerPrefixePremierOctetUtf8 ( int );

uint32_t calculerPointDeCodeUtf8 ( const uint8_t*, int& );

void encoderCaractereUtf8 ( uint32_t, string& );

string convertirStringVersUtf8 ( const u16string& );

#pragma endregion //}

#pragma endregion //}

