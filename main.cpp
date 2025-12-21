//all header files in use
// for input and output
#include <iostream>
// library for random numbers and other functions
#include <cstdlib>
// for string handling
#include <string>
// for random number generation
#include <ctime>
// for file handling
#include <fstream>
// standard namespace
#include <limits>
using namespace std;
// player structure to hold player attributes
struct Player {
    string name;
    int health;
    int strength;
    int intelligence;
    int dexterity;
    int rep;
    int money;
};
// 2d array for game map
char gameMap[7][7] = {
    {'W', '.', '.', ' ', ' ', ' ', 'V'},
    {'.', '.', ' ', 'B', ' ', '.', '.'},
    {'.', ' ', '.', '.', '.', ' ', 'E'},
    {'Q', '.', '.', 'R', '.', '.', 'S'},
    {' ', '.', ' ', '.', ' ', '.', ' '},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'T', 'F', '.', ' ', ' '}
};
// funcftion prototypes
// prints the game map
void printMap(char map[][7], int rows) {
    cout << "Game Map:\n";
    // for loop to print each row and column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 7; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
// displays player stats
void displayStats(const Player& player) {
    cout << "You have " << player.strength << " strength\n";
    cout << "You have " << player.intelligence << " intelligence\n";
    cout << "You have " << player.dexterity << " dexterity\n";
    cout << "You have " << player.health << " health\n";
}
// prints the player's inventory
void printInventory(string inv[], int size) {
    cout << "Inventory:\n";
    // for loop to print each item in inventory
    for (int i = 0; i < size; i++) {
        if (!inv[i].empty()) {
            cout << inv[i] << "\n";
        }
    }
}
// increases a player stat
void increaseStat(int* stat, int amount) {
    *stat += amount;
}
// attack thresholds for how much damage enemy does
int attackThresholds[4][2] = { {92, 10}, {75, 5}, {45, 3}, {0, 2} };
// attack types corresponding to thresholds
string attackTypes[4] = { "speical", "heavy", "normal", "light" };
// gets player damage based on fight type
int getPlayerDamage(int fightType) {
    if (fightType == 1) return 5;
    else if (fightType == 2) return 3;
    else if (fightType == 3) return 2;
    return 0;
}
// gets enemy attack based on random number
void getEnemyAttack(int random, int& damage, string& type) {
    for (int i = 0; i < 4; i++) {
        if (random >= attackThresholds[i][0]) {
            damage = attackThresholds[i][1];
            type = attackTypes[i];
            return;
        }
    }
    // default to light attack
    damage = 2;
    type = "light";
}
// recursive battle round function
void recursiveBattleRound(Player& player, int& enehp, string inventory[]) {
    int star;
    cout << "Confirm your attack\n";
    cout << "How will you attack\n";
    cout << "1 With strength\n";
    cout << "2 With intelligence\n";
    cout << "3 With dexterity\n";
    cout << "4 with Sword of light can only be used once\n";
    while (true) {
        if (cin >> star) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // generate random number for enemy attack
    int random = (rand() % 100) + 1;
    int damage;
    string type;
    // get enemy attack based on random number
    getEnemyAttack(random, damage, type);
    // adjust type for special cases
    if (star == 2 || star == 3) {
        if (damage == 2) type = "speical";
    }
    // switch case for player attack
    switch (star) {
        // case for strength attack
    case 1:
        cout << "You have attacked enemy for 5 damage\n";
        enehp = enehp - 5;
        // enemy attack
        if (random >= 75) {
            cout << "You have been attacked\n";
            cout << "Enemy has used heavy attack\n";
            // heavy attack damage
            player.health = player.health - 5;
        }
        else if (random >= 45) {
            cout << "You have been attacked\n";
            cout << "Enemy has used normal attack\n";
            // normal attack damage
            player.health = player.health - 3;
        }
        else if (random >= 92) {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // special attack damage
            player.health = player.health - 10;
        }
        else {
            cout << "You have been attacked\n";
            cout << "Enemy has used light attack\n";
            // light attack damage
            player.health = player.health - 2;
        }
        break;
        // case for intelligence attack
    case 2:
        // intelligence attack
        cout << "You have attacked enemy for 3 damage\n";
        // reduce enemy health
        enehp = enehp - 5;
        // enemy attack
        if (random >= 75) {
            cout << "You have been attacked\n";
            cout << "Enemy has used heavy attack\n";
            // heavy attack damage
            player.health = player.health - 5;
        }
        else if (random >= 45) {
            cout << "You have been attacked\n";
            cout << "Enemy has used normal attack\n";
            // normal attack damage
            player.health = player.health - 3;
        }
        else if (random >= 92) {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // special attack damage
            player.health = player.health - 10;
        }
        else {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // light attack damage
            player.health = player.health - 2;
        }
        break;
    case 3:
        // case for dexterity attack
        cout << "You have attacked enemy for 2 damage\n";
        // reduce enemy health
        enehp = enehp - 5;
        // enemy attack
        if (random >= 75) {
            cout << "You have been attacked\n";
            cout << "Enemy has used heavy attack\n";
            // heavy attack damage
            player.health = player.health - 5;
        }
        else if (random >= 45) {
            cout << "You have been attacked\n";
            cout << "Enemy has used normal attack\n";
            // normal attack damage
            player.health = player.health - 3;
        }
        else if (random >= 92) {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // special attack damage
            player.health = player.health - 10;
        }
        else {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // light attack damage
            player.health = player.health - 2;
        }
        break;
    case 4:
        // case for sword of light attack
        cout << "You have used the Sword of Light \n";
        // reduce enemy health
        enehp = enehp - 10;
        // enemy attack
        if (random >= 75) {
            cout << "You have been attacked\n";
            cout << "Enemy has used heavy attack\n";
            // heavy attack damage
            player.health = player.health - 5;
        }
        else if (random >= 45) {
            cout << "You have been attacked\n";
            cout << "Enemy has used normal attack\n";
            // normal attack damage
            player.health = player.health - 3;
        }
        else if (random >= 92) {
            cout << "You have been attacked\n";
            cout << "Enemy has used speical attack\n";
            // special attack damage
            player.health = player.health - 10;
        }
        else if (random > 10) {
            cout << "You have been attacked\n";
            cout << "Enemy has used light attack\n";
            // light attack damage
            player.health = player.health - 2;
        }
        else {
            // dodge attack
            cout << "You have dodged\n";
        }
        break;
    }
    // recursion for both player and enemy hp being greater than 0
    if (enehp >= 0 && player.health >= 0) {
        recursiveBattleRound(player, enehp, inventory);
    }
}
// battle function
int Battle(Player& player, int& enehp, int& strength, int& intelligence, int& dexterity, string inventory[]) {
    int fight;
    int star;
    // random number generator
    srand(time(0));
    // generates number between 1 and 100
    int random = (rand() % 100) + 1;
    cout << "You have gone to train\n";
    cout << "You s0ee an enemy\n";
    cout << "You face an enemy\n";
    cout << "How will you fight?\n";
    cout << "Enemy has 10 health\n";
    cout << "Enemy does 2 damage per hit\n";
    cout << "How will you fight?\n";
    cout << "1 With strength\n";
    cout << "2 With intelligence\n";
    cout << "3 With dExterity\n";
    // taking user input for attack
    while (true) {
        if (cin >> fight) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // checking if player stat is greater than 5
    if ((fight == 1 && strength > 5) || (fight == 2 && intelligence > 5) || (fight == 3 && dexterity > 5)) {
        cout << "You have attacked enemy for 5 damage\n";
        // reducing enemy health
        enehp = enehp - 5;
        cout << "You have been attacked for 2 damage\n";
        // enemy attack
        player.health = player.health - 2;
        // taking user input for next attack
        cout << "Your next attack\n";
        cout << "How will you attack\n";
        cout << "1 With strength\n";
        cout << "2 With intelligence\n";
        cout << "3 With dexterity\n";
        cout << "4 with Sword of light can only be used once\n";
        // calling recursive battle function
        recursiveBattleRound(player, enehp, inventory);
        // checking win or loss conditions
        if (player.health <= 0) {
            cout << "You have lost\n";
        }
        else if (enehp <= 0) {
            cout << "You have won\n";
            cout << "You have leveled up\n";
            // increasing player stats and restorng health
            if (player.health <= 20) {
                player.health = 20;
                cout << "Your health is now " << player.health << "\n";
            }
            increaseStat(&player.strength, 1);
            increaseStat(&player.intelligence, 1);
            increaseStat(&player.dexterity, 1);
        }
        else {
            cout << "Error\n";
        }
        cout << "You have defeated the enemy \n";
        cout << "You have obtained a Health Potion\n";
        // adding health potion to inventory
        inventory[3] = "Health Potion";
        cout << "You have gained 10 Gold\n";
    }
    return 0;
}
// boss fight function
void fightBoss(Player& player, string inventory[]) {
    int bosshp = 20;
    cout << "You face Malakar the Shadowbinder!\n";
    // checking rep to go into multiple endings
    if (player.rep < 10) {
        cout << "Malakar has heard of your evil deeds\n";
        cout << "He asks if you wish to join him\n";
        cout << "What will you do?\n";
        cout << "1 Join him\n";
        cout << "2 Fight him\n";
        cout << "3 kill him and take his place\n";
        // taking user input for choice
        int yo;
        while (true) {
            if (cin >> yo) {
                break;
            }
            else {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        switch (yo) {
        case 1:
            // joining Malakar ending
            cout << "You have joined Malakar\n";
            cout << "You invade the human plains with him\n";
            cout << "You kill humans as you see them\n";
            cout << "They fear you\n";
            cout << "You are one of the best in the world but are only the right hand man\n";
            exit(0);
        case 2:
            // fighting Malakar ending
            cout << "You have chosen to fight Malakar\n";
            cout << "How will you attack him?\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            // taking user input for attack
            int attack;
            while (true) {
                if (cin >> attack) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            // checking player stats and inventory for attack
            if (attack == 1 && player.strength >= 7 || inventory[0] == "Sword") {
                cout << "You have attacked enemy for 5 damage\n";
                bosshp = 15;
                cout << "You have been attacked for 3 damage\n";
                // player health decrease
                player.health = player.health - 3;
                cout << "Your next attack\n";
                cout << "How will you attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 with Sword of light can only be used once \n";
                cout << "5 heal with health potion can only be used once \n";
                // taking user input for next attack
                int start;
                while (true) {
                    if (cin >> start) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                // battle loop until boss or player health reaches 0
                do {
                    cout << "Confirm your attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Tome of knowledge can only be used once";
                    cout << "5 use health potion can only be used once \n";
                    // taking user input for attack
                    while (true) {
                        if (cin >> start) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    switch (start) {
                    case 1:
                        // strength attack
                        cout << "You have attacked enemy for 5 damage\n";
                        // reducing boss health
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        // reducing player health
                        player.health = player.health - 2;
                        break;
                    case 2:
                        // intelligence attack
                        cout << "You have attacked enemy for 3 damage\n";
                        // reducing boss health
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        // reducing player health
                        player.health = player.health - 2;
                        break;
                    case 3:
                        // dexterity attack
                        cout << "You have attacked enemy for 2 damage\n";
                        // reducing boss health
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        // reducing player health
                        player.health = player.health - 2;
                        break;
                    case 4:
                        // sword of light attack
                        cout << "You have used the Sword of Light\n";
                        // reducing boss health
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        // reducing player health
                        player.health = player.health - 2;
                        break;
                    case 5:
                        cout << "You have used the Health Potion\n";
                        // increasing player health by using potion
                        player.health = player.health + 5;
                        // removing potion from inventory
                        inventory[3] = "";
                        break;
                    }
                    // loop condition
                } while (bosshp >= 0 && player.health != 0);
                cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                cout << "People sing your praises\nYou are hailed as a hero\n";
                cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                exit(0);
                // intelligence attack path
            }
            else if (attack == 2 && player.intelligence >= 7 || inventory[1] == "Tome") {
                cout << "You have attacked enemy for 5 damage\n";
                // setting boss health
                bosshp = 15;
                cout << "You have been attacked for 2 damage\n";
                player.health = player.health - 2;
                cout << "Your next attack\n";
                cout << "How will you attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 with Tome of knowledge can only be used once";
                int start1;
                while (true) {
                    if (cin >> start1) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                do {
                    cout << "Confirm your attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Tome of knowledge can only be used once";
                    cout << "5 use health potion can only be used once \n";
                    while (true) {
                        if (cin >> start1) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    switch (start1) {
                    case 1:
                        // strength attack
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        // intelligence attack
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        // dexterity attack
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        // tome of knowledge attack
                        cout << "You have used the tome of knowledge\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        inventory[1] = "";
                        break;
                    case 5:
                        // health potion use
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        // removing potion from inventory
                        inventory[3] = "";
                        break;
                    }
                    // loop condition
                } while (bosshp >= 0 && player.health != 0);
                cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                cout << "People sing your praises\nYou are hailed as a hero\n";
                cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                exit(0);
                // dexterity attack path
            }
            else if (attack == 3 && player.dexterity >= 7 || inventory[2] == "Boots") {
                cout << "You have attacked enemy for 5 damage\n";
                bosshp = 15;
                cout << "You have been attacked for 2 damage\n";
                // reducing player health
                player.health = player.health - 2;
                cout << "Your next attack\n";
                cout << "How will you attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 with Sword of light can only be used once";
                int start2;
                while (true) {
                    if (cin >> start2) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                do {
                    cout << "Confirm your attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Tome of knowledge can only be used once";
                    cout << "5 use health potion can only be used once \n";
                    while (true) {
                        if (cin >> start2) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    switch (start2) {
                    case 1:
                        // strength attack
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        // intelligence attack
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        // dexterity attack
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        // boots of speed attack
                        cout << "You have used the boots\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        // removing boots from inventory
                        inventory[2] = "";
                        break;
                    case 5:
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        // removing potion from inventory
                        inventory[3] = "";
                        break;
                    }
                    // loop condition
                } while (bosshp >= 0 && player.health != 0);
                cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                cout << "People sing your praises\nYou are hailed as a hero\n";
                cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                exit(0);
            }
            else {
                // lose game over
                cout << "You are not strong enough...\nGame Over\n";
                exit(0);
            }
            break;
        case 3:
            // kill Malakar and take his place ending
            cout << "You have chosen to kill Malakar and take his place\n";
            cout << "How will you attack him?\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            while (true) {
                if (cin >> attack) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            // checking player stats and inventory for attack
            if (attack == 1 && player.strength >= 7 || inventory[0] == "Sword") {
                cout << "You have attacked enemy for 5 damage\n";
                bosshp = 15;
                cout << "You have been attacked for 3 damage\n";
                // reducing player health
                player.health = player.health - 3;
                cout << "Your next attack\n";
                cout << "How will you attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 with Sword of light can only be used once \n";
                cout << "5 heal with health potion can only be used once \n";
                int start;
                while (true) {
                    if (cin >> start) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                do {
                    cout << "Confirm your attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Tome of knowledge can only be used once";
                    cout << "5 use health potion can only be used once \n";
                    while (true) {
                        if (cin >> start) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    switch (start) {
                    case 1:
                        // strength attack
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        // intelligence attack
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        // dexterity attack
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        // sword of light attack
                        cout << "You have used the Sword of Light\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 5:
                        // health potion use
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        inventory[3] = "";
                        break;
                    }
                    // loop condition
                } while (bosshp >= 0 && player.health != 0);
                cout << "You are now the new evil overlord of Elarion\n";
                cout << "You are feared all across the world\n";
                cout << "You are the worlds new king\n";
                exit(0);
            }
            else {
                // lose game over
                cout << "Invalid choice, Malakar has killed you\n";
                exit(0);
            }
            break;
        default:
            cout << "Invalid choice, Malakar has killed you\n";
            exit(0);
        }
        // good reputation path
    }
    else {
        cout << "How will you attack him?\n";
        cout << "1 With strength\n";
        cout << "2 With intelligence\n";
        cout << "3 With dexterity\n";
        int attack1;
        while (true) {
            if (cin >> attack1) {
                break;
            }
            else {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        // checking player stats and inventory for attack
        if (attack1 == 1 && (player.strength >= 7 || inventory[0] == "Sword")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = bosshp - 5;
            cout << "You have been attacked for 3 damage\n";
            // reducing player health
            player.health = player.health - 3;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Sword of Light (can only be used once)\n";
            cout << "5 Heal with Health Potion (can only be used once)\n";
            int starA;
            while (true) {
                if (cin >> starA) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Sword of Light (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starB;
                while (true) {
                    if (cin >> starB) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                switch (starB) {
                case 1:
                    // strength attack
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = bosshp - 5;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 2:
                    // intelligence attack
                    cout << "You have attacked enemy for 3 damage\n";
                    bosshp = bosshp - 3;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 3:
                    // dexterity attack
                    cout << "You have attacked enemy for 2 damage\n";
                    bosshp = bosshp - 2;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 4:
                    // sword of light attack
                    cout << "You have used the Sword of Light\n";
                    bosshp = bosshp - 10;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 5:
                    // health potion use
                    cout << "You have used the Health Potion\n";
                    player.health = player.health + 5;
                    inventory[3] = "";
                    break;
                }
                // loop condition
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
            // intelligence attack path
        }
        else if (attack1 == 2 && (player.intelligence >= 7 || inventory[1] == "Tome")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = 15;
            cout << "You have been attacked for 2 damage\n";
            // reducing player health
            player.health = player.health - 2;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Tome of Knowledge (can only be used once)\n";
            cout << "5 Use Health Potion (can only be used once)\n";
            int starC;
            while (true) {
                if (cin >> starC) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Tome of Knowledge (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starD;
                while (true) {
                    if (cin >> starD) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                switch (starD) {
                case 1:
                    // strength attack
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = bosshp - 5;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 2:
                    // intelligence attack
                    cout << "You have attacked enemy for 3 damage\n";
                    bosshp = bosshp - 3;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 3:
                    // dexterity attack
                    cout << "You have attacked enemy for 2 damage\n";
                    bosshp = bosshp - 2;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 4:
                    // tome of knowledge attack
                    cout << "You have used the Tome of Knowledge\n";
                    bosshp = bosshp - 10;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    // removing tome from inventory
                    inventory[1] = "";
                    break;
                case 5:
                    // health potion use
                    cout << "You have used the Health Potion\n";
                    player.health = player.health + 5;
                    // removing potion from inventory
                    inventory[3] = "";
                    break;
                }
                // loop condition
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
            // dexterity attack path
        }
        else if (attack1 == 3 && (player.dexterity >= 7 || inventory[2] == "Boots")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = 15;
            cout << "You have been attacked for 2 damage\n";
            // reducing player health
            player.health = player.health - 2;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Boots of Speed (can only be used once)\n";
            cout << "5 Use Health Potion (can only be used once)\n";
            int starE;
            while (true) {
                if (cin >> starE) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Boots of Speed (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starF;
                while (true) {
                    if (cin >> starF) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                switch (starF) {
                case 1:
                    // strength attack
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = bosshp - 5;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 2:
                    // intelligence attack
                    cout << "You have attacked enemy for 3 damage\n";
                    bosshp = bosshp - 3;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 3:
                    // dexterity attack
                    cout << "You have attacked enemy for 2 damage\n";
                    bosshp = bosshp - 2;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    break;
                case 4:
                    // boots of speed attack
                    cout << "You have used the Boots of Speed\n";
                    bosshp = bosshp - 10;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    // removing boots from inventory
                    inventory[2] = "";
                    break;
                case 5:
                    // health potion use
                    cout << "You have used the Health Potion\n";
                    player.health = player.health + 5;
                    // removing potion from inventory
                    inventory[3] = "";
                    break;
                }
                // loop condition
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
            // lose game over
        }
        else {
            cout << "You are not strong enough...\nGame Over\n";
            exit(0);
        }
    }
}
// save functions
void saveGame(const Player& player, string inventory[]) {
    // opening file in write mode
    ofstream file("savegame.txt");
    // writing player data to file
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
    }
    else {
        cout << "Unable to save game.\n";
    }
}
// load game function
void loadGame(Player& player, string inventory[]) {
    // opening file in read mode
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
    }
    else {
        cout << "No save file found.\n";
    }
}
// main function
int main() {
    // main game
    int number;
    Player player;
    // inventory array
    string inventory[10];
    int con;
    // starting stats
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
    // starting storyline
    cout << "Welcome to the adventure game\n";
    cout << "Once the world of Elarion thrived in harmony its kingdoms united under peace ";
    cout << "Malakar the Shadowbinder rose, shattering lands with fire and shadow. ";
    cout << "Hope faded, cities crumbled, and darkness claimed the skies. ";
    cout << "Prophecy whispered of a chosen hero, destined to rise. ";
    cout << "From the ashes, a light would be born to end the darkness.\n";
    cout << "You are a brave adventurer seekings to find your true purpose.\n";
    cout << "Your name is: \n";
    // taking user input for name
    cin >> player.name;
    // choosing backstory
    cout << "Chose your upbringing\n";
    cout << "1. Noble Raised in luxury\n";
    cout << "2. Orphan Grew up on the streets\n";
    cout << "3. Farmer Hard-working and tough from labor in the fields\n";
    int backstory;
    while (true) {
        if (cin >> backstory) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    switch (backstory) {
    case 1:
        // noble backstory
        cout << "You are a smart noble\n";
        increaseStat(&player.intelligence, 1);
        player.money += 30;
        break;
    case 2:
        // orphan backstory
        cout << "You are a fast orphan\n";
        increaseStat(&player.dexterity, 1);
        break;
    case 3:
        // farmer backstory
        cout << "You are a strong farmer\n";
        increaseStat(&player.strength, 1);
        break;
    default:
        // invalid choice
        cout << "Invalid choice, you are a peasant\n";
        break;
    }
    // choosing race
    cout << "Chose your race\n";
    cout << "1. Human Versatile and ambitious, humans thrive by adapting to any challenge in Elarion\n";
    cout << "2. Elf Children of the ancient forests, elves carry centuries of wisdom but are wary of outsiders\n";
    cout << "3. Dwarf Forged in stone and fire, dwarves are stubborn warriors who value strength and honor above all\n";
    int race;
    while (true) {
        if (cin >> race) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    switch (race) {
    case 1:
        // human race
        cout << "You are a smart human\n";
        increaseStat(&player.intelligence, 1);
        break;
    case 2:
        // elf race
        cout << "You are a fast elf\n";
        increaseStat(&player.dexterity, 1);
        break;
    case 3:
        // dwarf race
        cout << "You are a strong dwarf\n";
        increaseStat(&player.strength, 1);
        break;
    default:
        cout << "Invalid choice, you are a peasant\n";
        break;
    }
    // choosing profession
    cout << "Choose your profession:\n";
    cout << "1. Warrior\n";
    cout << "2. Mage\n";
    cout << "3. Rogue\n";
    while (true) {
        if (cin >> job) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // setting profession stats
    switch (job) {
    case 1:
        // warrior profession
        cout << "You are a strong warrior\n";
        increaseStat(&player.strength, 2);
        break;
    case 2:
        // mage profession
        cout << "You are a wise mage\n";
        increaseStat(&player.intelligence, 2);
        break;
    case 3:
        // rogue profession
        cout << "You are a stealthy rogue\n";
        increaseStat(&player.dexterity, 2);
        break;
    default:
        // invalid choice
        cout << "Invalid choice, you are a peasant\n";
        break;
    }
    // main loop
    cout << "Do you wish to continue? (1 = yes, 0 = no)\n";
    while (true) {
        if (cin >> con) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (con >= 1) {
        cout << "\nYou are in a forest\n";
        cout << "Enter a number between 1 and 6:\n";
        cout << "1 To go Strength route\n";
        cout << "2 To go Intelligence route\n";
        cout << "3 To go Dexterity route\n";
        cout << "4 To fight enemy\n";
        cout << "5 To fight the evil wizard\n";
        cout << "6 To see your stats\n";
        cout << "7 To train\n";
        cout << "8 rescue mission\n";
        cout << "9 invasion\n";
        cout << "10 Save game\n";
        cout << "11 Load game\n";
        cout << "12 Print inventory\n";
        cout << "13 Print map\n";
        cout << "-1 To end the game\n";
        while (true) {
            if (cin >> number) {
                break;
            }
            else {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        // switch case for user input
        switch (number) {
            // various cases for different routes and actions
        case -1: {
            cout << "Ending the game.\n";
            return 0;
        }
        case 1: {
            // strength path
            cout << "You have gone strength route\n";
            cout << "You see trees\n";
            cout << "You see a path\n";
            cout << "What do you wish to do?\n";
            cout << "1 To follow the path\n";
            cout << "2 To go back\n";
            int choice;
            while (true) {
                if (cin >> choice) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            do {
                switch (choice) {
                case 1:
                    // following the path
                    cout << "You follow the path\n";
                    cout << "You see a clearing\n";
                    cout << "You see a sword stuck in the ground\n";
                    // checking strength to obtain sword
                    if (player.strength > 6) {
                        cout << "You are strong enough to pull the sword out\n";
                        cout << "You have obtained the Sword of Light\n";
                        // adding sword to inventory
                        inventory[0] = "Sword";
                        choice = 2;
                    }
                    else {
                        cout << "You are not strong enough to pull the sword out\n";
                        choice = 2;
                    }
                    break;
                case 2:
                    // going back
                    cout << "You go back\n";
                    break;
                default:
                    // invalid choice
                    cout << "Invalid choice, you go back\n";
                    choice = 2;
                    break;
                }
            } while (choice != 2);
            break;
        }
        case 2: {
            // intelligence path
            cout << "You have gone the intelligence route\n";
            cout << "You see a clearing with a book on a pedestal\n";
            // checking intelligence to obtain tome
            if (player.intelligence > 6) {
                cout << "You are smart enough to understand the book\n";
                cout << "You have obtained the Tome\n";
                // adding tome to inventory
                inventory[1] = "Tome";
            }
            else {
                cout << "You are not smart enough to understand the book\n";
            }
            break;
        }
        case 3: {
            // dexterity path
            cout << "You have gone the dexterity route\n";
            cout << "You see a clearing with wolves guarding boots\n";
            if (player.dexterity > 6) {
                cout << "You are fast enough to grab the boots\n";
                cout << "You have obtained the Boots of Speed\n";
                // adding boots to inventory
                inventory[2] = "Boots";
            }
            else {
                cout << "You are not fast enough to grab the boots\n";
            }
            break;
        }
        case 4: {
            // fight enemy
            Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
            break;
        }
        case 5: {
            // fight boss
            fightBoss(player, inventory);
            break;
        }
        case 6: {
            // display stats
            displayStats(player);
            break;
        }
        case 7: {
            // training path
            cout << "You have gone to train\n";
            cout << "Choose an attribute to train:\n";
            cout << "1 Strength\n";
            cout << "2 Intelligence\n";
            cout << "3 Dexterity\n";
            int train;
            while (true) {
                if (cin >> train) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            // training switch case
            switch (train) {
            case 1:
                increaseStat(&player.strength, 1);
                cout << "Your strength is now " << player.strength << "\n";
                break;
            case 2:
                increaseStat(&player.intelligence, 1);
                cout << "Your intelligence is now " << player.intelligence << "\n";
                break;
            case 3:
                increaseStat(&player.dexterity, 1);
                cout << "Your dexterity is now " << player.dexterity << "\n";
                break;
            default:
                cout << "Invalid choice, you did not train\n";
                break;
            }
            // checking if player is ready for boss fight
            if (player.strength > 10 || player.intelligence > 10 || player.dexterity > 10) {
                cout << "You have trained enough to face Malakar!\n";
            }
            break;
        }
        case 8: {
            // rescue missin
            cout << "You see a villager in distress\n";
            cout << "They tell you that their daughter has been kidnapped by goblins\n";
            cout << "They beg you to rescue her\n";
            cout << "They will reward you with a family relic\n";
            cout << "Do you accept the quest? (1 = yes, 0 = no)\n";
            while (true) {
                if (cin >> quest) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            // quest switch case
            switch (quest) {
            case 1:
                cout << "You have accepted the quest\n";
                cout << "You go to the goblin village\n";
                cout << "How do you wish to enter the village\n";
                cout << "1 Go full attack\n";
                cout << "2 Sneak in\n";
                int no;
                while (true) {
                    if (cin >> no) {
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                // entering village switch case
                switch (no) {
                case 1:
                    // full attack
                    Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
                    cout << "You have rescued the daughter\n";
                    cout << "You have gone back to the villager\n";
                    cout << "The villager gives you the family relic\n";
                    inventory[4] = "Family Relic";
                    break;
                case 2:
                    // sneak in
                    if (player.dexterity >= 5) {
                        cout << "You have successfully sneaked in\n";
                        cout << "You see the daughter but you also see the goblins treasure\n";
                        cout << "What do you wish to do\n";
                        cout << "1 Rescue the daughter\n";
                        cout << "2 Steal the goblin treasure\n";
                        int decision;
                        while (true) {
                            if (cin >> decision) {
                                break;
                            }
                            else {
                                cout << "Invalid input" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        // decision switch case
                        switch (decision) {
                        case 1:
                            // rescue daughter
                            cout << "You have rescued the daughter\n";
                            cout << "You have gone back to the villager\n";
                            cout << "The villager gives you the family relic\n";
                            inventory[4] = "Family Relic";
                            break;
                        case 2:
                            // steal treasure
                            cout << "You have stolen the goblin treasure\n";
                            player.money += 100;
                            cout << "You have gone back to the villager\n";
                            cout << "The villager is angry that you did not rescue his daughter\n";
                            cout << "He refuses to give you the family relic\n";
                            cout << "You can steal the family relic\n";
                            cout << "Do you wish to steal the relic\n";
                            cout << "1 yes\n";
                            cout << "2 no\n";
                            int ste;
                            while (true) {
                                if (cin >> ste) {
                                    break;
                                }
                                else {
                                    cout << "Invalid input" << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            switch (ste) {
                                // stealing relic
                            case 1: {
                                cout << "You attack the villager while he is crying\n";
                                cout << "You steal the family relic\n";
                                inventory[4] = "Family Relic";
                                player.rep -= 5;
                                cout << "You steal all the money he has\n";
                                player.money += 10;
                                break;
                            }
                                  // not stealing relic
                            case 2: {
                                cout << "You dont steal the relic and leave\n";
                                break;
                            }
                            }
                            break;
                            // invalid decision
                        default:
                            cout << "Invalid choice, you go back empty handed\n";
                            break;
                        }
                        // successfully sneaked in
                    }
                    else {
                        cout << "You were not stealthy enough and got caught\n";
                        cout << "You have been defeated by the goblins\nGame Over\n";
                        return 0;
                    }
                    break;
                default:
                    // invalid choice
                    cout << "Invalid choice, you leave\n";
                    break;
                }
                break;
            default:
                // refusing quest
                cout << "You refuse to help and leave\n";
                break;
            }
            break;
        }
        case 9: {
            // invasion storyline
            cout << "You have heard of a war\n";
            cout << "You leave to join the army\n";
            cout << "The conscription dismisses you as weak\n";
            cout << "You decide to beat him in a fight\n";
            // fighting officer
            Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
            cout << "The commanding officer sees your strength\n";
            cout << "He puts you as a small brigade commander\n";
            cout << "The war starts and your troops wait for your command\n";
            int bro;
            int enetrop = 200;
            int troops = 100;
            // invasion loop
            cout << "You see the main forces clashing\n";
            cout << "What will you do\n";
            cout << "1 Wait\n";
            cout << "2 Charge\n";
            cout << "3 Find a better position\n";
            cout << "4 Loot dead bodies\n";
            int boy;
            while (true) {
                if (cin >> boy) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            do {
                // invasion choices
                switch (boy) {
                case 1:
                    // waiting and observing
                    cout << "You wait and see the battle\n";
                    cout << "The main forces are fully battling\n";
                    cout << "How will you proceed\n";
                    cout << "1 Look to attack from above\n";
                    cout << "2 Look to attack from the back\n";
                    cout << "3 Go in guns blazing\n";
                    int bor;
                    while (true) {
                        if (cin >> bor) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    // attack choices
                    switch (bor) {
                    case 1:
                        // attack from above
                        cout << "You have attacked from above\n";
                        troops = troops - 20;
                        enetrop = enetrop - 50;
                        cout << "You have lost 20 troops\n";
                        cout << "You have " << troops << " troops left\n";
                        break;
                    case 2:
                        // attack from back
                        cout << "You have attacked from the back\n";
                        enetrop = enetrop - 100;
                        troops = troops - 30;
                        cout << "You have lost 30 troops\n";
                        cout << "You have " << troops << " troops left\n";
                        break;
                    case 3:
                        // guns blazing
                        cout << "You have gone in guns blazing\n";
                        cout << "You have lost the battle\n";
                        troops = troops - 100;
                        cout << "You have lost all your troops\nGame Over\n";
                        return 0;
                    default:
                        // invalid choice
                        cout << "Invalid choice, you lose the battle\nGame Over\n";
                        return 0;
                    }
                    break;
                    // charging into battle
                case 2: {
                    cout << "You have charged into battle\n";
                    // checking strength for battle outcome
                    if (player.strength >= 7) {
                        cout << "You have won the battle\n";
                        enetrop = enetrop - 100;
                        troops = troops - 30;
                        cout << "You have lost 30 troops\n";
                        cout << "You have " << troops << " troops left\n";
                    }
                    else {
                        // losing battle
                        cout << "You have lost the battle\n";
                        troops = troops - 100;
                        cout << "You have lost all your troops\nGame Over\n";
                        return 0;
                    }
                    break;
                }
                      // finding better position
                case 3: {
                    cout << "You have found a better position\n";
                    cout << "You see gold of the enemy\n";
                    cout << "Do you\n";
                    cout << "1 Attack the enemy\n";
                    cout << "2 Loot the gold\n";
                    int hope;
                    while (true) {
                        if (cin >> hope) {
                            break;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    switch (hope) {
                    case 1:
                        // attacking enemy
                        cout << "You have attacked the enemy\n";
                        enetrop = enetrop - 50;
                        troops = troops - 40;
                        cout << "You have lost 40 troops\n";
                        cout << "You have " << troops << " troops left\n";
                        break;
                    case 2:
                        // looting gold
                        cout << "You have looted the gold\n";
                        player.money += 200;
                        player.rep -= 5;
                        cout << "You have gained 200 gold\n";
                        cout << "You have lost reputation\n";
                        break;
                    default:
                        // invalid choice
                        cout << "Invalid choice, you lose the battle\nGame Over\n";
                        return 0;
                    }
                    break;
                }
                      // looting dead bodies
                case 4: {
                    cout << "You have looted the dead bodies\n";
                    player.money += 100;
                    player.rep -= 5;
                    troops = 0;
                    // ending battle
                    cout << "You have gained 100 gold\n";
                    cout << "You have lost reputation\n";
                    bro = 0;
                    break;
                }
                default:
                    // invalid choice
                    cout << "Invalid choice, you lose the battle\nGame Over\n";
                    return 0;
                }
                // loop condition
            } while ((enetrop > 0 && troops > 0));
            // battle outcome
            if (troops <= 0) {
                cout << "You have lost all your troops\n";
            }
            else if (enetrop <= 0) {
                cout << "You have won the battle\n";
                cout << "You have been promoted to general\n";
                player.rep += 10;
            }
            else {
                cout << "Error\n";
            }
            break;
        }
              // save game
        case 10: {
            saveGame(player, inventory);
            break;
        }
               // load game
        case 11: {
            loadGame(player, inventory);
            break;
        }
               // print inventory
        case 12: {
            printInventory(inventory, 10);
            break;
        }
               // print map
        case 13: {
            printMap(gameMap, 7);
            break;
        }
               // invalid choice
        default:
            cout << "Invalid choice, try again\n";
            break;
        }
    }
    // ending game
    cout << "\nDo you wish to continue? (1 = yes, 0 = no)\n";
    while (true) {
        if (cin >> con) {
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Thanks for playing!\n";
    // ending main
    return 0;
}