/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: iset64.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has iset64 class declaration 
-----------------------------------------------------------------*/

#pragma once

/*----------------------------------------------------------------
All includes here. 

YOU CANNOT ADD ANY LIBRARY COMMENTED BELOW

If you think, you require any of the library brlow means you have no clue
of data structures and algorithm


#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <string.h> //for strlen,strcat and strcpy on linux
#endif

/*----------------------------------------------------------------
Declaration of iset64 class
-----------------------------------------------------------------*/
class iset64{
public:
  static const int N = 64;
  static void set_display(bool b) {display = b; }
  iset64(const unsigned long long& _d = 0);
  iset64(const int& i);
  iset64(const int* arr, const int& len);
  iset64(const iset64& obj);
  ~iset64();

  friend ostream& operator <<(ostream& o, const iset64& obj);
  friend iset64& operator+(iset64& obj, const int& i);
  friend iset64& operator-(iset64& obj, const int& i);
  friend iset64& operator+(const int& i, iset64& obj);
  friend iset64& operator-(const int& i, iset64& obj);
  friend iset64& operator+=(iset64& obj, const int i);
  friend iset64& operator-=(iset64& obj, const int i);
  friend bool operator==(const iset64& a, const iset64& b);
  friend bool operator!=(const iset64& a, const iset64& b);
  void operator+=(const iset64& obj);
  void operator-=(const iset64& obj);
  iset64& operator=(const iset64& obj);
  iset64 operator+(const iset64& obj);
  iset64 operator-(const iset64& obj);
  iset64 operator++();
  iset64 operator--();
  iset64 operator++(int);
  iset64 operator--(int);
  iset64 operator~();

private:
  static bool display;
  static unsigned long long _generateBitMask(const int& i);
  unsigned long long _digit;
  
};




//EOF

