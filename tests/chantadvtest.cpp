#include <cassert>
#include <Player.hpp>
#include <Monster.hpp>
#include <Node.hpp>

void testAssetAdding() 
{
    Player player("Hero", 100, 5);
    Asset hammer("Hammer", "A heavy hammer", 150, true);
    player.AddAsset(hammer);
    assert(player.GetTotalAssetValue() == 150);
}

void testCombat() 
{
    Player player("Hero", 100, 5);
    Monster goblin("Goblin", 80, 3);
    int result = Battle(player, goblin);
    assert(result == 1 || result == 0);
}

int main() 
{
    testAssetAdding();
    testCombat();
    cout << "All tests passed!\n";
    return 0;
}
