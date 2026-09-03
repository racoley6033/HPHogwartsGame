#pragma once

#include <string>
#include <Combatant.hpp>

using namespace std;

namespace chants
{
    class Monster : public Combatant
    {
    public:
        Monster(string name, int health, int fightCoefficient);
        static Monster CreateDementor(); // Factory methods for the monsters // ADDED THIS
        static Monster CreateBasilisk(); // ADDED THIS
        static Monster CreateAcromantula(); // ADDED THIS
    };
}
