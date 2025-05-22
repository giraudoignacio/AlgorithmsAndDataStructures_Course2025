//
// Created by gvalenzuela on 3/30/25.
//

#ifndef CHRACTERVISITANT_HPP
#define CHRACTERVISITANT_HPP

#include "characters/artefactoUnico.hpp"
#include "characters/asaltante.hpp"
#include "characters/caravana.hpp"
#include "characters/enclave.hpp"
#include "characters/ghoul.hpp"
#include "characters/hermanosDeAcero.hpp"
#include "characters/mercader.hpp"
#include "characters/mercaderAgua.hpp"
#include "characters/mutantes.hpp"
#include "characters/refugiado.hpp"
#include "characters/refugio.hpp"
#include "characters/saqueador.hpp"

using VisitanteVariant = std::variant<
Refugiado,
Mercader,
MercaderAgua,
Saqueador,
HermanoAcero,
Enclave,
Mutante,
Asaltante,
Ghoul,
Caravana
>;

namespace NPC {
    enum class VisitantCategory
    {
        REFUGEE,
        BROTHER,
        ENEMY,
        MERCHANT,
        CARAVAN
    };

    struct VisitantChance
    {
        VisitantCategory type;
        double weight;
    };
};

#endif //CHRACTERVISITANT_HPP
