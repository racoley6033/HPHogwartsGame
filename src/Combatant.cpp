#include "Combatant.hpp"
#include <iostream>
using namespace std;

namespace chants
{
    Combatant::Combatant(string name, int health, int coefficient)
        : _name(name), _health(health), _fightCoefficient(coefficient) {}

    int Combatant::Fight() const
    {
        return _fightCoefficient;
    }

    string Combatant::GetName()
    {
        return _name;
    }

    int Combatant::GetHealth()
    {
        return _health;
    }

    void Combatant::SetHealth(int health)
    {
        _health = health;
    }

    bool Combatant::IsDefeated()
    {
        return _health <= 0;
    }

    int Combatant::CalculateDamage(const Combatant& attacker, const Combatant& defender)
    {
        return std::max(1, attacker.Fight() - (defender.Fight() / 2)); // Damage formula
    }

    void Combatant::ExecuteCombat(Combatant& attacker, Combatant& defender)
    {
        while (!attacker.IsDefeated() && !defender.IsDefeated())
        {
            int damageToDefender = CalculateDamage(attacker, defender);
            defender.SetHealth(defender.GetHealth() - damageToDefender);
            cout << attacker.GetName() << " deals " << damageToDefender
                 << " damage to " << defender.GetName() << ".\n";

            if (defender.IsDefeated())
            {
                cout << defender.GetName() << " has been defeated!\n";
                break;
            }

            int damageToAttacker = CalculateDamage(defender, attacker);
            attacker.SetHealth(attacker.GetHealth() - damageToAttacker);
            cout << defender.GetName() << " deals " << damageToAttacker
                 << " damage to " << attacker.GetName() << ".\n";

            if (attacker.IsDefeated())
            {
                cout << attacker.GetName() << " has been defeated!\n";
            }
        }
    }
}
