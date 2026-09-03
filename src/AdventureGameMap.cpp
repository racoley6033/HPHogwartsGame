#include "AdventureGameMap.hpp"
#include <iostream> // ADDED THIS for cout and endl


namespace chants
{
    void AdventureGameMap::buildMapNodes()
    {
        // Implement a similar way to initialize nodes as in game.cpp if needed
    }

    void AdventureGameMap::PrintMap()
    {
        for (Node &node : locations)
        {
            cout << node.GetName() << endl;
        }
    }

    void AdventureGameMap::AddNode(Node node)
    {
        locations.push_back(node);
    }

    Node* AdventureGameMap::GetNode(int nodeId)
    {
        for (Node &node : locations)
        {
            if (node.GetId() == nodeId)
                return &node;
        }
        return nullptr;
    }
}
