#pragma once

#include <vector>
#include <string>
#include <Asset.hpp>
#include <Monster.hpp>

namespace chants
{
    class Node
    {
    private:
        int _id;
        std::string _name;
        std::vector<Node *> _connections;
        std::vector<Asset *> _assets;
        std::vector<Monster *> _monsters;

    public:
        std::string Description;

        Node(int id, const std::string &name);
        int GetId() const;
        void SetId(int id);
        std::string GetName() const;
        void AddConnection(Node *conn);
        std::vector<Node *> GetConnections() const;
        Node *GetAConnection(int connId) const;

        void AddAsset(Asset *asset);
        void RemoveAsset(const std::string &assetName);
        std::vector<Asset *> GetAssets() const;
        Asset* GetAssetByName(const std::string &name); // ADDED THIS

        void AddMonster(Monster *monster);
        void RemoveMonster(const std::string &monsterName);
        std::vector<Monster *> GetMonsters() const;
        Monster* GetMonsterByName(const std::string &name); // ADDED THIS

        bool operator==(const Node &rhs) const;
    };
}
