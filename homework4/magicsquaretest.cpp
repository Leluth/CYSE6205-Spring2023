/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquaretest.cpp

On linux:
g++ magicsquare.cpp magicsquaretest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test magicsquare object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { 
#ifdef _WIN32
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  for (int i = 3; i < 100; i+=2) {
    magicsquare a;
    a.print_magic_square(i);
  }
  return 0;
}

//EOF

