#include <Asset.hpp>

namespace chants
{
    Asset::Asset(string name, string message, int value, bool isOffensive)
    {
        _name = name;
        _message = message;
        _value = value;
        _isOffensive = isOffensive;
        hasBeenUsed = false;
    }

    string Asset::GetName() const { return _name; }
    string Asset::GetMessage() const { return _message; }
    int Asset::GetValue() const { return _value; }
    bool Asset::isOffensive() const { return _isOffensive; }

    Asset Asset::CreateElderWand()
    {
        return Asset("Elder Wand", "A wand of immense power.", 50, true); // ADDED THIS
    }

    Asset Asset::CreateInvisibilityCloak()
    {
        return Asset("Cloak of Invisibility", "Makes you invisible to enemies.", 40, false); // ADDED THIS
    }

    Asset Asset::CreateMaraudersMap()
    {
        return Asset("Marauder's Map", "A map showing all secret passages in Hogwarts.", 30, false); // ADDED THIS
    }

    Asset Asset::CreateTimeTurner()
    {
        return Asset("Time Turner", "Allows you to rewind time in the game.", 60, false); // ADDED THIS
    }
}
