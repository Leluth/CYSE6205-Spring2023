/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: iset64test.cpp

On linux:
g++ iset64.cpp iset64test.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test iset64 object. YOU CANNOT TOYCH THIS FILE
DO NOT UPLOAD THIS FILE TO CANVAS. WE will use this to test
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "iset64.h"

/*----------------------------------------------------------------
test a set
-----------------------------------------------------------------*/
static void test_basic() {
  iset64 a;
  cout << "a = " << a << endl;
  a = a + 5;
  cout << "set a after adding 5 = " << a << endl;
  a += 5;
  cout << "set a after adding 5 = " << a << endl;
  a += 63;
  a += 0;
  cout << "set a after adding 0 and 63 = " << a << endl;
  int x[] = { 1, 3, 6 };
  iset64 b(x, sizeof(x) / sizeof(int));
  cout << "set b = " << b << endl;
  b = b - 3;
  cout << "set b after removing 3 = " << b << endl;
  b -= 3;
  cout << "set b after removing 3 = " << b << endl;
  b = b - 10;
  cout << "set b after removing 10 = " << b << endl;
  b -= 6;
  cout << "set b after removing 6 = " << b << endl;
  b = b - 1;
  cout << "set b after removing 1 = " << b << endl;
  b = b + 10;
  b = b + 2;
  cout << "set b after adding {10,2} = " << b << endl;
  {
    const int N = 5 ;
    iset64 *a = new iset64[N] ;
    iset64 t;
    t = t + 0 + 1 + 62 ;
    a[0] = a[1] = a[2] = a[3] = a[4] = t ;
    for (int i = 0; i < N; ++i) {
      cout << "a[" << i << "]=" << a[i] << endl ;
    }
    delete [] a ;
  }
}

/*----------------------------------------------------------------
test union
-----------------------------------------------------------------*/
static void test_union() {
  {
    cout << "TESTING: iset64 operator+(const iset64& a, const iset64& b)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    iset64 b;
    b += 1;
    b += 2;
    b += 3;
    cout << "Set a " << a << endl;
    cout << "Set b " << b << endl;
    iset64 c = a + b;
    cout << "a + b = " << c << endl;
  }
  {
    cout << "TESTING:iset64 operator+(const iset64& a, const int b)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    cout << a << endl;
    a = a + 1;
    cout << "{1,2} + 1 = " << a << endl;
    a += 1;
    a += 2;
    cout << a << endl;
    a = a + 3;
    cout << "{1,2} + 3 = " << a << endl;
  }
  {
    cout << "TESTING:iset64 operator+(const int b, const iset64& a)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    cout << "Set a " << a << endl;
    a = 1 + a;
    cout << " 1 + {1,2} = " << a << endl;
    a += 1;
    a += 2;
    cout << "Set a " << a << endl;
    a = 3 + a;
    cout << " 3 + {1,2}  = " << a << endl;
  }

  {
    cout << "TESTING:iset64& iset64::operator+=(const iset64& a)" << endl;
    iset64  b;
    b += 1;
    b += 2;
    iset64 a;
    a += 1;
    a += 3;
    cout << "Set b " << b << endl;
    cout << "Set a " << a << endl;
    b += a;
    cout << " {1,2} + {1,3}  = " << b << endl;
  }
  {
    cout << "iset64& iset64::operator+=(const int b)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    cout << "Set a " << a << endl;
    a += 3;
    cout << " {1,2} + 3  = " << a << endl;
  }
  {
    //test chaining
    iset64 a;
    a += 1;
    a += 2;
    iset64 b;
    b += 3;
    b += 4;
    iset64 c;
    c += 7;
    c += 8;
    iset64 d = a + b + c + 5;
    cout << "Set a " << a << endl;
    cout << "Set b " << b << endl;
    cout << "Set c " << c << endl;
    cout << "Set d " << d << endl;
  }
}

/*----------------------------------------------------------------
test equal
-----------------------------------------------------------------*/
static void test_equal_not_equal() {
  {
    cout << "TESTING: bool operator==(const iset64& a, const iset64& b)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    iset64 b;
    b += 1;
    b += 2;
    cout << "Set a " << a << endl;
    cout << "Set b " << b << endl;
    cout << "a == b " << boolalpha << (a == b) << endl;
    b -= 1;
    cout << a;
    cout << b;
    cout << "a == b " << boolalpha << (a == b) << endl;
  }
  {
    cout << "TESTING: bool operator!=(const iset64& a, const iset64& b)" << endl;
    iset64 a;
    a += 1;
    a += 2;
    iset64 b;
    b += 1;
    b += 2;
    cout << "Set a " << a << endl;
    cout << "Set b " << b << endl;
    cout << "a != b " << boolalpha << (a != b) << endl;
    b -= 1;
    cout << "Set a " << a << endl;
    cout << "Set b " << b << endl;
    cout << "a != b " << boolalpha << (a != b) << endl;
  }
}

