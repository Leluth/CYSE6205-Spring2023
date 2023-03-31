#include <iostream>
#include <assert.h>
using namespace std;

class obj {
public:
	obj(int x = 0) :_x(x) {
		if (show) {
			cout << "In constructor\n";
		}
	}
	~obj() {
		if (show) {
			cout << "In disstructor\n";
		}
		_x = 999999;
	}
	obj(const obj& r) {
		_x = r._x;
		if (show) {
			cout << "In copy constructor\n";
		}
	}
	obj& operator=(const obj& r) {
		_x = r._x;
		if (show) {
			cout << "In equal operator\n";
		}
		return *this;
	}
	friend ostream& operator<<(ostream& o, const obj& r) {
		o << "obj(" << r._x << ")";
		return o;
	}
	friend ostream& operator<<(ostream& o, const obj* r) {
		o << "obj(" << r->_x << ")";
		return o;
	}
	friend bool operator==(const obj& a, const obj& b) {
		return a._x == b._x;
	}
	friend bool operator!=(const obj& a, const obj& b) {
		return a._x != b._x;
	}
	obj& operator++() {
		++_x;
		return *this;
	}
	obj operator++(int j) {
		return(_x++);
	}
	obj& operator--() {
		--_x;
		return *this;
	}
	obj operator--(int j) {
		return(_x--);
	}
	obj operator-() {
		return(-_x);
	}
	static bool show;

private:
	int _x;
};

bool obj::show = false;
void main() {
	cout << "=============Test Initialization=============" << endl;
	{
		int a = 0;
		obj x;
		cout << "int a = 0, a = " << a << endl;
		cout << "obj x, x = " << x << endl;
		if (a != x) {
			cout << "a is NOT equal to x!" << endl;
			assert(false);
		}
		cout << "a is euqal to x\n" << endl;

		int b = 5;
		obj y(5);
		cout << "int b = 5, b = " << b << endl;
		cout << "obj y(5), y = " << y << endl;
		if (b != y) {
			cout << "b is NOT equal to y!" << endl;
			assert(false);
		}
		cout << "b is euqal to y\n" << endl;

		int c = 8;
		obj* z = new obj(8);
		cout << "int c = 8, c = " << c << endl;
		cout << "obj* z = new obj(8), z = " << z << endl;
		if (c != *z) {
			cout << "c is NOT equal to z!" << endl;
			assert(false);
		}
		cout << "c is euqal to z\n" << endl;
	}
	cout << "==============Test Pre-Increment=============" << endl;
	{
		int a = 20;
		obj x(20);
		cout << "int a = " << a << endl;
		cout << "obj x = " << x << endl;
		int b = ++a;
		obj y = ++x;
		cout << "int b = ++a, a = " << a << ", b = " << b << endl;
		cout << "obj y = ++x, x = " << x << ", y = " << y << endl;
		if (a != x) {
			cout << "a is NOT equal to x!" << endl;
			assert(false);
		}
		cout << "a is euqal to x" << endl;
		if (b != y) {
			cout << "b is NOT equal to y!" << endl;
			assert(false);
		}
		cout << "b is euqal to y\n" << endl;
	}
	cout << "==============Test Pre-Decrement=============" << endl;
	{
		int a = 20;
		obj x(20);
		cout << "int a = " << a << endl;
		cout << "obj x = " << x << endl;
		int b = --a;
		obj y = --x;
		cout << "int b = --a, a = " << a << ", b = " << b << endl;
		cout << "obj y = --x, x = " << x << ", y = " << y << endl;
		if (a != x) {
			cout << "a is NOT equal to x!" << endl;
			assert(false);
		}
		cout << "a is euqal to x" << endl;
		if (b != y) {
			cout << "b is NOT equal to y!" << endl;
			assert(false);
		}
		cout << "b is euqal to y\n" << endl;
	}
	cout << "=============Test Post-Increment============" << endl;
	{
		int a = 20;
		obj x(20);
		cout << "int a = " << a << endl;
		cout << "obj x = " << x << endl;
		int b = a++;
		obj y = x++;
		cout << "int b = a++, a = " << a << ", b = " << b << endl;
		cout << "obj y = x++, x = " << x << ", y = " << y << endl;
		if (a != x) {
			cout << "a is NOT equal to x!" << endl;
			assert(false);
		}
		cout << "a is euqal to x" << endl;
		if (b != y) {
			cout << "b is NOT equal to y!" << endl;
			assert(false);
		}
		cout << "b is euqal to y\n" << endl;

		int c = 20;
		obj m(20);
		cout << "int c = " << c << endl;
		cout << "obj m = " << m << endl;
		int d = -c++;
		obj n = -m++;
		cout << "int d = -c++, c = " << c << ", d = " << d << endl;
		cout << "obj n = -m++, m = " << m << ", n = " << n << endl;
		if (c != m) {
			cout << "c is NOT equal to m!" << endl;
			assert(false);
		}
		cout << "c is euqal to m" << endl;
		if (d != n) {
			cout << "d is NOT equal to n!" << endl;
			assert(false);
		}
		cout << "d is euqal to n\n" << endl;
	}
	cout << "=============Test Post-Decrement============" << endl;
	{
		int a = 20;
		obj x(20);
		cout << "int a = " << a << endl;
		cout << "obj x = " << x << endl;
		int b = a--;
		obj y = x--;
		cout << "int b = a--, a = " << a << ", b = " << b << endl;
		cout << "obj y = x--, x = " << x << ", y = " << y << endl;
		if (a != x) {
			cout << "a is NOT equal to x!" << endl;
			assert(false);
		}
		cout << "a is euqal to x" << endl;
		if (b != y) {
			cout << "b is NOT equal to y!" << endl;
			assert(false);
		}
		cout << "b is euqal to y\n" << endl;

		int c = 20;
		obj m(20);
		cout << "int c = " << c << endl;
		cout << "obj m = " << m << endl;
		int d = -c--;
		obj n = -m--;
		cout << "int d = -c--, c = " << c << ", d = " << d << endl;
		cout << "obj n = -m--, m = " << m << ", n = " << n << endl;
		if (c != m) {
			cout << "c is NOT equal to m!" << endl;
			assert(false);
		}
		cout << "c is euqal to m" << endl;
		if (d != n) {
			cout << "d is NOT equal to n!" << endl;
			assert(false);
		}
		cout << "d is euqal to n\n" << endl;
	}
}