#pragma once

#include <string>

using namespace std;

namespace chants
{
    class Asset
    {
    private:
        string _name;
        string _message;
        int _value;
        bool _isOffensive;

    public:
        bool hasBeenUsed;
        Asset(string name, string message, int value, bool isOffensive);
        string GetName() const;
        string GetMessage() const;
        int GetValue() const;
        bool isOffensive() const;

        // Static factory methods for Harry Potter items // ADDED THIS
        static Asset CreateElderWand();       // ADDED THIS
        static Asset CreateInvisibilityCloak(); // ADDED THIS
        static Asset CreateMaraudersMap();   // ADDED THIS
        static Asset CreateTimeTurner();     // ADDED THIS
    };
}
