#include <iostream>
#include <string>
using namespace std;
struct Player {
    string name;
    int health = 20, maxHealth = 20;
    int strength = 5, intelligence = 5, dexterity = 5;
    int gold = 50;
    int reputation = 10;
    string inventory[10] = {"", "", "", "", "", "", "", "", "", ""};
};
void pressEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
void displayStats(const Player& p) {
    cout << "\n=============\n";
    cout << "HERO: " << p.name << "\n";
    cout << "===============\n";
    cout << "Health: " << p.health << "/" << p.maxHealth << endl;
    cout << "Strength: " << p.strength << "|Intelligence: " << p.intelligence << endl;
    cout << "|Dexterity: " << p.dexterity << endl;
    cout << "Gold: " << p.gold << " |Reputation: " << p.reputation << endl;
    cout << "Inventory: ";
    bool empty = true;
    for (const string& item : p.inventory) {
        if (!item.empty()) { cout << item << " | "; empty = false; }
    }
    if (empty) cout << "Empty";
    cout << "\n===============\n";
}
void chooseBackstory(Player& p) {
    cout << "\nChoose your upbringing:\n";
    cout << "1. Noble (+1 Intelligence, +30 gold)\n";
    cout << "2. Orphan (+1 Dexterity)\n";
    cout << "3. Farmer (+1 Strength)\n> ";
    int c; 
    cin >> c;
    switch(c) {
        case 1: 
            p.intelligence++; 
            p.gold += 30; 
            cout << "You were raised in luxury.\n"; break;
        case 2: 
            p.dexterity++; 
            cout << "You grew up on the harsh streets.\n"; break;
        case 3: 
            p.strength++; 
            cout << "You worked the fields with iron will.\n"; break;
        default: 
            cout << "You are a simple peasant.\n"; break;
    }
}
void chooseRace(Player& p) {
    cout << "\nChoose your race:\n";
    cout << "1. Human (+1 Intelligence)\n";
    cout << "2. Elf (+1 Dexterity)\n";
    cout << "3. Dwarf (+1 Strength)\n> ";
    int c; 
    cin >> c;
    switch(c) {
        case 1: 
            p.intelligence++; 
            cout << "Human ambition burns within.\n"; break;
        case 2: 
            p.dexterity++; 
            cout << "Elven grace flows through you.\n"; break;
        case 3: 
            p.strength++; 
            cout << "Dwarven endurance is yours.\n"; break;
        default: 
            cout << "Your bloodline is unknown...\n"; break;
    }
}
void chooseClass(Player& p) {
    cout << "\nChoose your profession:\n";
    cout << "1. Warrior (+2 Strength)\n";
    cout << "2. Mage (+2 Intelligence)\n";
    cout << "3. Rogue (+2 Dexterity)\n";
    int c;
    cin >> c;
    switch(c) {
        case 1: 
            p.strength += 2; 
            cout << "You are a fearsome Warrior!\n"; break;
        case 2: 
            p.intelligence += 2; 
            cout << "You wield powerful Magic!\n"; break;
        case 3: 
            p.dexterity += 2; 
            cout << "You are a deadly Rogue!\n"; break;
        default: 
            cout << "You forge your own destiny.\n"; break;
    }
    void addItem(Player& p, const string& item, int slot) {
        if (slot < 10) {
            p.inventory[slot] = item;
        }
    }
    bool hasItem(const Player& p, int slot) {
        return slot < 10 && !p.inventory[slot].empty();
    }
    void removeItem(Player& p, int slot) {
        if (slot < 10) p.inventory[slot] = "";
    }
}