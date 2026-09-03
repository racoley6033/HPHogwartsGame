#include "Player.hpp"
#include <iostream>

using namespace std;

namespace chants {

    void Player::RemoveAsset(string itemName) {  // ADDED THIS: Remove item from inventory
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if ((*it)->GetName() == itemName) {
                inventory.erase(it);
                cout << "You dropped: " << itemName << endl;
                return;
            }
        }
        cout << "Item not found in inventory.\n";
    }

    void Player::DisplayInventory() const {  // ADDED THIS: Display player's inventory
        if (inventory.empty()) {
            cout << "Your inventory is empty.";
        } else {
            for (const auto &item : inventory) {
                cout << item->GetName() << " (Value: " << item->GetValue() << ") ";
            }
        }
    }
}
// implement the change health here 