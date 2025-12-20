#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
struct Player {
    string name;
    int health;
    int strength;
    int intelligence;
    int dexterity;
    int rep;
    int money;
};
char gameMap[7][7] = {
    {'W', '.', '.', ' ', ' ', ' ', 'V'},
    {'.', '.', ' ', 'B', ' ', '.', '.'},
    {'.', ' ', '.', '.', '.', ' ', 'E'},
    {'Q', '.', '.', 'R', '.', '.', 'S'},
    {' ', '.', ' ', '.', ' ', '.', ' '},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'T', 'F', '.', ' ', ' '}
};
void printMap(char map[][7], int rows) {
    cout << "Game Map:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 7; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void displayStats(const Player &player) {
    cout << "You have " << player.strength << " strength\n";
    cout << "You have " << player.intelligence << " intelligence\n";
    cout << "You have " << player.dexterity << " dexterity\n";
    cout << "You have " << player.health << " health\n";
}
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
// test commit
