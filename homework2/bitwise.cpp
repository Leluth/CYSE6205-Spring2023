/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: bitwise.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has bitwise class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "bitwise.h"
#include <bitset>

/*----------------------------------------------------------------
Definition of routines of bitwise class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
---------------  test_bitwise ---------
All answers are in hexadecimal
1. a = 0
2. ~a = ffffffff
Note that a NOT is changed,. Only the RHS is changed
2a. After ~a, a = 0
3. a = 1 00000001
4. b = 2 00000010
5. c = 3 00000011
6. (a & b) = 0 00000000
7. (a ! b) = 3 00000011
8. (a ^ b) = 3 00000011
9. (a & c) = 1 00000001
10. (a ! c) = 3 00000011
11. (a ^ c) = 2 00000010
-----------------------------------------------------------------*/
void bitwise::test_bitwise() {
		cout << "---------------  test_bitwise ---------\n";
		int a = 0;
		cout << hex;
		cout << "All answers are in hexadecimal" << endl;
		cout << "1. a = " << a << endl;
		cout << "2. ~a = " << ~a << endl;
		cout << "Note that a NOT is changed,. Only the RHS is changed\n";
		cout << "2a. After ~a, a = " << a << endl;
		a = 1;
		int b = 2;
		int c = 3;
		cout << "3. a = " << a << " " << bitset<8>(a) << endl;
		cout << "4. b = " << b << " " << bitset<8>(b) << endl;
		cout << "5. c = " << c << " " << bitset<8>(c) << endl;

		cout << "6. (a & b) = " << (a & b) << " " << bitset<8>(a & b) << endl;
		cout << "7. (a ! b) = " << (a | b) << " " << bitset<8>(a | b) << endl;
		cout << "8. (a ^ b) = " << (a ^ b) << " " << bitset<8>(a ^ b) << endl;

		cout << "9. (a & c) = " << (a & c) << " " << bitset<8>(a & c) << endl;
		cout << "10. (a ! c) = " << (a | c) << " " << bitset<8>(a | c) << endl;
		cout << "11. (a ^ c) = " << (a ^ c) << " " << bitset<8>(a ^ c) << endl;
		cout.unsetf(ios::hex);
}

/*----------------------------------------------------------------
-------------------  test_shift -------------------
a = 1 00000001
Left shift a by 0 = 00000001 1
Left shift a by 1 = 00000010 2
Left shift a by 2 = 00000100 4
Left shift a by 3 = 00001000 8
Left shift a by 4 = 00010000 16
Left shift a by 5 = 00100000 32
Left shift a by 6 = 01000000 64
Left shift a by 7 = 10000000 128
-----------------------
a = 256 100000000
Right shift a by 0 = 100000000 256
Right shift a by 1 = 010000000 128
Right shift a by 2 = 001000000 64
Right shift a by 3 = 000100000 32
Right shift a by 4 = 000010000 16
Right shift a by 5 = 000001000 8
Right shift a by 6 = 000000100 4
Right shift a by 7 = 000000010 2
-----------------------
a = -1 11111111
Left shift a by 0 = 11111111 -1
Left shift a by 1 = 11111110 -2
Left shift a by 2 = 11111100 -4
Left shift a by 3 = 11111000 -8
Left shift a by 4 = 11110000 -16
Left shift a by 5 = 11100000 -32
Left shift a by 6 = 11000000 -64
Left shift a by 7 = 10000000 -128
-----------------------
a = -256 100000000
Right shift a by 0 = 100000000 -256
Right shift a by 1 = 110000000 -128
Right shift a by 2 = 111000000 -64
Right shift a by 3 = 111100000 -32
Right shift a by 4 = 111110000 -16
Right shift a by 5 = 111111000 -8
Right shift a by 6 = 111111100 -4
Right shift a by 7 = 111111110 -2
-----------------------------------------------------------------*/
void bitwise::test_shift() {
		cout << "-------------------  test_shift -------------------\n";
		int a = 1;
		cout << "a = " << a << " " << bitset<8>(a) << endl;
		for (int i = 0; i < 8; i++) {
				int x = a << i;
				cout << "Left shift a by " << i << " = " << bitset<8>(x) << " " << x << endl;
		}
		cout << "-----------------------" << endl;
		a = 256;
		cout << "a = " << a << " " << bitset<9>(a) << endl;
		for (int i = 0; i < 8; i++) {
				int x = a >> i;
				cout << "Right shift a by " << i << " = " << bitset<9>(x) << " " << x << endl;
		}
		cout << "-----------------------" << endl;
		a = -1;
		cout << "a = " << a << " " << bitset<8>(a) << endl;
		for (int i = 0; i < 8; i++) {
				int x = a << i;
				cout << "Left shift a by " << i << " = " << bitset<8>(x) << " " << x << endl;
		}
		cout << "-----------------------" << endl;
		a = -256;
		cout << "a = " << a << " " << bitset<9>(a) << endl;
		for (int i = 0; i < 8; i++) {
				int x = a >> i;
				cout << "Right shift a by " << i << " = " << bitset<9>(x) << " " << x << endl;
		}
}

/*----------------------------------------------------------------
//WRITE all interview questions implementation here
-----------------------------------------------------------------*/
int bitwise::set_bit_i_to_1_and_all_others_to_zero(int n){
	return 1 << n;
}

int bitwise::set_bit_i_to_0_and_all_others_to_one(int n){
	return ~(1 << n);
}

int bitwise::get_bit_i(int x, int n){
	return (n >> x) & 1;
}

void bitwise::set_bit_i(int x, int &n){
	n |= 1 << x;
}

void bitwise::reset_bit_i(int x, int &n){
	n &= ~(1 << x);
}
void bitwise::reset_last_set_bit_of_rightmost_n(int &n){
	n ^= n & -n;
}

bool bitwise::check_n_is_a_power_of_2(int n){
	return n && !(n ^ (n & -n));
}

bool bitwise::check_n_is_a_power_of_4(int n){
	int p = 0;
	for(int num = n & -n; num && !(num & 1); num >>= 1, p++);
	return n && !(n ^ (n & -n)) && !(p & 1);
}

int bitwise::position_of_rightmost_set_bit(int n){
	int p = 0;
	for(int num = n & -n; num && !(num & 1); num >>= 1, p++);
	return p;
}