/*----------------------------------------------------------------
++ and --
-----------------------------------------------------------------*/
static void test_pre_post_inr_dec() {
  {
    int x[] = { 1, 2, 63 };
    iset64 a(x, sizeof(x) / sizeof(int));
    cout << "a = " << a << endl;
    ++a;
    cout << "++a = " << a << endl;
    int y[] = { 2, 3, 0 };
    iset64 b(y, sizeof(y) / sizeof(int));
    assert(a == b);
  }
  {
    int x[] = { 1, 2, 63 };
    iset64 a(x, sizeof(x) / sizeof(int));
    cout << "a = " << a << endl;
    iset64 acopy(x, sizeof(x) / sizeof(int));
    cout << "acopy = " << acopy << endl;
    iset64 rhs = a++;
    assert(rhs == acopy);
    cout << "a++ = " << a << endl;
    cout << "rhs = " << rhs << endl;
    int y[] = { 2, 3, 0 };
    iset64 b(y, sizeof(y) / sizeof(int));
    assert(a == b);
  }
  {
    int x[] = { 0,2,63 };
    iset64 a(x, sizeof(x) / sizeof(int));
    cout << "a = " << a << endl;
    --a;
    cout << "--a = " << a << endl;
    int y[] = { 63, 1, 62 };
    iset64 b(y, sizeof(y) / sizeof(int));
    assert(a == b);
  }
  {
    int x[] = { 0, 2, 63 };
    iset64 a(x, sizeof(x) / sizeof(int));
    cout << "a = " << a << endl;
    iset64 acopy(x, sizeof(x) / sizeof(int));
    cout << "acopy = " << acopy << endl;
    iset64 rhs = a--;
    assert(rhs == acopy);
    cout << "a-- = " << a << endl;
    cout << "rhs = " << rhs << endl;
    int y[] = { 63, 1, 62 };
    iset64 b(y, sizeof(y) / sizeof(int));
    assert(a == b);
  }
}

static void test_additional() {
    {
        int x[] = { 1, 2, 63 };
        iset64 a(x, 3);
        cout << "a = " << a << endl;
        int y[] = { 2, 3, 0 };
        iset64 b(y, 3);
        cout << "b = " << b << endl;
        cout << "a - b = " << a - b << endl;
        iset64 c;
        c += 1;
        c += 63;
        a -= b;
        cout << "a-=b, a=" << a << endl;
        assert(a == c);
        cout << "c= " << c << endl;
        cout << "1 - c = " << 1 - c << endl;
    }
    {
        int x[] = { 1, 2, 63 };
        iset64 a(x, 3);
        cout << "a = " << a << endl;
        int y[] = { 2, 3, 0 };
        iset64 b(y, 3);
        cout << "b = " << b << endl;
        int z[] = { 4, 5, 63 };
        iset64 c(z, 3);
        cout << "c = " << c << endl;
        cout << "a++ - --b + c = " << a++ - --b + c << endl;
    }
    {
        int x[] = { 1, 2, 63 };
        iset64 a(x, 3);
        cout << "a = " << a << endl;
        cout << "~a = " << ~a << endl;
        a -= 2;
        a -= 63;
        assert(a == 1);
        assert(1 == a);
        assert(a != 2);
        assert(2 != a);
    }
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
  test_basic();
  test_union();
  test_equal_not_equal();
  test_pre_post_inr_dec();
  test_additional();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainiset64
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  iset64::set_display(false) ;
  testbed();
  cout << "Must attach output of the program as a text file to get a grade\n";
  cout << "Must attach a doc that explains the data structure that was used to solve to get a grade\n";
  cout << "DO NOT attach iset64test.cpp\n";
  cout << "UPLOAD ONLY iset64.cpp  iset64.h\n";
  cout << "I will run your code by adding iset64.cpp  iset64.h\n";
  cout << "All test must pass for 100 marks\n" ;
  return 0;
}

//EOF


