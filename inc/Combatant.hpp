#pragma once
#include <string>
using namespace std;

namespace chants
{
    class Combatant
    {
    protected:
        string _name;
        int _health;
        int _fightCoefficient;

    public:
        Combatant(string name, int health, int coefficient);
        
        int Fight() const;  // Fighting power based on coefficient
        string GetName();
        int GetHealth();
        void SetHealth(int health);
        bool IsDefeated();

        // Static methods for combat calculation
        static int CalculateDamage(const Combatant& attacker, const Combatant& defender);
        static void ExecuteCombat(Combatant& attacker, Combatant& defender);  // ADDED THIS
    };
}
