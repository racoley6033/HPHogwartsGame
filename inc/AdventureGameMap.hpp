#pragma once

#include <string>
#include <Node.hpp>

using namespace std;

namespace chants
{
    class AdventureGameMap
    {
    private:
        vector<Node> locations;

        void buildMapNodes(); // Connect locations with Harry Potter themes // CHANGED THIS
    public:
        void PrintMap();
        void AddNode(Node node);
        Node* GetNode(int nodeId);
    };
}
