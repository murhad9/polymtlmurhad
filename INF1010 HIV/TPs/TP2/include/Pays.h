#ifndef PAYS_H
#define PAYS_H

#include <string>
#include "typesafe_enum.h"

enum class Pays
{

    Bresil = 0,
    Canada,
    Chine,
    EtatsUnis,
    France,
    Japon,
    RoyaumeUni,
    Russie,
    Mexique,
    first_ = Bresil,
    last_ = Mexique
};

#endif // PAYS_H
