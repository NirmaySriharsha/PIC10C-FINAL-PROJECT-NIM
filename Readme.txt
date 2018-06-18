S. Nirmay, 
004771797, 
June 2018. 

														PIC 10C Final Project: The Game of Nim!
	A quick overview over the game of Nim, the coding that went behind this project, and the documentation of the creation of the project. 
#THE MATH: 

Nim is a relatively simple math game. For info on the rules and how to play, see: https://www.geeksforgeeks.org/combinatorial-game-theory-set-2-game-nim/

Note that there are other versions of Nim where the player who takes the last token loses (called reverse-nim), or versions where there is a cap on the number of tokens you can remove, etc. We will be playing the standard version of Nim here. 

The game itself is relatively simple, but is fascinating (mathematically speaking) as it is a perfect introduction into the field of Mathematical Game Theory. The game is said to be "Solvable", meaning that we can derive an algorithm that will allow the user to win any game (with one caveat: if both players use this algorithm, then the player who goes second will always win. See the link provided above for more details on the mathematics behind the algorithm). 

The mathematics of the game is of course not relevant to this project, so here's the quick and dirty: 

1. Convert every row into binary based on the number of counters on the row. 
2. Define a sum called the "Nim Sum". A nim sum is the XOR addition of all the (binary) values of the rows. 
3. The Player/CPU's goal is to always make a move such that the move will result in a new Nim Sum of 0. 

This "algorithm" will ensure victory.  


#THE CODING:

#THE DOCUMENTATION: 

1. Have been playing with various template styles for the class Nim (each instance of the class Nim will be a game). Have finally settled on the template style, and thus the barebones of the game and its sub-class. Began this readme. 

2. Created a function that allows the CPU_opponent to calculate the nim sum of its parent game. Needless to say, this is crucial to the working of the algorithm and the game. 