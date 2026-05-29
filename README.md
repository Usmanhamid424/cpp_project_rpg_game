# ⚔️ Elarion — A Text-Based RPG in C++

A console-based role-playing game set in the fantasy world of **Elarion**, built entirely in C++ as a first-semester university project. The game features a branching narrative, turn-based combat, an inventory system, a save/load mechanic, and multiple endings — all driven through text input.

---

## 🌍 Story

> *Once the world of Elarion thrived in harmony, its kingdoms united under peace. Then Malakar the Shadowbinder rose, shattering lands with fire and shadow. Hope faded, cities crumbled, and darkness claimed the skies. Prophecy whispered of a chosen hero, destined to rise from the ashes.*

You are that hero. Shape your destiny through the choices you make.

---

## 🎮 Features

- **Character Customization** — Choose your backstory (Noble, Orphan, Farmer), race (Human, Elf, Dwarf), and profession (Warrior, Mage, Rogue), each affecting your starting stats
- **Stat System** — Manage Strength, Intelligence, and Dexterity throughout the game; stats influence combat outcomes and story paths
- **Turn-Based Combat** — Fight enemies using your chosen stat, with randomized enemy attack patterns (Light, Normal, Heavy, Special)
- **Recursive Battle Engine** — Combat rounds handled via recursion for a dynamic, looping fight system
- **Inventory System** — Collect items like the Sword of Light, Tome of Knowledge, Boots of Speed, and Health Potions; use them strategically in battle
- **Multiple Quests** — Rescue missions, army invasions, training paths, and exploration routes with moral choices that affect your reputation
- **Boss Fight — Malakar the Shadowbinder** — The final battle adapts based on your reputation score, unlocking different dialogue and endings
- **Multiple Endings** — Hero, Villain, Overlord, and Game Over endings based on the choices made throughout the game
- **Save & Load System** — Persist game state to a file and resume your adventure anytime
- **Game Map** — A 7x7 2D grid representing the world of Elarion
- **Input Validation** — Handles invalid inputs gracefully throughout the game

---

## 🛠️ Built With

- **Language:** C++
- **Libraries:** `iostream`, `fstream`, `cstdlib`, `ctime`, `string`, `limits`
- **Concepts Used:** Structs, Arrays, Pointers, Recursion, File I/O, Switch-Case, Input Validation, OOP-lite design

---

## 🚀 How to Run

### Prerequisites
- A C++ compiler (GCC / G++ recommended)
- Any terminal or IDE (VS Code, Code::Blocks, Visual Studio)

### Compile & Run
```bash
g++ main.cpp -o elarion
./elarion
```

Or on Windows:
```bash
g++ main.cpp -o elarion.exe
elarion.exe
```

---

## 🗺️ Gameplay Overview

```
1  → Strength Route     — Find the Sword of Light
2  → Intelligence Route — Obtain the Tome of Knowledge
3  → Dexterity Route    — Grab the Boots of Speed
4  → Fight Enemy        — Enter turn-based combat
5  → Fight Boss         — Face Malakar (final battle)
6  → View Stats         — Check current attributes
7  → Train              — Improve a chosen stat
8  → Rescue Mission     — A moral side quest
9  → Invasion           — Lead troops into battle
10 → Save Game
11 → Load Game
12 → View Inventory
13 → View Map
-1 → Quit
```

---

## 📁 Project Structure

```
elarion/
│
├── main.cpp        # Full game source code
└── README.md       # Project documentation
```

*Note: `savegame.txt` is generated automatically when you save.*

---

## 👤 Authors

**Muhammad Zunain Tahir**  
BAI Student @ GIK Institute of Engineering Sciences and Technology ('29)  
[LinkedIn](https://www.linkedin.com/in/zunaintahir) | [GitHub](https://github.com/ZunainTahir)

**Usman Hamid**
BAI Student @ GIK Institute of Engineering Sciences and Technology ('29)  
[GitHub](https://github.com/Usmanhamid424)


## 📌 Note

This project demonstrates applied use of core C++ concepts including recursion, file handling, pointer-based functions, and structured game logic — all implemented from scratch without any game engine or external library.
