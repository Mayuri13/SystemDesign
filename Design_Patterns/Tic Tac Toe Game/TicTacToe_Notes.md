# 🎮 Tic Tac Toe Game - Project Notes

## 📂 Project File Structure

    TicTacToeGame/
      Tic Tac Toe Game/
        main.cpp               # Entry point of the game
        Game.h                 # Main Game logic
        GameFactory.h          # Factory pattern (creates Game instance)
        Board.h                # Board structure and display
        consoleNotifier.h      # Observer implementation for notifications
        standardRules.h        # Rules implementation (win/draw/valid moves)
        utilities/
          Players.h            # Player and Symbol classes
          GameType.h           # Enum for game type (STANDARD, etc.)
          Symbols.h            # Game symbols (X, O)
        interfaces/
          IObserver.h          # Observer interface
          Rules.h              # Rules interface

---

## 🎬 Movie Analogy for Game Flow

- **main.cpp → Director**
  - Starts everything.
  - Decides actors (players), stage (board size), and script (game
    type).
  - Then says: "Action!" → `game.play()`.
- **GameFactory.h → Production House**
  - Creates the Game object when director demands it.
  - Different movie → different factory setup (STANDARD, CUSTOM,
    etc.).
  - Analogy: Like a movie studio deciding whether to make an action
    film or a comedy.
- **Game.h → Stage Manager (Core Game Engine)**
  - Core of the project.
  - Holds:
    - Players (deque → easy rotation of turns).
    - Board (Board\*).
    - Rules (Rules\*).
    - Observers (for notifications).
  - Methods:
    - addPlayer() → add players.
    - addObserver() → attach observers.
    - notify() → send messages to observers.
    - play() → main loop:
      - Displays board.
      - Takes input from current player.
      - Checks move validity, win, draw.
      - Switches turns until game ends.
  - Analogy: Like the stage manager who ensures play goes smoothly.
- **Board.h → The Stage**
  - The actual place where players act (marks X & O).
  - Responsible only for displaying and updating squares.
- **Players.h + Symbols.h → The Actors**
  - Players = Actors.
  - Symbols (X, O) = Their costumes.
  - Actors wear costumes and perform on stage.
- **Rules.h (interface) + standardRules.h (concrete class)→ Script Writers**

  - Defines what is a valid move, when game ends, who wins.
  - Analogy: Like the script telling actors what is allowed in the
    play.
  - Can change rules (different genres of the play) without changing
    stage manager.

- **IObserver.h (interface) + consoleNotifier.h (concrete class)→ The Audience /
  Announcers**
  - Audience reacts to what's happening.
  - Observers are like announcers who shout:
    - "Player 1 wins!" 🎉
    - "It's a draw!" 😮
  - New audience (GUI, mobile, log files) can be added later without
    touching game logic.
- **GameType.h → Genre of the Movie**
  - STANDARD, CUSTOM, etc.
  - Analogy: Whether the movie is a comedy or thriller, rules and
    flow will change.

---

## 🎯 Design Patterns Used

### 🏭 Factory Pattern

- **GameFactory** creates Game objects.\
- **Benefit →** centralizes object creation, makes it easy to extend
  for different game types.

### 👀 Observer Pattern

- **IObserver + consoleNotifier.**\
- Used to send messages (like "Player X wins" or "Game Draw") without
  changing core game logic.\
- **Benefit →** Allows adding multiple observers later (e.g., GUI,
  file logger).

### 🎭 Strategy Pattern

- **Rules are defined in Rules interface.**\
- **standardRules implements it.**\
- **Benefit →** You could easily plug in new rules (like "4x4 Tic Tac
  Toe" or "misère Tic Tac Toe") without modifying Game.
