## Requirements:

- main.cpp -> where the players will be created and the game will be started.
- gameFactory -> which will create the game instance as per the rule stated('STANDARD', 'CUSTOM')
- game:

  - Instantiate Board inside the game()
  - deque<Player\*>
  - Add players
  - Remove Players
  - Instantiate rules inside the game()
  - isGameOver -> boolean variable which will be responsible for the end game logic
  - logic for game starting:
    - value of dice (It will be a random value generated from the random function)
    - Check for the updated score with the help of the rules class -> does the player won/ is it a head of a snake/ is it a tail of a leader
    - Print the result
    - Update the player's position

- Player -> it will have name, getScore, incrementScore, getName
- GameType -> 'STANDARD'
- Board
  - A map of snake and ladder's positions, [start, end]
  - getCell -> returns the cell's value, either it is a plane cell, or has a snake, or has a ladder

## Class Strutures

- 2 interfaces:
  - Rules Interface -> concrete class (StandardRules)
