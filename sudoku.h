// This is the "HEADERFILE FOR THE MAIN SUDOKU FILE

//Author: Simon Charalambous
//Last Changed: 20th of October


#ifndef SUDOKU_H
#define SUDOKU_H

//Here we can insert the variable constants if required


//Function to create the sudoku board
void load_board(const char* filename, char board[9][9]);

//Function to display the board 
void display_board(const char board[9][9]);

//Function for checking if all board positions are occupied by digits.
bool is_complete(const char board [9][9]);

//Function which checks if the proposed move is legal
bool make_move(const char position [2],const char digit, char board [9][9]);

/*Function which outputs the board to a file with a name. 
This will retrun true if the board was successfully written.
*/
bool save_board(const char* filename, const char board [9][9]);


//Function which attempts to solve the sudoku and display the board.
bool solve_board (char board[9][9]);

//Function that finds the next empty field and returns the row and col by reference.
bool next_empty_position(const char board[9][9], int& row, int& col);  



#endif
