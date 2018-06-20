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
In the beginning, the project seemed to be in trouble of not covering any topics that were discusses in PIC10C. Now, upon completion, the project touches upon the following topic in PIC10C: 

1. Nested classes and iterators: While the CPU_Opponent class is not an iterator as you'd expect in a typical STL, this is expected as the Nim class isn't an STL either. Regardless, CPU_Opponent does share a strong resemblance with a typical iterator, with its ability to traverse its parent and affect changes upon it. The CPU_Opponent class was created by nesting it inside the Nim class, another topic we covered in class. 

2. Generic Algorithms, Numeric Algorithms, and Lambda Functions: Several standard algorithms such as accumulate, for_each, copy etc was used in this project to help simplify tedious tasks. There was also the use of lambda functions in order to speed up coding instead of defining a seperate function elsewhere. All of these topics were also covered in PIC10C. 

3. Function pointers: Function pointers were mainly used to implement the UI of the game, as it was a handy tool that helped code the reactions to the player's interaction with the UI. 

4. Other: We also used memory management (albeit basic memory management) when we allocate memory for objects of the Nim class. We also use concepts of rand(), system("CLS"), etc. 

#THE DOCUMENTATION: 

1. Have been playing with various template styles for the class Nim (each instance of the class Nim will be a game). Have finally settled on the template style, and thus the barebones of the game and its sub-class. Began this readme. 

2. Created a function that allows the CPU_opponent to calculate the nim sum of its parent game. Needless to say, this is crucial to the working of the algorithm and the game. 

3. Have created functions that allow the user (and CPU) to actually make moves, and see their moves reflected in the game. I also added functions that would help the CPU determine what move to make, based on its difficulty setting and the Nim solving algorithm. Finally, I also updated the "UI" of the game.

4. The program seems to be working fine right now. No bugs as far as I can see. Will polish the UI and player experience next. 

5. Removed some of the bloat of the programming by removing an unecessary "intermediary" in the move making process. This also removed a few corner case bugs I saw. Improved the UI a bit. The project is pretty much ready to be graded. Might still make some changes later. 