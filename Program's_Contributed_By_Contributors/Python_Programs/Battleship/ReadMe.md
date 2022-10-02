# BattleShip
A Python based implementation of BattleShip, a turn-based two-player game that simulates a war between ships on an ocean.
Each player gets their own battle area with a certain number of ships placed in non-overlapping positions. The
ships might be of different sizes. 

Note, players cannot see each others ship's location.

## Running the game

To run the given test data
```
Python Gameplay.py
```
To run using input file
```
Python Gameplay.py "C:/testdata/testdata.txt"
```
### Given Constraints
* 1 <= Width of Battle area (M’) <= 9,
* A <= Height of Battle area (N’) <= Z
* 1 <= Number of battleships <= M’ * N’
* Type of ship = {‘P’, ‘Q’}
* 1 <= Width of battleship <= M’
* A <= Height of battleship <= N’
* 1 <= X coordinate of ship <= M’
* A <= Y coordinate of ship <= N’


### Code Structure

```
BattleArea.py:  model class for the Battle Area
Gameplay.py:    start script, conatins logic to initalise and initiate the game
Player.py:      model class for each player, each player has its own battle area, ships and moves
Ship.py:        model class for ship
Utilities.py:   common utilities for the project
/testdata:      contains sample test data
/tests:         unittests
/outputs:       output for sample test data
/htmlcov        coverage report, open index.html in browser
```

## Running the tests
Unittests are available under tests folder | Coverage 96%

```
coverage run -m unittest discover
coverage report -m
covergae html
```


## Built With

* [Python 3.6](https://www.python.org/downloads/release/python-360/) 


