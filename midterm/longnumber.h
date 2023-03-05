/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: longnumber.h
-----------------------------------------------------------------*/

#pragma once

/*----------------------------------------------------------------
Basic include files.
CANNOT CHANGE OR ADD ANY LIBRARY
CANNOT USE ANY STL OBJECTS FOR THIS ASSIGNMENT
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <string.h> //for strlen,strcat and strcpy on linux
#endif

//'sprintf' : This function or variable may be unsafe.Consider using sprintf_s instead.To disable deprecation, 
//use _CRT_SECURE_NO_WARNINGS
//To overcome above warning
#ifdef _MSC_VER
#pragma warning(disable: 4996) /* Disable deprecation */
#endif

//IF YOU ADD ant STL library here, 0 marks will be given

/*--------------------------------------------------------
long number class
----------------------------------------------------------*/
class longnumber {
public:
	longnumber();
	longnumber(const int& k);
	longnumber(const char* s);
	~longnumber();
	bool is_negative();
	bool is_positive();
	int num_digits();
	friend ostream& operator <<(ostream& o, const longnumber& obj);
	bool operator ==(const longnumber& obj);
	bool operator !=(const longnumber& obj);
	char operator [](const int& i);
	longnumber& operator=(const longnumber& obj);
	longnumber operator+(const int& n);
	longnumber operator +(const longnumber& obj);
	longnumber operator*(const int& n);
	longnumber operator *(const longnumber& obj);
	static longnumber fact(const int& n);
private:
		//Private data. YOU CANNOT USE STL. 0 marks will given if you add vector, string or set etc
		//You can have any number of C++ prinitives you want
	    char* _valueStr;
		bool _isNegative = false;
		bool _isPositive = false;
		int _digitNum = 0;
		//Private functions. You can have any number of funcions
		bool _isEqual(const longnumber& obj);
};

//EOF


