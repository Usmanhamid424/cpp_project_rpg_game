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
void printInventory(string inv[], int size) {
    cout << "Inventory:\n";
    for (int i = 0; i < size; i++) {
        if (!inv[i].empty()) {
            cout << inv[i] << "\n";
        }
    }
}
void increaseStat(int *stat, int amount) {
    *stat += amount;
}
int attackThresholds[4][2] = {{92, 10}, {75, 5}, {45, 3}, {0, 2}};
string attackTypes[4] = {"speical", "heavy", "normal", "light"};
void printInventory(string inv[], int size) {
    cout << "Inventory:\n";
    for (int i = 0; i < size; i++) {
        if (!inv[i].empty()) {
            cout << inv[i] << "\n";
        }
    }
}