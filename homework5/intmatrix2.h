/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "../util/util.h"
#include <string.h>

/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //WRITE CODE.
  //CANNOT DECLARE ANY GLOBAL VARIABLE
  intmatrix2(const int r = 0, const int c = 0, const int v = 0);
  intmatrix2(const char* s);
  intmatrix2(const intmatrix2& obj);
  ~intmatrix2();
  friend ostream& operator<<(ostream& o, const intmatrix2& obj);
  intmatrix2& operator=(const intmatrix2& obj);
  bool operator!();
  intmatrix2 add(const intmatrix2& obj);
  intmatrix2 mult(const intmatrix2& obj);
  bool isEqual(const intmatrix2& obj);
  //USE this as is. I will explain when I show
  static void makeShowOn() {_show = true;}
  static void makeShowOff() {_show = false;}
  static bool show() {return _show ;} 
private:
  static bool _show ; //MUST USE THIS
  //WRITE CODE BELOW
  //use xxx_ so that we know all variables are private
  int** _matrix = nullptr;
  int _r = 0;
  int _c = 0;
  void _release();
  void _reconstruct(const int& r, const int& c, int v = 0);
  void _reconstructFromStr(const char* s);
  void _copy(const intmatrix2& obj);
};




//EOF

