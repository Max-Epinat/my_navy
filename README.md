# My_navy

This project is a recreation of the very famous Battleship game
The game consist of a 8X8 board and is initially ran using a file as argument with the coordinates of the boats on the board

Example of the content of a file:
  
> 2:D1:D2
> 
> 3:A1:A3
>
> 4:B3:E3
>
> 5:C5:G5

These represents the positions of the ships, with sizes of 2, 3, 4 and 5

## Compilation

> Make

## Usage

To play, you have to open two terminals. The two will connect with each other by sending the PID of the first one to the second as argument.

First player:

```bash
./my_navy [map1]
```

Second player:

```bash
./my_navy [PID of the first terminal] [map2]
```

If you do an out-of-range attack or attack at a place you have already attacked, you will lose the turn. The game will end whenever all of the ships of any of the players have been defeated.
