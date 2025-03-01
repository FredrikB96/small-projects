The project aims to build a Tic-Tac-Toe game using bitwise operations to efficiently manage the board state and determine winners.

Requierment:
  - Board needs to displayed like this:
    1 | 2 | 3
    4 | 5 | 6
    7 | 8 | 9

  - Bitwise operations to handle moves per player.
  - GUI should utilize the console imput.
  - Use atleast one lamda


Implementation plan:
Since we need 9 bits to display the full board we will need to make use of uint16_t.
  however since a bit can only be 1 or 0 we will need to have one board per player.

To make the systems independet we will split up the tasks into one file for the game loop, another for the GUI and User Input, then lastly one for the game loop.

GUIConsole.cpp explanations:

bitwisetictactoe.cpp explanations:

GameLogic.cpp explanations:

One bitmask (uint16_t) for Player X and another for Player O.
Use one file to handle GUI, one file for game loop and one for game logic.

