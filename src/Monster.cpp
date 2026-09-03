#include <Monster.hpp>

namespace chants
{
    Monster::Monster(string name, int health, int fightCoefficient) 
        : Combatant(name, health, fightCoefficient) {}

    Monster Monster::CreateDementor()
    {
        return Monster("Dementor", 100, 20); // ADDED THIS
    }

    Monster Monster::CreateBasilisk()
    {
        return Monster("Basilisk", 200, 30); // ADDED THIS
    }

    Monster Monster::CreateAcromantula()
    {
        return Monster("Acromantula", 120, 25); // ADDED THIS
    }
}
