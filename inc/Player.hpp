#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Asset.hpp"

using namespace std;

namespace chants {

    class Player {
    private:
        string name;
        int health; // set health as 100 by default 
        int strength;
        vector<Asset*> inventory; // ADDED THIS: Inventory of assets/items
    public:
        Player(string name, int health, int strength) : name(name), health(health), strength(strength) {}
        
        string GetName() const { return name; }
        int GetHealth() const { return health; }
        void SetHealth(int newHealth) { health = newHealth; }
        int GetStrength() const { return strength; }

        void AddAsset(Asset* asset) { inventory.push_back(asset); } // ADDED THIS: Add item to inventory
        void RemoveAsset(string itemName); // ADDED THIS: Remove item from inventory
        void DisplayInventory() const; // ADDED THIS: Display inventory

        int Fight() const { return strength; }
    };
// add or subtract using negative or positive integer value to starting health according to asset picked up 
//declared here, implemented in .cpp
}

#endif
