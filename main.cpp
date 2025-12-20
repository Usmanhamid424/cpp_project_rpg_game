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
void saveGame(const Player &player, string inventory[]) {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        file << player.name << endl;
        file << player.health << endl;
        file << player.strength << endl;
        file << player.intelligence << endl;
        file << player.dexterity << endl;
        file << player.rep << endl;
        file << player.money << endl;
        for (int i = 0; i < 10; i++) {
            file << inventory[i] << endl;
        }
        file.close();
        cout << "Game saved!\n";
    } else {
        cout << "Unable to save game.\n";
    }
}
void loadGame(Player &player, string inventory[]) {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        getline(file, player.name);
        file >> player.health;
        file >> player.strength;
        file >> player.intelligence;
        file >> player.dexterity;
        file >> player.rep;
        file >> player.money;
        for (int i = 0; i < 10; i++) {
            getline(file, inventory[i]);
        }
        file.close();
        cout << "Game loaded!\n";
    } else {
        cout << "No save file found.\n";
    }
}
int main() {
    int number;
    Player player;
    string inventory[10];
    int con;
    player.money = 50;
    player.rep = 10;
    int quest;
    int enehp = 10;
    int health = 20;
    int fight;
    int job;
    player.strength = 5;
    player.intelligence = 5;
    player.dexterity = 5;
    cout << "Welcome to the adventure game\n";
    cout << "Once the world of Elarion thrived in harmony its kingdoms united under peace ";
    cout << "Malakar the Shadowbinder rose, shattering lands with fire and shadow. ";
    cout << "Hope faded, cities crumbled, and darkness claimed the skies. ";
    cout << "Prophecy whispered of a chosen hero, destined to rise. ";
    cout << "From the ashes, a light would be born to end the darkness.\n";
    cout << "You are a brave adventurer seekings to find your true purpose.\n";
    cout << "Your name is: \n";
    cin >> player.name;
    cout << "Chose your upbringing\n";
    cout << "1. Noble Raised in luxury\n";
    cout << "2. Orphan Grew up on the streets\n";
    cout << "3. Farmer Hard-working and tough from labor in the fields\n";
    int backstory;
    cin >> backstory;
    switch (backstory) {
        case 1:
            cout << "You are a smart noble\n";
            increaseStat(&player.intelligence, 1);
            player.money += 30;
            break;
        case 2:
            cout << "You are a fast orphan\n";
            increaseStat(&player.dexterity, 1);
            break;
        case 3:
            cout << "You are a strong farmer\n";
            increaseStat(&player.strength, 1);
            break;
        default:
            cout << "Invalid choice, you are a peasant\n";
            break;
    }
    cout << "Chose your race\n";
    cout << "1. Human Versatile and ambitious, humans thrive by adapting to any challenge in Elarion\n";
    cout << "2. Elf Children of the ancient forests, elves carry centuries of wisdom but are wary of outsiders\n";
    cout << "3. Dwarf Forged in stone and fire, dwarves are stubborn warriors who value strength and honor above all\n";
    int race;
    cin >> race;
    switch (race) {
        case 1:
            cout << "You are a smart human\n";
            increaseStat(&player.intelligence, 1);
            break;
        case 2:
            cout << "You are a fast elf\n";
            increaseStat(&player.dexterity, 1);
            break;
        case 3:
            cout << "You are a strong dwarf\n";
            increaseStat(&player.strength, 1);
            break;
        default:
            cout << "Invalid choice, you are a peasant\n";
            break;
    }
    cout << "Choose your profession:\n";
    cout << "1. Warrior\n";
    cout << "2. Mage\n";
    cout << "3. Rogue\n";
    cin >> job;
    switch (job) {
        case 1:
            cout << "You are a strong warrior\n";
            increaseStat(&player.strength, 2);
            break;
        case 2:
            cout << "You are a wise mage\n";
            increaseStat(&player.intelligence, 2);
            break;
        case 3:
            cout << "You are a stealthy rogue\n";
            increaseStat(&player.dexterity, 2);
            break;
        default:
            cout << "Invalid choice, you are a peasant\n";
            break;
    }
}