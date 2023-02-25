/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false ;


/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
int split(const char* s, const int &l, const int &r, const char deli) {
    return find(s + l, s + r, deli) - (s + l);
}

bool verifyCharacter(const char ch) {
    return ch == '|' || ch == ' ' || (ch >= '0' && ch <= '9');
}

bool verifyMatrix(const char* s, int& row, int& col) {
    int sLen = strlen(s);
    if (sLen == 0) {
        return false;
    }
    for (int l = 0, r = sLen; l < r; l++) {
        if (!verifyCharacter(s[l])) {
            return false;
        }
    }
    row = 0;
    for (int l = 0, r = sLen, len = 0; l <= r; l += len + 1) {
        len = split(s, l, r, '|');
        if (len == 0) {
            return false;
        }
        row++;
        int tmpc = 0;
        for (int l2 = l, r2 = l+len, len2 = 0; l2 <= r2; l2 += len2 + 1) {
            len2 = split(s, l2, r2, ' ');
            tmpc += len2 > 0;
        }
        if (col == 0) {
            col = tmpc;
        } else if (col != tmpc) {
            return false;
        }
    }
    return col > 0;
}

int stringToInt(const char* s, int l, int r) {
    int ans = 0;
    for (int i = l; i < r; i++) {
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}

intmatrix2::intmatrix2(const int r, const int c, const int v):_r(r), _c(c) {
    if (show()) {
        cout << "In constructor r = " << r << " c = " << c << " v = " << v << endl;
    }
    _reconstruct(r, c, v);
}

intmatrix2::intmatrix2(const char* s) {
    if (show()) {
        cout << "In constructor s = " << s << endl;
    }
    _reconstructFromStr(s);
}

intmatrix2::intmatrix2(const intmatrix2& obj) {
    if (show()) {
        cout << "In copy constructor" << endl;
        cout << obj << endl;
    }
    _copy(obj);
}

intmatrix2::~intmatrix2() {
    _release();
}

ostream& operator<<(ostream& os, const intmatrix2& obj) {
    if (obj._r == 0 || obj._c == 0) {
        os << "\tEmpty Matrix" << endl;
    } else {
        for (int i = 0; i < obj._r; i++) {
            for (int j = 0; j < obj._c; j++) {
                os << obj._matrix[i][j] << (j == obj._c-1? "\n": " "); 
            }
        }
    }
    return os;
}

intmatrix2& intmatrix2::operator=(const intmatrix2 &obj) {
    if (this != &obj) {
        if (show()) {
            cout << "In equal operator rhs" << endl;
            cout << obj << endl;
        }
        _release();
        _copy(obj);
    }
    return *this;
}

bool intmatrix2::operator!() {
    return this->_r == 0 || this->_c == 0;
}

intmatrix2 intmatrix2::add(const intmatrix2 &obj) {
    if (this->_r != obj._r || this->_c != obj._c) {
        return intmatrix2(0, 0);
    }
    intmatrix2 ans(this->_r, this->_c);
    for (int i = 0; i < this->_r; i++) {
        for (int j = 0; j < this->_c; j++) {
            ans._matrix[i][j] = obj._matrix[i][j] + this->_matrix[i][j];
        }
    }
    return ans;
}

intmatrix2 intmatrix2::mult(const intmatrix2& obj) {
    if(this->_c == obj._r) {
        intmatrix2 ans(this->_r, obj._c);
        for (int i = 0; i < this->_r; i++) {
            for (int j = 0; j < obj._c; j++) {
                for (int k = 0; k < this->_c; k++) {
                    ans._matrix[i][j] += this->_matrix[i][k] * obj._matrix[k][j];
                }
            }
        }
        return ans;
    }
    if (obj._r == 1 && obj._c == 1) {
        int v = obj._matrix[0][0];
        intmatrix2 ans(this->_r, this->_c);
        for (int i = 0; i < this->_r; i++) {
            for (int j = 0; j < this->_c; j++) {
                ans._matrix[i][j] = this->_matrix[i][j] * v;
            }
        }
        return ans;
    }
    if (this->_r == 1 || this->_c == 1) {
        int v = this->_matrix[0][0];
        intmatrix2 ans(obj._r, obj._c);
        for (int i = 0; i < obj._r; i++) {
            for (int j = 0; j < obj._c; j++) {
                ans._matrix[i][j] = obj._matrix[i][j] * v;
            }
        }
        return ans;
    }
    return intmatrix2(0, 0);
}

bool intmatrix2::isEqual(const intmatrix2 &obj) {
    if (this->_r != obj._r || this->_c != obj._c) {
        return false;
    } 
    for (int i = 0; i < this->_r; i++) {
        for (int j = 0; j < this->_c; j++) {
            if (this->_matrix[i][j] != obj._matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void intmatrix2::_release() {
    if (_matrix != nullptr) {
        if (show()) {
            cout << "In distructor" << endl;
            if (this->_r == 0 || this->_c == 0) {
                cout << "\tEmpty Matrix" << endl;
            } else {
                for (int i = 0; i < this->_r; i++) {
                    for (int j = 0; j < this->_c; j++) {
                        cout << this->_matrix[i][j] << (j == this->_c-1? "\n": " ");
                    }
                }
            }
            cout << "\n" << endl;
        }
        for (int i = 0; i < _r; i++) {
            if (_matrix[i] != nullptr) {
                delete[] _matrix[i];
            }
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
    _r = 0;
    _c = 0;
}

void intmatrix2::_reconstruct(const int &r, const int &c, int v) {
    _release();
    _r = r;
    _c = c;
    if (r == 0 || c == 0) {
        return;
    }
    _matrix = new int*[r];
    for (int i = 0; i < r; i++) {
        _matrix[i] = new int[c];
        for (int j = 0; j < c; j++) {
            _matrix[i][j] = v;
        }
    }
}

void intmatrix2::_reconstructFromStr(const char *s) {
    int r = 0, c = 0;
    if (!verifyMatrix(s, r, c)) {
        _reconstruct(0, 0);
        return;
    }
    _reconstruct(r, c);
    int tmpr = 0;
    for(int l = 0, r = strlen(s), len = 0; l <= r; l += len + 1) {
        int tmpc = 0;
        len = split(s, l, r, '|');
        for(int l2 = l, r2 = l + len, len2 = 0; l2 <= r2; l2 += len2 + 1) {
            len2 = split(s, l2, r2, ' ');
            if(len2 > 0) {
                _matrix[tmpr][tmpc++] = stringToInt(s, l2, l2 + len2);
            }
        }
        tmpr++;
    }
}

void intmatrix2::_copy(const intmatrix2& obj) {
    _reconstruct(obj._r, obj._c);
    for (int i = 0; i < obj._r; i++) {
        for (int j = 0; j < obj._c; j++) {
            this->_matrix[i][j] = obj._matrix[i][j];
        }
    }
}



//EOF

