#include <iostream>
#include <cstdio>
#include "sudoku.h"
#include <ctime>

using namespace std;

int main() {

  char board[9][9];
  
  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  
  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  
  load_board("easy.dat", board);
  
  // Should be false
  
  cout << "Putting '2' into A2 is ";
  if (!make_move("A2", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  
  load_board("easy.dat", board);
  
  // Should be false
  
  cout << "Putting '9' into D8 is ";
  if (!make_move("D8", '9', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  




  
  // write more tests
  
  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;
  
  
  cout << "====================== Question 4 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;


  //This tests what happens if there is a char in it
  /*
   load_board("test1_char.dat", board);
  if (solve_board(board)) {
    cout << "The 'test1_char' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  This resulted in a load_board exit, since the load function was a char and the assert isdigit in 
  the function stoped the function from conitnuing.


  */  
	// write more tests

  cout << "====================== Question 5 ======================" << endl << endl;
  //clock_t begin=clock();
  load_board("mystery1.dat", board);

  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  
  
  //clock_t end=clock();
  //cout<< "Clock Time: "<<(end-begin)<<endl<< endl;  //This will allow me to time each function to see how long the solution took


  //begin=clock();

   load_board("mystery2.dat", board);
   if (solve_board(board)) {
     cout << "The 'mystery2' board has a solution:" << endl;
     display_board(board);
   } else 
     cout << "A solution cannot be found." << endl;
   cout << endl;
   
   //end=clock();
   //cout<<"Clock Time: "<<(end-begin)<<endl<<endl;


   //begin=clock();

   load_board("mystery3.dat", board);
   if (solve_board(board)) {
     cout << "The 'mystery3' board has a solution:" << endl;
     display_board(board);
   } else 
     cout << "A solution cannot be found." << endl;
   cout << endl;

   //end=clock();
   //cout<<"Clock Time: " << (end-begin) << endl << endl;
  
	// write more tests
	
  return 0;
}
