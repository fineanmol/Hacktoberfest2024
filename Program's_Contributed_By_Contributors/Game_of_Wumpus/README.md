# A game of Wumpus
[Hunt the Wumpus](https://en.wikipedia.org/wiki/Hunt_the_Wumpus)

This game was coded as an exercise, I wanted to add some kind of basic AI to the Wumpus to chase the player, it would 
be a great improvement if someone want to do it. 

* The hunter (player) perceives:
  * If it is in the same cell as the Wumpus
  * A breeze in adjacent cells to pits 
  * Wumpus odor if its in adjacent cells to it 
  * A shining if is located in the same cell as the gold 
  * When a wall is hit 
  * A yell if kills the Wumpus
* Actions
  * Move forward
  * Turn 90º to the left or right
  * Shoot an arrow (flight until Wumpus or a wall is hit)
  * Exit the map if is on the exit cell

In order to execute the game use the following command:
```
python3.7 main.py [-h] [--debug] cols rows pits arrows 

positional arguments:
  cols        Number of columns for the board game
  rows        Number of rows for the board game
  pits        How many pits should be
  arrows      How many arrows have the player

optional arguments:
  -h, --help  show this help message and exit
  --debug     Enambles debug mode
```

The commands to control the character are (does mather if upper or lower case:

* move | move forward | move forwards
* turn left | left turn
* turn right | right turn
* shoot | shoot arrow | throw arrow
* exit | exit board | exit game | go outside

If debug mode is enabled, the board is drawn in ASCII, with a character which symbolise the information contained in that cell  (due to obvious reasons, if a cell contains more tha one thing, only the most relevant is shown).
```
  Legend:
  * P -> Player
  * W -> Wumpus
  * G -> Gold
  * O -> Pit 
  * w -> Wall
  * o -> Wumpus odor
  * b -> Breeze
```
Also is shown where the player is looking and how many arrows have.


