/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1test.cpp

On linux:
g++ ninetynine1.cpp ninetynine1test.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test ninetynine1 object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine1.h"

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
#ifdef _WIN32
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  ninetynine1 a;
  a.run();
}

/*----------------------------------------------------------------
main
ninetnine
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}

//EOF

