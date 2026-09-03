#include <iostream>
#include <Node.hpp>
#include <Asset.hpp>
#include <Player.hpp>
#include <Monster.hpp>
#include <AdventureGameMap.hpp>

using namespace std;
using namespace chants;

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort, Player &player)  // ADDED: Player reference
{
    cout << "\033[2J\033[1;1H"; // clear screen

    // Output contents of this node
    cout << "Location: " << viewPort.GetName() + "\n\n";
    cout << viewPort.Description << endl
         << "There are paths here ..." << endl;
    for (Node *node : viewPort.GetConnections())
    {
        cout << node->GetId() << " " << node->GetName() << endl;
    }

    // Show all assets 
    for (Asset *asset : viewPort.GetAssets())
    {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetMessage() << " " << asset->GetValue() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters())
    {
        cout << "Monster at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
    }

    // Display player's inventory
    cout << "\nYour inventory: ";
    player.DisplayInventory(); // ADDED THIS: Call DisplayInventory() on player
    cout << "\n";
}

int FindNode(string loc, vector<Node> *gameMap)
{
    int intLoc = -1;
    if (isNumber(loc))
    {
        intLoc = stoi(loc);
    }
    for (Node node : *gameMap)
    {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(Player &player, Monster &monster) // ADDED THIS 
{
    int playerAttack = player.Fight();
    int monsterAttack = monster.Fight();

    while (player.GetHealth() > 0 && monster.GetHealth() > 0)
    {
        // Use SetHealth to modify health
        player.SetHealth(player.GetHealth() - monsterAttack);
        monster.SetHealth(monster.GetHealth() - playerAttack);

        if (player.GetHealth() <= 0)
        {
            cout << "You were defeated by " << monster.GetName() << "!\n";
            return 0;
        }
        else if (monster.GetHealth() <= 0)
        {
            cout << "You defeated " << monster.GetName() << "!\n";
            return 1;
        }
    }
    return -1;
}

int main()
{
    Player player("Harry Potter", 100, 10); // CHANGED THIS: Player with a Harry Potter name and attributes
    vector<Node> gameMap;

    // Create Harry Potter-themed nodes
    Node hogwarts(0, "Hogwarts");
    hogwarts.Description = "You are at Hogwarts, the famous and secret school of Wizards.\n";

    Node diagon(1, "Diagon Alley");
    diagon.Description = "You are in Diagon Alley, grab a drink and shop wizard stuff.\n";

    Node forbiddenForest(2, "Forbidden Forest");
    forbiddenForest.Description = "You are in the Forbidden Forest, off limits to students and full of monsters.\n";

    Node hagridHut(3, "Hagrid's Hut");
    hagridHut.Description = "You are at Hagrid's Hut, a welcoming home.\n";

    Node greatHall(4, "Great Hall");
    greatHall.Description = "You are in the Great Hall, grab some magical food.\n";

    // Add connections
    hogwarts.AddConnection(&diagon);
    hogwarts.AddConnection(&forbiddenForest);
    diagon.AddConnection(&hogwarts);
    diagon.AddConnection(&hagridHut);
    forbiddenForest.AddConnection(&hogwarts);
    forbiddenForest.AddConnection(&greatHall);
    hagridHut.AddConnection(&diagon);
    hagridHut.AddConnection(&forbiddenForest);
    greatHall.AddConnection(&forbiddenForest);

    gameMap.push_back(hogwarts);
    gameMap.push_back(diagon);
    gameMap.push_back(forbiddenForest);
    gameMap.push_back(hagridHut);
    gameMap.push_back(greatHall);

    // Wizard items
    Asset wand("Wand", "A wand used to cast spells. It's powerful but needs to be handled carefully.", 200, true);
    Asset broom("Broomstick", "A broomstick for flying. It is essential for Quidditch and quick travel.", 150, true);
    Asset invisibilityCloak("Invisibility Cloak", "This cloak makes you invisible. Perfect for sneaky moves.", 300, true);
    Asset potions("Potion", "A healing potion that restores health.", 50, false);

    // Randomly add assets to nodes
    srand(time(nullptr)); // seed the random number generator
    int randNode = rand() % gameMap.size();
    gameMap[randNode].AddAsset(&wand);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddAsset(&broom);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddAsset(&invisibilityCloak);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddAsset(&potions);

    // Harry Potter monsters
    Monster dementor("Dementor", 400, 25);
    Monster basilisk("Basilisk", 1000, 50);
    Monster giantSpider("Giant Spider", 600, 35);
    Monster thestral("Thestral", 800, 40);
    Monster werewolf("Werewolf", 500, 30);

    randNode = rand() % gameMap.size();
    gameMap[randNode].AddMonster(&dementor);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddMonster(&basilisk);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddMonster(&giantSpider);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddMonster(&thestral);
    randNode = rand() % gameMap.size();
    gameMap[randNode].AddMonster(&werewolf);

    int nodePointer = 0; // start at Hogwarts
    string input;

    // Game loop
    while (true)
    {
        AtNode(gameMap[nodePointer], player); // CHANGED THIS: Pass player to AtNode function
        cout << "\nEnter action (take <item name>, drop <item name>, attack <monster>, move <number>, or 'exit' all must be full name): ";
        getline(cin, input);
        
        // Debugging the input
        cout << "You entered: " << input << endl;

        if (input == "exit")
        {
            cout << "Exiting game...\n";
            break; // Exit if 'exit' command is typed
        }
        else if (input.find("take") == 0)
        {
            string itemName = input.substr(5); // Get the name after 'take '
            if (itemName.empty()) // Check if the item name is provided
            {
                cout << "You need to specify an item to take.\n";
            }
            else
            {
                cout << "Attempting to take: " << itemName << endl;
                Asset *asset = gameMap[nodePointer].GetAssetByName(itemName);
                if (asset)
                {
                    player.AddAsset(asset); // Add to player's inventory
                    gameMap[nodePointer].RemoveAsset(asset->GetName()); // Remove from node using asset name
                    cout << "You picked up: " << asset->GetName() << endl;
                }
                else
                {
                    cout << "No such item here to take.\n";
                }
            }
        }
        else if (input.find("drop") == 0)
        {
            string itemName = input.substr(5); // Get the name after 'drop '
            if (itemName.empty()) // Check if the item name is provided
            {
                cout << "You need to specify an item to drop.\n";
            }
            else
            {
                cout << "Attempting to drop: " << itemName << endl;
                player.RemoveAsset(itemName); // Remove the asset from player's inventory
                gameMap[nodePointer].AddAsset(new Asset(itemName, "Dropped item", 0, false)); // Add new Asset (or adapt as needed)
                cout << "You dropped: " << itemName << endl;
            }
        }
        else if (input.find("attack") == 0)
        {
            string monsterName = input.substr(7); // Get the name after 'attack '
            if (monsterName.empty()) // Check if the monster name is provided
            {
                cout << "You need to specify a monster to attack.\n";
            }
            else
            {
                cout << "Attempting to attack: " << monsterName << endl;
                Monster *monster = gameMap[nodePointer].GetMonsterByName(monsterName);
                if (monster)
                {
                    int battleResult = Battle(player, *monster); // CHANGED THIS: Call Battle function
                    if (battleResult == 0)
                    {
                        break; // Player lost, exit the game
                    }
                    else if (battleResult == 1)
                    {
                        cout << "You defeated the " << monsterName << "!\n";
                    }
                }
                else
                {
                    cout << "No such monster here to attack.\n";
                }
            }
        }
        else if (input.find("move") == 0)
        {
            string nodeNumStr = input.substr(5);
            if (isNumber(nodeNumStr))
            {
                int nodeNum = stoi(nodeNumStr);
                if (nodeNum >= 0 && nodeNum < gameMap.size())
                {
                    nodePointer = nodeNum; // Move to the new node
                    cout << "Moved to: " << gameMap[nodePointer].GetName() << endl;
                }
                else
                {
                    cout << "Invalid location.\n";
                }
            }
            else
            {
                cout << "Invalid move command. Please enter a valid node number.\n";
            }
        }
        else
        {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}
