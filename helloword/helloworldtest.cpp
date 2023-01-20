/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: helloworldtest.cpp

On linux:
g++ helloworld.cpp helloworldtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test helloworld object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "helloworld.h"

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
  helloworld a ;
  a.welcome() ;
  helloworld b ;
  b.welcome() ;
}


/*----------------------------------------------------------------
main
helloworld
-----------------------------------------------------------------*/
int main() { //mainHelloworld
#ifdef _WIN32
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  testbed() ;
  return 0 ;
}

//EOF

