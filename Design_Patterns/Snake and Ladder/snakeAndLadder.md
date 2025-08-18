## 🎬 Movie Analogy for Game Flow

### **main.cpp → 🎥 The Director**

- Starts the whole movie (game).
- Chooses the script (rules), actors (players), and the stage (board).
- Calls `game.play()` → “Action!”.

---

### **GameFactory.h → 🏭 Production House**

- Responsible for creating the **Game** object.
- Decides which rulebook (Standard or Custom) to use.
- **Analogy:** Like a movie studio deciding whether to shoot a comedy or a thriller.

---

### **Game.h → 🎭 Stage Manager (Core Engine)**

- Keeps track of:
  - Players (`deque` → makes turn rotation simple).
  - Board (where snakes and ladders live).
  - Rules (how the game works).
- **Methods:**
  - `addPlayer()` → cast actors for the movie.
  - `play()` → main loop:
    - Roll dice 🎲.
    - Move player.
    - Check if snake 🐍 or ladder 🪜 changes the position.
    - Check if someone reached 100 (win 🏆).
    - Switch turn to next player.
- **Analogy:** Like the stage manager who makes sure the show continues smoothly.

---

### **Board.h → 🎪 The Stage**

- Holds the map of snakes and ladders.
- **Methods:**
  - `isSnake(pos)` → check if player landed on a snake head.
  - `isLadder(pos)` → check if player landed at bottom of a ladder.
- **Analogy:** The playground where surprises (snake bites, ladders) happen.

---

### **Player.h → 👨‍🎤 The Actors**

- Each player has:
  - A **name**.
  - A **score** (current position on board).
- They roll the dice and move around the board.
- **Analogy:** Like actors performing on stage.

---

### **Rules.h (interface) + standardRules.h (concrete) → 📜 The Scriptwriters**

- Define how the game should be played.
- **standardRules** handles:
  - Dice rolling 🎲 (`rollDice()`).
  - Checking win condition (must reach 100).
  - Snake check.
  - Ladder check.
- **Analogy:** The script that all actors must follow, but can be swapped (e.g., different board size, different rules).

---

### **GameType.h → 🎞️ Genre of the Movie**

- Defines type of game → `STANDARD`, `CUSTOM`.
- **Analogy:** Whether the movie is a comedy, thriller, or drama.

---

## 🎯 Design Patterns Used

### 🏭 Factory Pattern

- **GameFactory** creates the Game object with appropriate rules.
- **Benefit →** Flexible: add new game types later without changing `main.cpp`.

### 🎭 Strategy Pattern

- **Rules** is an interface.
- **standardRules** implements it.
- **Benefit →** New rules (like bigger board, multi-dice) can be plugged in easily.
