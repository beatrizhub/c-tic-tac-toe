# Txc Tac Toe
This is a simple Command Line Interface Tic Tac Toe game implemented in C, where the player can play against an artificial intelligence. Every time the game ends, an ASCII art will be displayed.
```
██████████╗  ██╗██████╗    ████████╗█████╗ ██████╗    ████████╗██████╗███████╗
╚══██╔══╚██╗██╔██╔════╝    ╚══██╔══██╔══████╔════╝    ╚══██╔══██╔═══████╔════╝
   ██║   ╚███╔╝██║            ██║  █████████║            ██║  ██║   ███████╗  
   ██║   ██╔██╗██║            ██║  ██╔══████║            ██║  ██║   ████╔══╝  
   ██║  ██╔╝ ██╚██████╗       ██║  ██║  ██╚██████╗       ██║  ╚██████╔███████╗
   ╚═╝  ╚═╝  ╚═╝╚═════╝       ╚═╝  ╚═╝  ╚═╝╚═════╝       ╚═╝   ╚═════╝╚══════╝
```

## Installation
To run this program, you need to have a C compiler installed on your system, such as GCC or Clang. You can install these compilers using your package manager or download them from their official websites.

To get started with the program, you need to first clone or download the repository. You can do this by clicking on the "Code" button at the top of the repository page and selecting "Download ZIP" to download a compressed file of the repository, or copy the repository URL and run the following command in your terminal:
```
git clone https://github.com/beatrizhub/c-tic-tac-toe
```

Once you have a C compiler installed and cloned this repository, move into the program's directory and compile the tictactoe.c file using one of the following commands:

### GCC
```
gcc -o tictactoe tictactoe.c
```

### Clang
```
clang -o tictactoe tictactoe.c
```

This will generate an executable file called tictactoe in the current directory.

## Usage
To start the game, run the tictactoe executable from the command line:
```
./tictactoe
```

You will be prompted to press enter to start the game and then choose your symbol (X or O). To choose your symbol, simply type in 'X' or 'O' and press enter. The computer will automatically be assigned the other symbol.

When the game starts, enter the row (A, B or C) and then the column (1, 2, or 3) of the cell where you want to place your marker (X or O). After each move, the game board will be displayed, and the AI will make its move.

The game continues until there's a tie or either the player or the AI wins.

At the end of the game, an ASCII art will be displayed:

- If the player wins, the following ASCII art will be displayed:
```
██╗   ████╗██████████████╗██████╗██████╗██╗   ██╗
██║   ██████╔════╚══██╔══██╔═══████╔══██╚██╗ ██╔╝
██║   ██████║       ██║  ██║   ████████╔╝╚████╔╝ 
╚██╗ ██╔████║       ██║  ██║   ████╔══██╗ ╚██╔╝  
 ╚████╔╝██╚██████╗  ██║  ╚██████╔██║  ██║  ██║   
  ╚═══╝ ╚═╝╚═════╝  ╚═╝   ╚═════╝╚═╝  ╚═╝  ╚═╝   
```

- If the AI wins, the following ASCII art will be displayed:
```
██████╗█████████████████████╗█████╗████████╗
██╔══████╔════██╔════██╔════██╔══██╚══██╔══╝
██║  ███████╗ █████╗ █████╗ ███████║  ██║   
██║  ████╔══╝ ██╔══╝ ██╔══╝ ██╔══██║  ██║   
██████╔█████████║    █████████║  ██║  ██║   
╚═════╝╚══════╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝   
```

- If the game ends in a tie, the following ASCII art will be displayed:
```
█████████████████╗
╚══██╔══████╔════╝
   ██║  ███████╗  
   ██║  ████╔══╝  
   ██║  █████████╗
   ╚═╝  ╚═╚══════╝
```

Afterwards, you will be prompted for a rematch. Simply type 'Y' and enter for restarting the game, keeping the scores or, type 'N' and enter for ending the game, which will display the following ASCII art:
```
 ██████╗ █████╗███╗   ██████████╗     ██████╗██╗   ███████████████╗
██╔════╝██╔══██████╗ ██████╔════╝    ██╔═══████║   ████╔════██╔══██╗
██║  ████████████╔████╔███████╗      ██║   ████║   ███████╗ ██████╔╝
██║   ████╔══████║╚██╔╝████╔══╝      ██║   ██╚██╗ ██╔██╔══╝ ██╔══██╗
╚██████╔██║  ████║ ╚═╝ █████████╗    ╚██████╔╝╚████╔╝█████████║  ██║
 ╚═════╝╚═╝  ╚═╚═╝     ╚═╚══════╝     ╚═════╝  ╚═══╝ ╚══════╚═╝  ╚═╝
```

## Algorithm
The AI in this program uses uses a simple strategy to select its moves. It first checks for any winning move by iterating through all the empty cells on the board and placing the computer's symbol in each one. If a move results in a win, the function immediately returns and the move is made.

If there is no winning move available, the function checks for a blocking move. It iterates through all the empty cells on the board again and places the player's symbol in each one. If a move results in blocking the player from winning, the computer places its symbol in that cell and returns, making the move.

If neither a winning nor a blocking move is available, the function makes a random move. It generates a random row and column until an empty cell is found, and then places the computer's symbol in that cell.

Overall, this function prioritizes winning over blocking the player's moves, and random moves are made only when no winning or blocking moves are available.

## Credits
This program was created by Beatriz Rodrigues.

ASCII art created with [TAAG](https://patorjk.com/software/taag/)

## License
This program is licensed under the MIT License. Feel free to use and modify this program for your own purposes.
