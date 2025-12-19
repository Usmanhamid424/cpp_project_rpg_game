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
void addItem(Player& p, const string& item, int slot) {
    if (slot < 10) p.inventory[slot] = item;
}
void strengthPath(Player& p) {
    if (p.strength >= 7) addItem(p, "Sword of Light", 0);
    pressEnter();
}
void intelligencePath(Player& p) {
    if (p.intelligence >= 7) addItem(p, "Tome of Knowledge", 1);
    pressEnter();
}
void dexterityPath(Player& p) {
    if (p.dexterity >= 7) addItem(p, "Boots of Speed", 2);
    pressEnter();
}