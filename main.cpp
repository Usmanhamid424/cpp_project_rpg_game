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
    if(enehp >= 0 && player.health >= 0){
        recursiveBattleRound(player, enehp, inventory);
    }
}
int Battle(Player &player, int &enehp, int &strength, int &intelligence, int &dexterity, string inventory[]) {
    int fight;
    int star;
    srand(time(0));
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
    cout << "3 With dexterity\n";
    cin >> fight;
    if ((fight == 1 && strength > 5) || (fight == 2 && intelligence > 5) || (fight == 3 && dexterity > 5)) {
        cout << "You have attacked enemy for 5 damage\n";
        enehp = enehp - 3;
        cout << "You have been attacked for 2 damage\n";
        player.health = player.health - 2;
        cout << "Your next attack\n";
        cout << "How will you attack\n";
        cout << "1 With strength\n";
        cout << "2 With intelligence\n";
        cout << "3 With dexterity\n";
        cout << "4 with Sword of light can only be used once\n";
        recursiveBattleRound(player, enehp, inventory);
        if (player.health <= 0) {
            cout << "You have lost\n";
        } else if (enehp <= 0) {
            cout << "You have won\n";
            cout << "You have leveled up\n";
            if (player.health <= 20) {
                player.health = 20;
                cout << "Your health is now " << player.health << "\n";
            }
            increaseStat(&player.strength, 1);
            increaseStat(&player.intelligence, 1);
            increaseStat(&player.dexterity, 1);
        } else {
            cout << "Error\n";
        }
        cout << "You have defeated the enemy \n";
        cout << "You have obtained a Health Potion\n";
        inventory[3] = "Health Potion";
        cout << "You have gained 10 Gold\n";
    }
    return 0;
}
void fightBoss(Player &player, string inventory[]){
    int bosshp = 20;
    cout << "You face Malakar the Shadowbinder!\n";
    if (player.rep < 10) {
        cout << "Malakar has heard of your evil deeds\n";
        cout << "He asks if you wish to join him\n";
        cout << "What will you do?\n";
        cout << "1 Join him\n";
        cout << "2 Fight him\n";
        cout << "3 kill him and take his place\n";
        int yo;
        cin >> yo;
        switch (yo){
            case 1:
                cout << "You have joined Malakar\n";
                cout << "You invade the human plains with him\n";
                cout << "You kill humans as you see them\n";
                cout << "They fear you\n";
                cout << "You are one of the best in the world but are only the right hand man\n";
                exit(0);
            case 2:
                cout << "You have chosen to fight Malakar\n";
                cout << "How will you attack him?\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                int attack;
                cin >> attack;
                if (attack == 1 && player.strength >= 7 || inventory[0] == "Sword") {
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = 15;
                    cout << "You have been attacked for 3 damage\n";
                    player.health = player.health - 3;
                    cout << "Your next attack\n";
                    cout << "How will you attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Sword of light can only be used once \n";
                    cout << "5 heal with health potion can only be used once \n";
                    int start;
                    cin >> start;
                    do {
                        cout << "Confirm your attack\n";
                        cout << "1 With strength\n";
                        cout << "2 With intelligence\n";
                        cout << "3 With dexterity\n";
                        cout << "4 with Tome of knowledge can only be used once";
                        cout << "5 use health potion can only be used once \n";
                        cin >> start;
                        switch (start) {
                            case 1:
                                cout << "You have attacked enemy for 5 damage\n";
                                bosshp = bosshp - 5;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 2:
                                cout << "You have attacked enemy for 3 damage\n";
                                bosshp = bosshp - 3;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 3:
                                cout << "You have attacked enemy for 2 damage\n";
                                bosshp = bosshp - 2;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 4:
                                cout << "You have used the Sword of Light\n";
                                bosshp = bosshp - 10;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 5:
                                cout << "You have used the Health Potion\n";
                                player.health = player.health + 5;
                                inventory[3] = "";
                                break;
                        }
                    } while (bosshp >= 0 && player.health != 0);
                    cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                    cout << "People sing your praises\nYou are hailed as a hero\n";
                    cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                    exit(0);
                } else if (attack == 2 && player.intelligence >= 7 || inventory[1] == "Tome") {
                    cout << "You have attacked enemy for 5 damage\n";
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
                    cin >> start1;
                    do {
                        cout << "Confirm your attack\n";
                        cout << "1 With strength\n";
                        cout << "2 With intelligence\n";
                        cout << "3 With dexterity\n";
                        cout << "4 with Tome of knowledge can only be used once";
                        cout << "5 use health potion can only be used once \n";
                        cin >> start1;
                        switch (start1) {
                            case 1:
                                cout << "You have attacked enemy for 5 damage\n";
                                bosshp = bosshp - 5;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 2:
                                cout << "You have attacked enemy for 3 damage\n";
                                bosshp = bosshp - 3;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 3:
                                cout << "You have attacked enemy for 2 damage\n";
                                bosshp = bosshp - 2;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 4:
                                cout << "You have used the tome of knowledge\n";
                                bosshp = bosshp - 10;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                inventory[1] = "";
                                break;
                            case 5:
                                cout << "You have used the Health Potion\n";
                                player.health = player.health + 5;
                                inventory[3] = "";
                                break;
                        }
                    } while (bosshp >= 0 && player.health != 0);
                    cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                    cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                    cout << "People sing your praises\nYou are hailed as a hero\n";
                    cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                    exit(0);
                } else if (attack == 3 && player.dexterity >= 7 || inventory[2] == "Boots") {
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = 15;
                    cout << "You have been attacked for 2 damage\n";
                    player.health = player.health - 2;
                    cout << "Your next attack\n";
                    cout << "How will you attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Sword of light can only be used once";
                    int start2;
                    cin >> start2;
                    do {
                        cout << "Confirm your attack\n";
                        cout << "1 With strength\n";
                        cout << "2 With intelligence\n";
                        cout << "3 With dexterity\n";
                        cout << "4 with Tome of knowledge can only be used once";
                        cout << "5 use health potion can only be used once \n";
                        cin >> start2;
                        switch (start2) {
                            case 1:
                                cout << "You have attacked enemy for 5 damage\n";
                                bosshp = bosshp - 5;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 2:
                                cout << "You have attacked enemy for 3 damage\n";
                                bosshp = bosshp - 3;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 3:
                                cout << "You have attacked enemy for 2 damage\n";
                                bosshp = bosshp - 2;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 4:
                                cout << "You have used the boots\n";
                                bosshp = bosshp - 10;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                inventory[2] = "";
                                break;
                            case 5:
                                cout << "You have used the Health Potion\n";
                                player.health = player.health + 5;
                                inventory[3] = "";
                                break;
                        }
                    } while (bosshp >= 0 && player.health != 0);
                    cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                    cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
                    cout << "People sing your praises\nYou are hailed as a hero\n";
                    cout << "You may be know as a hero but those you hurt know your truth\nYou are a monster\n";
                    exit(0);
                } else {
                    cout << "You are not strong enough...\nGame Over\n";
                    exit(0);
                }
                break;
            case 3:
                cout << "You have chosen to kill Malakar and take his place\n";
                cout << "How will you attack him?\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cin >> attack;
                if (attack == 1 && player.strength >= 7 || inventory[0] == "Sword") {
                    cout << "You have attacked enemy for 5 damage\n";
                    bosshp = 15;
                    cout << "You have been attacked for 3 damage\n";
                    player.health = player.health - 3;
                    cout << "Your next attack\n";
                    cout << "How will you attack\n";
                    cout << "1 With strength\n";
                    cout << "2 With intelligence\n";
                    cout << "3 With dexterity\n";
                    cout << "4 with Sword of light can only be used once \n";
                    cout << "5 heal with health potion can only be used once \n";
                    int start;
                    cin >> start;
                    do {
                        cout << "Confirm your attack\n";
                        cout << "1 With strength\n";
                        cout << "2 With intelligence\n";
                        cout << "3 With dexterity\n";
                        cout << "4 with Tome of knowledge can only be used once";
                        cout << "5 use health potion can only be used once \n";
                        cin >> start;
                        switch (start) {
                            case 1:
                                cout << "You have attacked enemy for 5 damage\n";
                                bosshp = bosshp - 5;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 2:
                                cout << "You have attacked enemy for 3 damage\n";
                                bosshp = bosshp - 3;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 3:
                                cout << "You have attacked enemy for 2 damage\n";
                                bosshp = bosshp - 2;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 4:
                                cout << "You have used the Sword of Light\n";
                                bosshp = bosshp - 10;
                                cout << "You have been attacked for 2 damage\n";
                                player.health = player.health - 2;
                                break;
                            case 5:
                                cout << "You have used the Health Potion\n";
                                player.health = player.health + 5;
                                inventory[3] = "";
                                break;
                        }
                    } while (bosshp >= 0 && player.health != 0);
                    cout << "You are now the new evil overlord of Elarion\n";
                    cout << "You are feared all across the world\n";
                    cout << "You are the worlds new king\n";
                    exit(0);
                } else {
                    cout << "Invalid choice, Malakar has killed you\n";
                    exit(0);
                }
                break;
            default:
                cout << "Invalid choice, Malakar has killed you\n";
                exit(0);
        }
    } else {
        cout << "How will you attack him?\n";
        cout << "1 With strength\n";
        cout << "2 With intelligence\n";
        cout << "3 With dexterity\n";
        int attack1;
        cin >> attack1;
        if (attack1 == 1 && (player.strength >= 7 || inventory[0] == "Sword")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = bosshp - 5;
            cout << "You have been attacked for 3 damage\n";
            player.health = player.health - 3;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Sword of Light (can only be used once)\n";
            cout << "5 Heal with Health Potion (can only be used once)\n";
            int starA;
            cin >> starA;
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Sword of Light (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starB;
                cin >> starB;
                switch (starB) {
                    case 1:
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        cout << "You have used the Sword of Light\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 5:
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        inventory[3] = "";
                        break;
                }
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
        } else if (attack1 == 2 && (player.intelligence >= 7 || inventory[1] == "Tome")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = 15;
            cout << "You have been attacked for 2 damage\n";
            player.health = player.health - 2;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Tome of Knowledge (can only be used once)\n";
            cout << "5 Use Health Potion (can only be used once)\n";
            int starC;
            cin >> starC;
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Tome of Knowledge (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starD;
                cin >> starD;
                switch (starD) {
                    case 1:
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        cout << "You have used the Tome of Knowledge\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        inventory[1] = "";
                        break;
                    case 5:
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        inventory[3] = "";
                        break;
                }
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
        } else if (attack1 == 3 && (player.dexterity >= 7 || inventory[2] == "Boots")) {
            cout << "You have attacked enemy for 5 damage\n";
            bosshp = 15;
            cout << "You have been attacked for 2 damage\n";
            player.health = player.health - 2;
            cout << "Your next attack\n";
            cout << "How will you attack\n";
            cout << "1 With strength\n";
            cout << "2 With intelligence\n";
            cout << "3 With dexterity\n";
            cout << "4 With Boots of Speed (can only be used once)\n";
            cout << "5 Use Health Potion (can only be used once)\n";
            int starE;
            cin >> starE;
            do {
                cout << "Confirm your attack\n";
                cout << "1 With strength\n";
                cout << "2 With intelligence\n";
                cout << "3 With dexterity\n";
                cout << "4 With Boots of Speed (can only be used once)\n";
                cout << "5 Use Health Potion (can only be used once)\n";
                int starF;
                cin >> starF;
                switch (starF) {
                    case 1:
                        cout << "You have attacked enemy for 5 damage\n";
                        bosshp = bosshp - 5;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 2:
                        cout << "You have attacked enemy for 3 damage\n";
                        bosshp = bosshp - 3;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 3:
                        cout << "You have attacked enemy for 2 damage\n";
                        bosshp = bosshp - 2;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        break;
                    case 4:
                        cout << "You have used the Boots of Speed\n";
                        bosshp = bosshp - 10;
                        cout << "You have been attacked for 2 damage\n";
                        player.health = player.health - 2;
                        inventory[2] = "";
                        break;
                    case 5:
                        cout << "You have used the Health Potion\n";
                        player.health = player.health + 5;
                        inventory[3] = "";
                        break;
                }
            } while (bosshp > 0 && player.health > 0);
            cout << "You have defeated Malakar!\nPeace returns to Elarion.\n";
            cout << "You are hailed as a hero!\nYou are written into the annals of history.\n";
            cout << "You have won!\nThank you for playing.\n";
            exit(0);
        } else {
            cout << "You are not strong enough...\nGame Over\n";
            exit(0);
        }
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
    cout << "Do you wish to continue? (1 = yes, 0 = no)\n";
    cin >> con;
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
        cin >> number;
        switch (number) {
            case -1: {
                cout << "Ending the game.\n";
                return 0;
            }
            case 1: {
                cout << "You have gone strength route\n";
                cout << "You see trees\n";
                cout << "You see a path\n";
                cout << "What do you wish to do?\n";
                cout << "1 To follow the path\n";
                cout << "2 To go back\n";
                int choice;
                cin >> choice;
                do {
                    switch (choice) {
                        case 1:
                            cout << "You follow the path\n";
                            cout << "You see a clearing\n";
                            cout << "You see a sword stuck in the ground\n";
                            if (player.strength > 6) {
                                cout << "You are strong enough to pull the sword out\n";
                                cout << "You have obtained the Sword of Light\n";
                                inventory[0] = "Sword";
                                choice = 2;
                            } else {
                                cout << "You are not strong enough to pull the sword out\n";
                                choice = 2;
                            }
                            break;
                        case 2:
                            cout << "You go back\n";
                            break;
                        default:
                            cout << "Invalid choice, you go back\n";
                            choice = 2;
                            break;
                    }
                } while (choice != 2);
                break;
            }
            case 2: {
                cout << "You have gone the intelligence route\n";
                cout << "You see a clearing with a book on a pedestal\n";
                if (player.intelligence > 6) {
                    cout << "You are smart enough to understand the book\n";
                    cout << "You have obtained the Tome\n";
                    inventory[1] = "Tome";
                } else {
                    cout << "You are not smart enough to understand the book\n";
                }
                break;
            }
            case 3: {
                cout << "You have gone the dexterity route\n";
                cout << "You see a clearing with wolves guarding boots\n";
                if (player.dexterity > 6) {
                    cout << "You are fast enough to grab the boots\n";
                    cout << "You have obtained the Boots of Speed\n";
                    inventory[2] = "Boots";
                } else {
                    cout << "You are not fast enough to grab the boots\n";
                }
                break;
            }
            case 4: {
                Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
                break;
            }
            case 5: {
                fightBoss(player, inventory);
                break;
            }
            case 6: {
                displayStats(player);
                break;
            }
            case 7: {
                cout << "You have gone to train\n";
                cout << "Choose an attribute to train:\n";
                cout << "1 Strength\n";
                cout << "2 Intelligence\n";
                cout << "3 Dexterity\n";
                int train;
                cin >> train;
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
                if (player.strength > 10 || player.intelligence > 10 || player.dexterity > 10) {
                    cout << "You have trained enough to face Malakar!\n";
                }
                break;
            }
            case 8: {
                cout << "You see a villager in distress\n";
                cout << "They tell you that their daughter has been kidnapped by goblins\n";
                cout << "They beg you to rescue her\n";
                cout << "They will reward you with a family relic\n";
                cout << "Do you accept the quest? (1 = yes, 0 = no)\n";
                cin >> quest;
                switch (quest) {
                    case 1:
                        cout << "You have accepted the quest\n";
                        cout << "You go to the goblin village\n";
                        cout << "How do you wish to enter the village\n";
                        cout << "1 Go full attack\n";
                        cout << "2 Sneak in\n";
                        int no;
                        cin >> no;
                        switch (no) {
                            case 1:
                                Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
                                cout << "You have rescued the daughter\n";
                                cout << "You have gone back to the villager\n";
                                cout << "The villager gives you the family relic\n";
                                inventory[4] = "Family Relic";
                                break;
                            case 2:
                                if (player.dexterity >= 5) {
                                    cout << "You have successfully sneaked in\n";
                                    cout << "You see the daughter but you also see the goblins treasure\n";
                                    cout << "What do you wish to do\n";
                                    cout << "1 Rescue the daughter\n";
                                    cout << "2 Steal the goblin treasure\n";
                                    int decision;
                                    cin >> decision;
                                    switch (decision) {
                                        case 1:
                                            cout << "You have rescued the daughter\n";
                                            cout << "You have gone back to the villager\n";
                                            cout << "The villager gives you the family relic\n";
                                            inventory[4] = "Family Relic";
                                            break;
                                        case 2:
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
                                            cin >> ste;
                                            switch (ste) {
                                                case 1: {
                                                    cout << "You attack the villager while he is crying\n";
                                                    cout << "You steal the family relic\n";
                                                    inventory[4] = "Family Relic";
                                                    player.rep -= 5;
                                                    cout << "You steal all the money he has\n";
                                                    player.money += 10;
                                                    break;
                                                }
                                                case 2: {
                                                    cout << "You don’t steal the relic and leave\n";
                                                    break;
                                                }
                                            }
                                            break;
                                        default:
                                            cout << "Invalid choice, you go back empty handed\n";
                                            break;
                                    }
                                } else {
                                    cout << "You were not stealthy enough and got caught\n";
                                    cout << "You have been defeated by the goblins\nGame Over\n";
                                    return 0;
                                }
                                break;
                            default:
                                cout << "Invalid choice, you leave\n";
                                break;
                        }
                        break;
                    default:
                        cout << "You refuse to help and leave\n";
                        break;
                }
                break;
            }
            case 9:{
                cout << "You have heard of a war\n";
                cout << "You leave to join the army\n";
                cout << "The conscription dismisses you as weak\n";
                cout << "You decide to beat him in a fight\n";
                Battle(player, enehp, player.strength, player.intelligence, player.dexterity, inventory);
                cout << "The commanding officer sees your strength\n";
                cout << "He puts you as a small brigade commander\n";
                cout << "The war starts and your troops wait for your command\n";
                int bitch;
                int enetrop = 200;
                int troops = 100;
                cout << "You see the main forces clashing\n";
                cout << "What will you do\n";
                cout << "1 Wait\n";
                cout << "2 Charge\n";
                cout << "3 Find a better position\n";
                cout << "4 Loot dead bodies\n";
                int boi;
                cin >> boi;
                do {
                    switch (boi) {
                        case 1:
                            cout << "You wait and see the battle\n";
                            cout << "The main forces are fully battling\n";
                            cout << "How will you proceed\n";
                            cout << "1 Look to attack from above\n";
                            cout << "2 Look to attack from the back\n";
                            cout << "3 Go in guns blazing\n";
                            int bor;
                            cin >> bor;
                            switch (bor) {
                                case 1:
                                    cout << "You have attacked from above\n";
                                    troops = troops - 20;
                                    enetrop = enetrop - 50;
                                    cout << "You have lost 20 troops\n";
                                    cout << "You have " << troops << " troops left\n";
                                    break;
                                case 2:
                                    cout << "You have attacked from the back\n";
                                    enetrop = enetrop - 100;
                                    troops = troops - 30;
                                    cout << "You have lost 30 troops\n";
                                    cout << "You have " << troops << " troops left\n";
                                    break;
                                case 3:
                                    cout << "You have gone in guns blazing\n";
                                    cout << "You have lost the battle\n";
                                    troops = troops - 100;
                                    cout << "You have lost all your troops\nGame Over\n";
                                    return 0;
                                default:
                                    cout << "Invalid choice, you lose the battle\nGame Over\n";
                                    return 0;
                            }
                            break;
                        case 2: {
                            cout << "You have charged into battle\n";
                            if (player.strength >= 7) {
                                cout << "You have won the battle\n";
                                enetrop = enetrop - 100;
                                troops = troops - 30;
                                cout << "You have lost 30 troops\n";
                                cout << "You have " << troops << " troops left\n";
                            } else {
                                cout << "You have lost the battle\n";
                                troops = troops - 100;
                                cout << "You have lost all your troops\nGame Over\n";
                                return 0;
                            }
                            break;
                        }
                        case 3: {
                            cout << "You have found a better position\n";
                            cout << "You see gold of the enemy\n";
                            cout << "Do you\n";
                            cout << "1 Attack the enemy\n";
                            cout << "2 Loot the gold\n";
                            int ho;
                            cin >> ho;
                            switch (ho) {
                                case 1:
                                    cout << "You have attacked the enemy\n";
                                    enetrop = enetrop - 50;
                                    troops = troops - 40;
                                    cout << "You have lost 40 troops\n";
                                    cout << "You have " << troops << " troops left\n";
                                    break;
                                case 2:
                                    cout << "You have looted the gold\n";
                                    player.money += 200;
                                    player.rep -= 5;
                                    cout << "You have gained 200 gold\n";
                                    cout << "You have lost reputation\n";
                                    break;
                                default:
                                    cout << "Invalid choice, you lose the battle\nGame Over\n";
                                    return 0;
                            }
                            break;
                        }
                        case 4: {
                            cout << "You have looted the dead bodies\n";
                            player.money += 100;
                            player.rep -= 5;
                            troops = 0;
                            cout << "You have gained 100 gold\n";
                            cout << "You have lost reputation\n";
                            bitch = 0;
                            break;
                        }
                        default:
                            cout << "Invalid choice, you lose the battle\nGame Over\n";
                            return 0;
                    }
                } while ((enetrop > 0 && troops > 0));
                if (troops <= 0) {
                    cout << "You have lost all your troops\n";
                } else if (enetrop <= 0) {
                    cout << "You have won the battle\n";
                    cout << "You have been promoted to general\n";
                    player.rep += 10;
                } else {
                    cout << "Error\n";
                }
                break;
            }
            case 10: {
                saveGame(player, inventory);
                break;
            }
            case 11: {
                loadGame(player, inventory);
                break;
            }
            case 12: {
                printInventory(inventory, 10);
                break;
            }
            case 13: {
                printMap(gameMap, 7);
                break;
            }
            default:
                cout << "Invalid choice, try again\n";
                break;
        }
    }
    cout << "\nDo you wish to continue? (1 = yes, 0 = no)\n";
    cin >> con;
    cout << "Thanks for playing!\n";
    return 0;
}