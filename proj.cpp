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
    cout << "Strength: " << p.strength << " | Intelligence: " << p.intelligence << endl;
    cout << " | Dexterity: " << p.dexterity << endl;
    cout << "Gold: " << p.gold << " | Reputation: " << p.reputation << endl;
    cout << "Inventory: ";
    bool empty = true;
    for (const string& item : p.inventory) {
        if (!item.empty()) { cout << item << " | "; empty = false; }
    }
    if (empty) cout << "Empty";
    cout << "\n===============\n";
}