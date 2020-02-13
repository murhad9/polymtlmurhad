////////////////////////////////////////////////////////////////////////////////
/// \file   constantes.hpp
/// \author Charles Hosson
///
/// Les constantes des points de code spéciaux.
////////////////////////////////////////////////////////////////////////////////

#pragma once


#pragma region "Inclusions" //{

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <istream>
#include <ostream>
#include <string>


using namespace std;

#pragma endregion //}


#pragma region "Déclarations" //{

#pragma region "Constantes" //{

enum PointsDeCodeSpeciaux : uint32_t
{
	INVALIDE = 0xFFFF,
	BOM = 0xFEFF,
	MULTI_CODET_UTF16_HAUT = 0xD800,
	MULTI_CODET_UTF16_BAS = 0xDC00,
};

#pragma endregion //}

#pragma endregion //}

