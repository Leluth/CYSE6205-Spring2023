/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*-----------------------------------------------------
YOU MUST USE ONLY FILE BELOW
NOTHING CAN BE CHANGED
-----------------------------------------------------------------*/
#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of magicsquare class
-----------------------------------------------------------------*/
class magicsquare{
private:
  //YOU CANNOT ADD ANY DATA MEMBERS like matrix, int n etc
  //Because I want you to learn: can you pass parameters to other functions correctly?
  //Write as many small functions as possible 
  // 1. Allocate 2. Init 3 Alg 4. Verify 5. Print 
  //Note YOU CANNOT WRITE ANY DATA MEMBERS BELOW
  //MUST USE ONLY STL to solve this problem
  //WRITE CODE BELOW
  void allocate(const int n, vector<vector<int>> &matrix);
  void init(const int n, vector<vector<int>> &matrix);
  void magic_square(const int n, vector<vector<int>> &matrix);
  bool verify(const int n, vector<vector<int>> &matrix);
  void print(const int n, vector<vector<int>> &matrix);
public:
  //Cannot add anythig nere
  //0 marks will be given if you write all code only in this function
  //Write as many small functions as possible to implement print_magic_square
  void print_magic_square(int n);
};

//EOF

