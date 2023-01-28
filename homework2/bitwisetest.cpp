/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: bitwisetest.cpp

On linux:
g++ bitwise.cpp bitwisetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "bitwise.h"
#include <bitset>
#include <cmath>

/*----------------------------------------------------------------
global to this file
-----------------------------------------------------------------*/
static const int K = 8;

/*----------------------------------------------------------------
Header
-----------------------------------------------------------------*/
static void H() {
		for (int i = K - 1; i >= 0; --i) {
				cout << i;
		}
		cout << endl;
}

/*----------------------------------------------------------------
print int as bits
-----------------------------------------------------------------*/
static void P(int n) {
		cout << "n = " << n << endl;
		H();
		cout << bitset<K>(n) << endl;
}

/*----------------------------------------------------------------
interview
-----------------------------------------------------------------*/
static void interview() {
		bitwise b;
		{
				cout << "--------- set bit i to 1 and all others to 0 ------------\n";
				H();
				for (int i = 0; i < K; ++i) {
						int a = b.set_bit_i_to_1_and_all_others_to_zero(i);
						cout << "Set bit " << i << " to 1:" << bitset<K>(a) << endl;
						int g = int(pow(2, i));
						if (a != g) {
								cout << "correct answer = " << bitset<K>(a) << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- set bit i to 0 and all others to 1 ------------\n";
				H();
				const int g[] = { -2,-3,-5,-9,-17,-33,-65,-129 };
				for (int i = 0; i < K; ++i) {
						int a = b.set_bit_i_to_0_and_all_others_to_one(i);
						cout << "Set bit " << i << " to 1:" << bitset<K>(a) << " a = " << a << endl;
						if (a != g[i]) {
								cout << "correct answer = " << bitset<K>(g[i]) << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- bit_at_position_i_of_n ------------\n";
				int n = 200; //must be < 255 as K = 8
				P(n);
				for (int i = K - 1; i >= 0; --i) {
						int a = b.get_bit_i(i, n);
						bitset<K> g(n); //gold answer
						cout << "g[" << i << "] = " << g[i] << " ";
						cout << "n[" << i << "] = " << a << endl;
						if (g[i] != a) {
								cout << "n[" << i << "] = " << a << " is WRONG\n";
								assert(false);
						}
				}
		}
		{
				cout << "--------- set_bit_at_position_i_of_n ------------\n";
				int n = 200; //must be < 255 as K = 8
				P(n);
				for (int i = K - 1; i >= 0; --i) {
						b.set_bit_i(i, n);
						bitset<K> g(n);
						g.set(i);
						cout << "Set " << i << " bit to 1: " << "g = " << g << " n = " << bitset<K>(n) << endl;
						int gi = (int)(g.to_ulong()); //bitset to int
						if (gi != n) {
								cout << "correct answer = " << g << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- reset_bit_at_position_i_of_n ------------\n";
				int n = 200; //must be < 255 as K = 8
				P(n);
				for (int i = K - 1; i >= 0; --i) {
						b.reset_bit_i(i, n);
						bitset<K> g(n); //Note cannot be K.
						g.reset(i);
						cout << "Reset " << i << " bit  to 0: " << "g = " << g << " n = " << bitset<K>(n) << endl;
						int gi = (int)(g.to_ulong()); //bitset to int
						if (gi != n) {
								cout << "correct answer = " << g << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- reset_last_set_bit_of_rightmost_n ------------\n";
				int n = 214; //must be < 255 as K = 8
				P(n);
				const int g[] = { 0,0,0,0, 128,192,208,212 };
				for (int i = K - 1; i >= 0; --i) {
						cout << n << " reset_last_set_bit_of_rightmost_n " << bitset<K>(n) << "  ";
						b.reset_last_set_bit_of_rightmost_n(n);
						cout << bitset<K>(n) << "  " << n << endl;
						if (n != g[i]) {
								cout << "correct answer = " << bitset<K>(g[i]) << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- check n is a power of 2 ------------\n";
				const int a[] = { 0,1,2,3,4,7,8, 15,16,31,32, 57,64,120,128,254,255 };
				const int g[] = { 0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0 };
				int s = sizeof(a) / sizeof(int);
				for (int i = 0; i < s; ++i) {
						int n = a[i];
						cout << n << " is a power of 2 " << bitset<K>(n) << " IS ";
						bool v = b.check_n_is_a_power_of_2(n);
						cout << boolalpha << v << endl;
						if (v != g[i]) {
								cout << "correct answer = " << boolalpha << bool(g[i]) << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- check n is a power of 4 ------------\n";
				const int a[] = { 0,1,2,3,4,7,8, 15,16,31,32, 57,64,120,128,254,255,256,1023,1024 };
				const int g[] = { 0,1,0,0,1,0,0, 0, 1, 0, 0,  0, 1,  0,0,0,0,1,0,1 };
				int s = sizeof(a) / sizeof(int);
				for (int i = 0; i < s; ++i) {
						int n = a[i];
						cout << n << " is a power of 4 " << bitset<16>(n) << " IS ";
						bool v = b.check_n_is_a_power_of_4(n);
						cout << boolalpha << v << endl;
						if (v != g[i]) {
								cout << "correct answer = " << boolalpha << bool(g[i]) << endl;
								assert(false);
						}
				}
		}
		{
				cout << "--------- position_of_rightmost_set_bit ------------\n";
				const int a[] = { 1,10,18, 19, 32, 64 };
				const int g[] = { 0,1, 1,0,5 , 6 };
				const int k = sizeof(a) / sizeof(int);
				for (int i = 0; i < k; ++i) {
						int n = a[i];
						int ans = b.position_of_rightmost_set_bit(n);
						cout << n << " position_of_rightmost_set_bit  " << bitset<K>(n) << "  " << ans << endl;
						if (ans != g[i]) {
								cout << "correct answer = " << g[i] << endl;
								assert(false);
						}
				}
		}
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
static void testbed() {
		bitwise a;
		a.test_bitwise();
		a.test_shift();
		//You need to write code for interview
		interview();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
		// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		testbed();
		return 0;
}

//EOF
