#include "Node.hpp"

namespace chants
{
    Node::Node(int id, const std::string &name) : _id(id), _name(name) {}

    int Node::GetId() const
    {
        return _id;
    }

    void Node::SetId(int id)
    {
        _id = id;
    }

    std::string Node::GetName() const
    {
        return _name;
    }

    void Node::AddConnection(Node *conn)
    {
        _connections.push_back(conn);
    }

    std::vector<Node *> Node::GetConnections() const
    {
        return _connections;
    }

    Node *Node::GetAConnection(int connId) const
    {
        for (Node *conn : _connections)
        {
            if (conn->GetId() == connId)
            {
                return conn;
            }
        }
        return nullptr;
    }

    void Node::AddAsset(Asset *asset)
    {
        _assets.push_back(asset);
    }

    void Node::RemoveAsset(const std::string &assetName)
    {
        auto it = std::remove_if(_assets.begin(), _assets.end(),
                                 [&assetName](Asset *asset) { return asset->GetName() == assetName; });
        if (it != _assets.end())
        {
            _assets.erase(it, _assets.end());
        }
    }

    std::vector<Asset *> Node::GetAssets() const
    {
        return _assets;
    }

    Asset* Node::GetAssetByName(const std::string &name)
    {
        for (Asset *asset : _assets)
        {
            if (asset->GetName() == name)
                return asset;
        }
        return nullptr;
    }

    void Node::AddMonster(Monster *monster)
    {
        _monsters.push_back(monster);
    }

    void Node::RemoveMonster(const std::string &monsterName)
    {
        auto it = std::remove_if(_monsters.begin(), _monsters.end(),
                                 [&monsterName](Monster *monster) { return monster->GetName() == monsterName; });
        if (it != _monsters.end())
        {
            _monsters.erase(it, _monsters.end());
        }
    }

    std::vector<Monster *> Node::GetMonsters() const
    {
        return _monsters;
    }

    Monster* Node::GetMonsterByName(const std::string &name)
    {
        for (Monster *monster : _monsters)
        {
            if (monster->GetName() == name)
                return monster;
        }
        return nullptr;
    }

    bool Node::operator==(const Node &rhs) const
    {
        return _id == rhs._id;
    }
}
