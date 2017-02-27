#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"


using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */


// Function 1: Function for testing if all positions are occubied by digits

bool is_complete (const char board [9][9]){

  
  for (int row =0; row<9; row++)
    {
     
      for(int column =0; column <9; column++)
      {
	
       	while (!((board [row][column] >='1') && (board [row][column] <='9')))
	  
	{
	   return false;
	}
	
      }
    }
  return true;
}


// Function 2
bool make_move (const char position [2],const char digit, char board [9][9]){

  int row_num_inp = position[0]-'A';
  int col_num_inp = position[1]-'1';         //This is for getting the number

  int row_section;
  int column_section;

  
  //checking boundaries 
  if (! ((row_num_inp >= 0) && (row_num_inp < 9)) && ((col_num_inp >=0) && (col_num_inp < 9)) )
    return false;
  
  //checking if not occupied by number
  if ((board [row_num_inp][col_num_inp]) != '.')
     return false;
   
   //checking columns for same namber
   for(int col_num=0;col_num <9; col_num++)
    {
      if(board[row_num_inp][col_num] == digit)
	return false;
    }
  
  
  //checking rows for same number
  for(int row_num=0;row_num <9; row_num++)
    {
      if(board[row_num][col_num_inp] == digit)
	return false;
    }
  
  //seperating the board into 9 sections to check loop containing the digit if it is repeated
  row_section= ((row_num_inp)/3)*3;
  column_section= ((col_num_inp)/3)*3;
  
  for (int i=row_section; i <= row_section+2; i++)
    {
      for (int k=column_section; k <= column_section+2;k++)
	{
	  if(board[i][k] == digit)
	    {
	      return false;
	      
	    }
	  
	}
      
    }
  
  board[row_num_inp][col_num_inp]=digit;
  return true;
}

//Function 3:

bool save_board (const char* filename, const char board [9][9]){

  ofstream out_stream(filename);


  if(out_stream.fail())
         return false;
    
  
  else
    {
       for (int row=0;row<9;row++)
	 {
	  for (int col=0;col <9; col++)
	    {
	      
	      out_stream << board[row][col]; 
	      
	    }
	  out_stream << endl;
	}
     
      out_stream.close();
      return true;
    }
}

//Function 4 attempts to solve and retrun the solution.

  /*
    Psuedocode: 
    find the next empty space
    if the digit is existing 
    for all digits from 1 to 9 are correct
    copy to array
    recall function
    base case would be if is_complete 
  
   */


bool solve_board (char board [9][9])
{

  char array_position [2];
  int row_pos,col_pos;
  // static int counter=0;            //static means it is executed just once

  //  counter++;
    
  if (is_complete(board))
    {
      //  cout << counter << endl;
      // counter =0;
      return true;
    }
  else
    {
      
      if(next_empty_position(board,row_pos,col_pos))
	{
	  array_position[0]=row_pos + 'A';
	  array_position[1]=col_pos + '1';
	  
	  
      	  for(char digit = '1'; digit <= '9'; digit++)
	    {
	      
	      if (make_move(array_position,digit,board))
		{
		  
		  if(solve_board(board))
		    return true;
		  
		  else
		    board[row_pos][col_pos] = '.';	  
		}
	    }
	} 
    }     
  return false;
}


bool next_empty_position(const char board[9][9], int& row, int& col)
{
  for (row=0; row < 9; row++)
    {
      for(col=0; col<9; col++)
	{
	 if (board[row][col] == '.')
	   return true;
	}
    }
  
  return false;	    
}


