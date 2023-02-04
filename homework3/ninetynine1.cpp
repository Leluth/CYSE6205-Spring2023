/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: ninetynine1.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine1 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine1.h"
/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety
b = one
(90)
c = Ninety
d = ""
*----------------------------------------------------------------*/
void ninetynine1::_print(const char* a, const char* b, bool b1, const char*  c, const char* d, bool b2) {
  //NOTHING CAN BE CHANGED
  const char* bot = bottle[b1];
  cout << a << " " << b << " " << bot << " of beer on the wall," << endl;
  cout << a << " " << b << " " << bot << " of beer," << endl;
  cout << "Take one down, pass it around," << endl;
  bot = bottle[b2];
  cout << c << " " << d << " " << bot << " of beer on the wall," << endl;
  cout << endl;
}


/*----------------------------------------------------------------
compute strings using Reference
*----------------------------------------------------------------*/
void ninetynine1::_stanzaReference(int n) {
  /* WRITE CODE */
  const char *a = nullptr;
  const char *b = nullptr;
  const char *c = nullptr;
  const char *d = nullptr;
  bool b1 = _compute_string(n, a, b);
  bool b2 = _compute_string(n - 1, c, d);

  _print(a, b, b1, c, d, b2);
}

bool ninetynine1::_compute_string(int n, const char *&a, const char *&b) {
  if (n <= 20) {
    a = numbers[n];
    b = "";
  } else {
    int x = n / 10;
    int y = n % 10;
    a = numbers[18 + x];
    b = y? numbers[y]: "";
  }

  return n != 1;
}

/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine1::_stanzaPointer(int n) {
  /* WRITE CODE */
  const char *a = nullptr;
  const char *b = nullptr;
  const char *c = nullptr;
  const char *d = nullptr;
  bool b1 = _compute_string(n, &a, &b);
  bool b2 = _compute_string(n - 1, &c, &d);
 
  _print(a, b, b1, c, d, b2);
}

bool ninetynine1::_compute_string(int n, const char **a, const char **b) {
  if (n <= 20) {
    *a = numbers[n];
    *b = "";
  } else {
    int x = n / 10;
    int y = n % 10;
    *a = numbers[18 + x];
    *b = y? numbers[y]: "";
  } 

  return n != 1;
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine1::run() {
  cout << "Reference based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaReference(i);
  }
  cout << "Pointer based song\n";
  for (int i = MAX; i > 0; --i) {
    _stanzaPointer(i);
  }
}

//EOF


