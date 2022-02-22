#include "board.hpp"
#include <iostream>

/* Author: Alexander Klein
 * Date: 10/18/21
 * Assignment: Battleship
 */

//Initializes default board.
Board::Board() {
}

//Gets the value of the board at x and y.
char Board::getVal(int x, int y) const {
	return grid[x][y];
}

//Sets the value of the board at x and y to the desired character.
void Board::setVal(int x, int y, char val) {
	this->grid[x][y] = val;
}

//Sets the 'hidden' value of the board.
void Board::setHidden(int h) {
    this->hidden = h;
}

//Prints the board.
std::ostream& operator<< (std::ostream& out, const Board& board) {
    out << "   0 1 2 3 4 5 6 7 8 9\n______________________\n";
    for (int i = 0; i < 10; i++) {
        out << i << "|";
        for (int j = 0; j < 10; j++) {
            out << " ";
            if (board.hidden) {
                if (board.getVal(j, i) != '-' && board.getVal(j, i) != '*') {
                    out << " ";
                } else {
                    out << board.getVal(j, i);
                }
            } else {
                if (board.getVal(j, i) == '\0') {
                    out << " ";
                } else {
                    out << board.getVal(j, i);
                }
            }
        }
        out << "\n";
    }
    out << "\n";
    return out;
}
