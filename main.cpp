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
int getPlayerDamage(int fightType) {
    if (fightType == 1) return 5;
    else if (fightType == 2) return 3;
    else if (fightType == 3) return 2;
    return 0;
}

// Function to get enemy attack (uses multidimensional array, pass by reference for damage and type)
void getEnemyAttack(int random, int &damage, string &type) {
    for (int i = 0; i < 4; i++) {
        if (random >= attackThresholds[i][0]) {
            damage = attackThresholds[i][1];
            type = attackTypes[i];
            return;
        }
    }
    damage = 2;
    type = "light";
}
void recursiveBattleRound(Player &player, int &enehp, string inventory[]) {
    int star;
    cout << "Confirm your attack\n";
    cout << "How will you attack\n";
    cout << "1 With strength\n";
    cout << "2 With intelligence\n";
    cout << "3 With dexterity\n";
    cout << "4 with Sword of light can only be used once\n";
    cin >> star;
    int random = (rand() % 100) + 1;
    int damage;
    string type;
    getEnemyAttack(random, damage, type);
    if (star == 2 || star == 3) {
        if (damage == 2) type = "speical";
    }
    switch (star) {
        case 1:
            cout << "You have attacked enemy for 5 damage\n";
            enehp = enehp - 5;
            if (random >= 75) {
                cout << "You have been attacked\n";
                cout << "Enemy has used heavy attack\n";
                player.health = player.health - 5;
            } else if (random >= 45) {
                cout << "You have been attacked\n";
                cout << "Enemy has used normal attack\n";
                player.health = player.health - 3;
            } else if (random >= 92) {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 10;
            } else {
                cout << "You have been attacked\n";
                cout << "Enemy has used light attack\n";
                player.health = player.health - 2;
            }
            break;
        case 2:
            cout << "You have attacked enemy for 3 damage\n";
            enehp = enehp - 5;
            if (random >= 75) {
                cout << "You have been attacked\n";
                cout << "Enemy has used heavy attack\n";
                player.health = player.health - 5;
            } else if (random >= 45) {
                cout << "You have been attacked\n";
                cout << "Enemy has used normal attack\n";
                player.health = player.health - 3;
            } else if (random >= 92) {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 10;
            } else {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 2;
            }
            break;
        case 3:
            cout << "You have attacked enemy for 2 damage\n";
            enehp = enehp - 5;
            if (random >= 75) {
                cout << "You have been attacked\n";
                cout << "Enemy has used heavy attack\n";
                player.health = player.health - 5;
            } else if (random >= 45) {
                cout << "You have been attacked\n";
                cout << "Enemy has used normal attack\n";
                player.health = player.health - 3;
            } else if (random >= 92) {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 10;
            } else {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 2;
            }
            break;
        case 4:
            cout << "You have used the Sword of Light \n";
            enehp = enehp - 10;
            if (random >= 75) {
                cout << "You have been attacked\n";
                cout << "Enemy has used heavy attack\n";
                player.health = player.health - 5;
            } else if (random >= 45) {
                cout << "You have been attacked\n";
                cout << "Enemy has used normal attack\n";
                player.health = player.health - 3;
            } else if (random >= 92) {
                cout << "You have been attacked\n";
                cout << "Enemy has used speical attack\n";
                player.health = player.health - 10;
            } else if (random > 10) {
                cout << "You have been attacked\n";
                cout << "Enemy has used light attack\n";
                player.health = player.health - 2;
            } else {
                cout << "You have dodged\n";
            }
            break;
    }
    if (enehp >= 0 && player.health >= 0) {
        recursiveBattleRound(player, enehp, inventory);
    }
}