# CPPND Capstone Project Submission: Snake Game with extra food type

* Short Description
    For my Capstone Project submission, I have chosen to add extra features to the original Snake game code provided by Udacity. At random intervals of time, the game spawns in a "Super food" instead of the normal one, eating which gives y ou extra points. The "Super food" is spawned using a random number generator and rendered with a different colour. The project was completed using the a combination of the different concepts studied during the C++ Nano degree. Two new classes have been declared namely, "Food" class in a separat file "food.h" and "Player" class that is declared in the "snake.h" file that inherits publicly from the "Snake" class. The "Food" class handles the types of food being placed in the game and "Player" allows for the player to input a player name.

* Fulfilled rubric criteria
    1. Loops, Functions, I/O
    *  The project demonstrates an understanding of C++ functions and control structures.(DONE) : 
       The game member function "Update()" & "Placefood()" has been modified appropriately to handle the new features.
       The "PlaceFood()" function now ocaasionally places a "Super food" in the game that gives extra points for eating it. The "Update()" function now can recognise which food has been eaten and adds the appropriate number of points to the game score.
    *  The project accepts user input and processes the input.(DONE) :
       The game accepts the player name as user input to display on the console in the main function. The console is also updated evertime a new food is eaten displaying the foodtype along with the player name.
    
    2. Object Oriented Programming
    *  The project uses Object Oriented Programming techniques.(DONE) :
       Two new classes have been added to the game code. The "Food" class defines the types of food placed in the game. The Food class defines the Value, Colour and Type of food being placed. The "Player" class inherits from the snake class and allows for the user to give snake a player name which is later displayed in the console.
    *  Classes use appropriate access specifiers for class members.(DONE) :
       The members functions and data members of the two new classes are clearly specified as public & private.
    *  Class constructors utilize member initialization lists.(DONE) : 
       The class constructors of the new classes uses initialization lists to initialize the data members of the classes.
    
    3. Memory Management
    *  The project uses move semantics to move data, instead of copying it, where possible.(DONE) :
       The mutator method "SetColour()" of the Food Class uses move semantics to move a vector of int (containing the rdg values for the render colour) instead of passing a vector by value to avoid unecessary copies.



<img src="snake_game.gif"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
