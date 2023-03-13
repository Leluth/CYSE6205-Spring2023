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
	longnumber(int i = 0);
	longnumber(const char* n);
	~longnumber();
	longnumber(const longnumber& rhs) {
		copy_(rhs);
	}
	longnumber& operator =(const longnumber& rhs) {
		if (this != &(rhs)) {
			free_();
			copy_(rhs);
		}
		return *this;
	}
	friend ostream& operator <<(ostream& o, const longnumber& l);
	char& operator [](int i) const {
		return s_[i];
	}
	friend bool operator ==(const longnumber& a, const longnumber& b);
	friend bool operator !=(const longnumber& a, const longnumber& b);
	friend longnumber operator +(const longnumber& a, const longnumber& b);
	friend longnumber operator *(const longnumber& a, const int b);
	static longnumber fact(const int n);
	bool is_positive() const { return sign_; }
	bool is_negative() const { return (!(is_positive())); }
	int num_digits() const { return int(strlen(s_)); }
	
private:
		//Private data. YOU CANNOT USE STL. 0 marks will given if you add vector, string or set etc
		//You can have any number of C++ prinitives you want
	    char* s_ = nullptr;
		bool sign_ = true;
		//Private functions. You can have any number of funcions
		void num_2_String_(int n);
		void reverse_();
		void insert_at_pos_(char c, int space, int pos);
		void insert_at_pos_(int i, int space, int pos);
		void allocate_(int s) {
			s_ = new char[s];
		}
		void free_() {
			delete[] s_;
		}
		void copy_(const longnumber& rhs) {
			allocate_(rhs.num_digits() + 1);
			strcpy(s_, rhs.s_);
			sign_ = rhs.sign_;
		}
		void change_sign(bool x) {
			sign_ = x;
		}
		void reserve_(int s) {
			free_();
			allocate_(s);
		}
};

//EOF


