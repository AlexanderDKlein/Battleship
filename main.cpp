#include "board.hpp"
#include <string>
#include <iostream>
#include <random>
#include <unistd.h>

/* Author: Alexander Klein
 * Date: 10/18/21
 * Assignment: Battleship
 */

//Checks if the placement of one boat will overlap with the placement of another.
int overlap(int x, int y, int s, int o, Board b) {
	if (o == 0) {
        for (int i = x; i < x + s; i++) {
            if (b.getVal(i, y) != '\0') {
				return 1;
			}
        }
    } else {
        for (int i = y; i < y + s; i++) {
            if (b.getVal(x, i) != '\0') {
                return 1;
            }
        }
    }
	return 0;
}

//Places a boat on the grid.
Board placeShip(int x, int y, int s, char sh, int o, Board b) {
	if (o == 0) {
		for (int i = x; i < x + s; i++) {
			b.setVal(i, y, sh);
		}
	} else {
		for (int i = y; i < y + s; i++) {
			b.setVal(x, i, sh);
		}
	}
	return b;
}

//Input error (invalid input).
void iE() {
	std::cout << "Invalid user input." << std::endl;
}

//Main function.
int main(int argc, char** argv) {
	//Declares important variables.
	Board player, computer;
	int input, input2, input3;
	int invalid = 1;

	//Sets the computer to a hidden board.
	computer.setHidden(1);

	//Prints out game intro.
	std::cout << "---------------BATTLESHIP---------------\n" << std::endl;

	std::cout << "In this game, you will be playing" << std::endl;
	std::cout << "Battleship against an AI. Good luck!" << std::endl;

	std::cout << "The pieces that will be used are:\n" << std::endl;
	std::cout << "\tCarrier     [5 spaces]" << std::endl;
	std::cout << "\tBattleship  [4 spaces]" << std::endl;
	std::cout << "\tDestroyer   [3 spaces]" << std::endl;
	std::cout << "\tSubmarine   [5 spaces]" << std::endl;
	std::cout << "\tPatrol Boat [5 spaces]\n" << std::endl;

	//Places player's Carrier.
	do {
		std::cout << "Where do you want to place the Carrier [5 spaces]?" << std::endl;
		std::cin >> input;
		std::cin >> input2;
		std::cout << "Horizontally or Vertically? (0 or 1)" << std::endl;
		std::cin >> input3;
		if (((input + 4 > 9 && input3 == 0) || (input2 > 9)) || ((input2 + 4 > 9 && input3 == 1) || input > 9)) {
			iE();
		} else if ((input3 != 1 && input3 != 0) || (input < 0 || input > 9 || input2 < 0 || input2 > 9)) {
			iE();
		} else {
			invalid = 0;
		}
	} while (invalid);
	invalid = 1;

    player = placeShip(input, input2, 5, 'C', input3, player);

	std::cout << player << std::endl;

	//Places player's Battleship.
	do {
        std::cout << "Where do you want to place the Battleship [4 spaces]?" << std::endl;
        std::cin >> input;
        std::cin >> input2;
        std::cout << "Horizontally or Vertically? (0 or 1)" << std::endl;
        std::cin >> input3;
        if (((input + 3 > 9 && input3 == 0) || (input2 > 9)) || ((input2 + 3 > 9 && input3 == 1) || input > 9)) {
            iE();
        } else if ((input3 != 1 && input3 != 0) || (input < 0 || input > 9 || input2 < 0 || input2 > 9)) {
            iE();
        } else if (overlap(input, input2, 4, input3, player)) {
			std::cout << "This causes ship overlap!" << std::endl;
		} else {
            invalid = 0;
        }
    } while (invalid);
    invalid = 1;

    player = placeShip(input, input2, 4, 'B', input3, player);

    std::cout << player << std::endl;

	//Places player's Destroyer.
	do {
        std::cout << "Where do you want to place the Destroyer [3 spaces]?" << std::endl;
        std::cin >> input;
        std::cin >> input2;
        std::cout << "Horizontally or Vertically? (0 or 1)" << std::endl;
        std::cin >> input3;
        if (((input + 2 > 9 && input3 == 0) || (input2 > 9)) || ((input2 + 2 > 9 && input3 == 1) || input > 9)) {
            iE();
        } else if ((input3 != 1 && input3 != 0) || (input < 0 || input > 9 || input2 < 0 || input2 > 9)) {
            iE();
        } else if (overlap(input, input2, 3, input3, player)) {
            std::cout << "This causes ship overlap!" << std::endl;
        } else {
            invalid = 0;
        }
    } while (invalid);
    invalid = 1;

    player = placeShip(input, input2, 3, 'D', input3, player);

    std::cout << player << std::endl;

	//Places player's Submarine.
	do {
        std::cout << "Where do you want to place the Submarine [3 spaces]?" << std::endl;
        std::cin >> input;
        std::cin >> input2;
        std::cout << "Horizontally or Vertically? (0 or 1)" << std::endl;
        std::cin >> input3;
        if (((input + 2 > 9 && input3 == 0) || (input2 > 9)) || ((input2 + 2 > 9 && input3 == 1) || input > 9)) {
            iE();
        } else if ((input3 != 1 && input3 != 0) || (input < 0 || input > 9 || input2 < 0 || input2 > 9)) {
            iE();
        } else if (overlap(input, input2, 3, input3, player)) {
            std::cout << "This causes ship overlap!" << std::endl;
        } else {
            invalid = 0;
        }
    } while (invalid);
    invalid = 1;

    player = placeShip(input, input2, 3, 'S', input3, player);

    std::cout << player << std::endl;

	//Places player's Patrol Boat.
	do {
        std::cout << "Where do you want to place the Patrol Boat [2 spaces]?" << std::endl;
        std::cin >> input;
        std::cin >> input2;
        std::cout << "Horizontally or Vertically? (0 or 1)" << std::endl;
        std::cin >> input3;
        if (((input + 1 > 9 && input3 == 0) || (input2 > 9)) || ((input2 + 1 > 9 && input3 == 1) || input > 9)) {
            iE();
        } else if ((input3 != 1 && input3 != 0) || (input < 0 || input > 9 || input2 < 0 || input2 > 9)) {
            iE();
        } else if (overlap(input, input2, 2, input3, player)) {
            std::cout << "This causes ship overlap!" << std::endl;
        } else {
            invalid = 0;
        }
    } while (invalid);
    invalid = 1;

    player = placeShip(input, input2, 2, 'P', input3, player);

    std::cout << player << std::endl;

    //Creates opponent's board.
    std::cout << "\nPlacing opponent's ships:" << std::endl;

    //Creates random generator.
    const int range_from  = 0;
    const int range_to    = 9;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    //Places computer's Carrier.
    do {
        input = distr(generator);
        input2 = distr(generator);
        input3 = (distr(generator) % 2);

        if ((input + 4 > 9 && input3 == 0) || (input2 + 4 > 9 && input3 == 1)) {
			iE();
		} else {
			invalid = 0;
		}
    } while (invalid);
    invalid = 1;

    computer = placeShip(input, input2, 5, 'C', input3, computer);

	std::cout << "Carrier Placed" << std::endl;

	//Places computer's Battleship.
	do {
        input = distr(generator);
        input2 = distr(generator);
        input3 = (distr(generator) % 2);

        if ((input + 3 > 9 && input3 == 0) || (input2 + 3 > 9 && input3 == 1)) {
			iE();
		} else if (overlap(input, input2, 4, input3, computer)) {
			std::cout << "This causes ship overlap!" << std::endl;
		} else {
			invalid = 0;
		}
    } while (invalid);
    invalid = 1;

    computer = placeShip(input, input2, 4, 'B', input3, computer);

	std::cout << "Battleship Placed" << std::endl;

	//Places computer's Destroyer.
	do {
        input = distr(generator);
        input2 = distr(generator);
        input3 = (distr(generator) % 2);

        if ((input + 2 > 9 && input3 == 0) || (input2 + 2 > 9 && input3 == 1)) {
			iE();
		} else if (overlap(input, input2, 3, input3, computer)) {
			std::cout << "This causes ship overlap!" << std::endl;
		} else {
			invalid = 0;
		}
    } while (invalid);
    invalid = 1;

    computer = placeShip(input, input2, 3, 'D', input3, computer);

	std::cout << "Destroyer Placed" << std::endl;

	//Places computer's Submarine.
	do {
        input = distr(generator);
        input2 = distr(generator);
        input3 = (distr(generator) % 2);

        if ((input + 2 > 9 && input3 == 0) || (input2 + 2 > 9 && input3 == 1)) {
			iE();
		} else if (overlap(input, input2, 3, input3, computer)) {
			std::cout << "This causes ship overlap!" << std::endl;
		} else {
			invalid = 0;
		}
    } while (invalid);
    invalid = 1;

    computer = placeShip(input, input2, 3, 'S', input3, computer);

	std::cout << "Submarine Placed" << std::endl;

	//Places computer's Patrol Boat.
	do {
        input = distr(generator);
        input2 = distr(generator);
        input3 = (distr(generator) % 2);

        if ((input + 1 > 9 && input3 == 0) || (input2 + 1 > 9 && input3 == 1)) {
			iE();
		} else if (overlap(input, input2, 2, input3, computer)) {
			std::cout << "This causes ship overlap!" << std::endl;
		} else {
			invalid = 0;
		}
    } while (invalid);
    invalid = 1;

    computer = placeShip(input, input2, 2, 'P', input3, computer);

	std::cout << "Patrol Boat Placed" << std::endl;

	std::cout << "All Computer Boats successfully placed!" << std::endl;

    //Plays the game.
    int pPoints = 17;
    int cPoints = 17;

    while (pPoints && cPoints) {
        //Prints the boards.
        player.setHidden(0);
        computer.setHidden(1);
        std::cout << player;
        std::cout << computer;

        //Outputs number of points and who is winning.
        std::cout << "Player Points: " << pPoints << "    Computer Points: " << cPoints << std::endl;

        if (pPoints > cPoints) {
            std::cout << "Player is winning!" << std::endl;
        } else if (cPoints > pPoints) {
            std::cout << "Computer is winning!" << std::endl;
        } else {
            std::cout << "Tie game!" << std::endl;
        }

        //Gets user's shot location.
        do {
            std::cout << "Where do you wish to attack?" << std::endl;
            std::cin >> input;
            std::cin >> input2;

            if (input < 0 || input > 9 || input2 < 0 || input2 > 9) {
                iE();
            } else if (computer.getVal(input, input2) == '-' || computer.getVal(input, input2) == '*') {
                std::cout << "You already shot there." << std::endl;
            } else {
                invalid = 0;
            }
        } while (invalid);
        invalid = 1;

        //Determines if shot is a hit or a miss.
        if (computer.getVal(input, input2) == '\0') {
            std::cout << "PLAYER MISS" << std::endl;
            computer.setVal(input, input2, '-');
        } else {
            std::cout << "PLAYER HIT" << std::endl;
            computer.setVal(input, input2, '*');
            cPoints--;
        }

        //Gets computer's shot location.
        do {
            input = distr(generator);
            input2 = distr(generator);

            if (player.getVal(input, input2) != '-' && player.getVal(input, input2) != '*') {
                invalid = 0;
            }
        } while (invalid);
        invalid = 1;

        std::cout << input << std::endl;
        std::cout << input2 << std::endl;

        //Determines if shot is a hit or a miss.
        if (player.getVal(input, input2) == '\0') {
            std::cout << "COMPUTER MISS" << std::endl;
            player.setVal(input, input2, '-');
        } else {
            std::cout << "COMPUTER HIT" << std::endl;
            player.setVal(input, input2, '*');
            pPoints--;
        }
    }
    //Makes both boards unhidden.
    player.setHidden(0);
    computer.setHidden(0);

    std::cout << player;
    std::cout << computer;

    //Outputs who wins.
    if (cPoints == 0 && pPoints == 0) {
        std::cout << "\nTIE GAME\nYou both fought well! :)\n" << std::endl;
    } else if (cPoints == 0) {
        std::cout << "\nPLAYER WINS\nGood job! :)\n" << std::endl;
    } else if (pPoints == 0) {
        std::cout << "\nCOMPUTER WINS\nBetter luck next time... :(\n" << std::endl;
    }

	return 0;
}
