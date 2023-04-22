/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: iset64.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has iset64 class definition 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
YOU CANNOT ADD ANYTHING other than iset64.h
-----------------------------------------------------------------*/
#include "iset64.h"

/*----------------------------------------------------------------
static declaration
-----------------------------------------------------------------*/
bool iset64::display = false;

/*----------------------------------------------------------------
Definition of routines of iset64 class
-----------------------------------------------------------------*/
iset64::iset64(const unsigned long long& _d) {
    if (display) {
        cout << "In constructor\n";
    }
    _digit = _d;
}

iset64::iset64(const int& i) {
    if (display) {
        cout << "In constructor\n";
    }
    unsigned long long bitMask = _generateBitMask(i);
    _digit = bitMask;
}

iset64::iset64(const int* arr, const int& len) {
    if (display) {
        cout << "In constructor\n";
    }
    _digit = 0;
    for (int i = 0; i < len; ++i) {
        unsigned long long bitMask = _generateBitMask(arr[i]);
        _digit |= bitMask;
    }
}

iset64::iset64(const iset64& obj) {
    if (display) {
        cout << "In copy constructor\n";
    }
    _digit = obj._digit;
}

iset64::~iset64() {
    if (display) {
        cout << "In disstructor\n";
    }
}

ostream& operator<<(ostream& o, const iset64& obj) {
    o << "{";
    if (obj._digit == 0) {
        o << "Empty set";
    }
    bool first = true;
    for (int i = 0; i < obj.N; ++i) {
        unsigned long long bitMask = obj._generateBitMask(i);
        unsigned long long res = obj._digit & bitMask;
        if (res) {
            if (!first) {
                o << ", ";
            }
            o << i;
            first = false;
        }
    }
    o << "}";
    return o;
}

iset64& operator+(iset64& obj, const int& i) {
    unsigned long long bitMask = obj._generateBitMask(i);
    obj._digit |= bitMask;
    return obj;
}

iset64& operator-(iset64& obj, const int& i) {
    unsigned long long bitMask = obj._generateBitMask(i);
    obj._digit &= ~bitMask;
    return obj;
}

iset64& operator+(const int& i, iset64& obj) {
    unsigned long long bitMask = obj._generateBitMask(i);
    obj._digit |= bitMask;
    return obj;
}

iset64& operator-(const int& i, iset64& obj) {
    unsigned long long bitMask = obj._generateBitMask(i);
    bitMask &= ~obj._digit;
    obj._digit = bitMask;
    return obj;
}

iset64& operator+=(iset64& obj, const int i) {
    unsigned long long bitMask = obj._generateBitMask(i);
    obj._digit |= bitMask;
    return obj;
}

iset64& operator-=(iset64& obj, const int i) {
    unsigned long long bitMask = obj._generateBitMask(i);
    obj._digit &= ~bitMask;
    return obj;
}

bool operator==(const iset64& a, const iset64& b) {
    return a._digit == b._digit;
}

bool operator!=(const iset64& a, const iset64& b) {
    return a._digit != b._digit;
}

void iset64::operator+=(const iset64& obj) {
    _digit |= obj._digit;
}

void iset64::operator-=(const iset64& obj) {
    _digit &= (~obj._digit);
}

iset64& iset64::operator=(const iset64& obj) {
    if (display) {
        cout << "In equal operator\n";
    }
    if (this != &obj) {
        _digit = obj._digit;
    }
    return *this;
}

iset64 iset64::operator+(const iset64& obj) {
    return iset64(_digit | obj._digit);
}

iset64 iset64:: operator-(const iset64& obj) {
    return iset64(_digit & (~obj._digit));
}

iset64 iset64::operator++() {
    bool overflow = _digit & _generateBitMask(63);
    _digit <<= 1;
    if (overflow) {
        _digit |= 1;
    }

    return iset64(_digit);
}

iset64 iset64::operator--() {
    bool overflow = _digit & _generateBitMask(0);
    _digit >>= 1;
    if (overflow) {
        _digit |= _generateBitMask(63);
    }

    return iset64(_digit);
}

iset64 iset64::operator++(int) {
    iset64 res(_digit);

    bool overflow = _digit & _generateBitMask(63);
    _digit <<= 1;
    if (overflow) {
        _digit |= 1;
    }

    return res;
}

iset64 iset64::operator--(int) {
    iset64 res(_digit);

    bool overflow = _digit & _generateBitMask(0);
    _digit >>= 1;
    if (overflow) {
        _digit |= _generateBitMask(63);
    }

    return res;
}

iset64 iset64::operator~() {
    return (~_digit);
}

unsigned long long iset64::_generateBitMask(const int& i) {
    return 1ull << i;
}
//EOF

