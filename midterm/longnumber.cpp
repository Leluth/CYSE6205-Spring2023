/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: longnumber.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HERE
-----------------------------------------------------------------*/
#include "longnumber.h"

longnumber::longnumber() {
     _valueStr = nullptr;
    _isNegative = false;
    _isPositive = false;
    _digitNum = 0;
}

longnumber::longnumber(const int& k) {
    _isNegative = k < 0;
    _isPositive = k > 0;
    int remain = k;
    while (remain != 0) {
        _digitNum++;
        remain /= 10;
    }
    if (k == 0) {
        _digitNum = 1;
    }
    _valueStr = new char[_digitNum + 1];
    _valueStr[_digitNum] = '\0';
    int pointer = _digitNum - 1;
    remain = k;
    while (pointer >= 0) {
        _valueStr[pointer] = abs(remain % 10) + '0';
        remain /= 10;
        pointer--;
    }
}

longnumber::longnumber(const char* s) {
    int start = 0;
    int sLen = strlen(s);
    _digitNum = sLen;
    if (s[0] == '-') {
        start = 1;
        _isNegative = true;
        _digitNum--;
    }
    else if (s[0] != '0') {
        _isPositive = true;
    }
    _valueStr = new char[_digitNum + 1];
    _valueStr[_digitNum] = '\0';
    int pointer = _digitNum - 1;
    while (pointer >= 0) {
        _valueStr[pointer] = s[pointer + start];
        pointer--;
    }
}

longnumber::~longnumber() {
    if (_valueStr != nullptr) {
        delete[] _valueStr;
    }
}

bool longnumber::is_negative() {
    return _isNegative;
}

bool longnumber::is_positive() {
    return _isPositive;
}

int longnumber::num_digits() {
    return _digitNum;
}

ostream& operator<<(ostream& os, const longnumber& obj) {
    if (obj._isNegative) {
        os << '-';
    }
    int count = 1;
    int pointer = 0;
    while (pointer < obj._digitNum) {
        if (count > 40 && count % 40 == 1) {
            cout << endl;
        }
        cout << obj._valueStr[pointer];
        count++;
        pointer++;
    }
    return os;
}

longnumber& longnumber::operator=(const longnumber& obj) {
    if (this != &obj) {
        if (_valueStr != nullptr) {
            delete[] _valueStr;
        }
        _isNegative = obj._isNegative;
        _isPositive = obj._isPositive;
        _digitNum = obj._digitNum;
        _valueStr = new char[_digitNum + 1];
        strcpy(_valueStr, obj._valueStr);
    }
    return *this;
}

bool longnumber::operator ==(const longnumber& obj) {
    return _isEqual(obj);
}

bool longnumber::operator !=(const longnumber& obj) {
    return !_isEqual(obj);
}

char longnumber::operator [](const int& i) {
    return _valueStr[i];
}

longnumber longnumber::operator +(const int& n) {
    return (*this) + longnumber(n);
}

longnumber longnumber::operator +(const longnumber& obj) {
    longnumber res = longnumber();
    if (_valueStr == nullptr || obj._valueStr == nullptr) {
        return res;
    }
    int aLen = this->_digitNum;
    int bLen = obj._digitNum;
    int maxLen = max(aLen, bLen) + 1;
    char* str = new char[maxLen + 1];
    str[maxLen] = '\0';
    int remain = 0;
    int pointerA = aLen - 1;
    int pointerB = bLen - 1;
    int pointerC = maxLen - 1;
    while (pointerC >= 0) {
        if (pointerA >= 0) {
            remain += this->_valueStr[pointerA] - '0';
            pointerA--;
        }
        if (pointerB >= 0) {
            remain += obj._valueStr[pointerB] - '0';
            pointerB--;
        }
        str[pointerC] = remain % 10 + '0';
        remain = remain / 10;
        pointerC--;
    }
    int start = 0;
    if (str[0] == '0') {
        res._digitNum = maxLen - 1;
        start = 1;
    }
    else {
        res._digitNum = maxLen;
    }
    res._valueStr = new char[res._digitNum + 1];
    res._valueStr[res._digitNum] = '\0';
    for (int i = 0; i < res._digitNum; i++) {
        res._valueStr[i] = str[i + start];
    }
    res._isNegative = false;
    res._isPositive = true;
    if (res._digitNum == 1 && res._valueStr[0] == '0') {
        res._isPositive = false;
    }
    delete[] str;
    return res;
}

longnumber longnumber::operator*(const int& n) {
    return (*this) * longnumber(n);
}

longnumber longnumber::operator *(const longnumber& obj) {
    longnumber res = longnumber();
    if (_valueStr == nullptr || obj._valueStr == nullptr) {
        return res;
    }
    int aLen = this->_digitNum;
    int bLen = obj._digitNum;
    const int cLen = aLen + bLen;
    char* str = new char[cLen + 1];
    for (int i = 0; i < cLen; i++) {
        str[i] = 0;
    }
    str[cLen] = '\0';
    int end = aLen - 1;
    for (int p1 = aLen - 1; p1 >= 0; p1--) {
        int add = 0;
        int p = cLen - 1 - (end - p1);
        for (int p2 = bLen - 1; p2 >= 0; p2--, p--) {
            int num1 = _valueStr[p1] - '0';
            int num2 = obj._valueStr[p2] - '0';
            int sum = num1 * num2 + add + str[p];
            str[p] = sum % 10;
            add = sum / 10;
        }
        while (add > 0) {
            str[p] += add;
            add = str[p] / 10;
            str[p] %= 10;
            p--;
        }
    }
    for (int i = 0; i < cLen; i++) {
        str[i] += '0';
    }
    for (int i = 0; i < cLen; i++) {
        if (str[i] != '0' || i == cLen - 1) {
            res._digitNum = cLen - i;
            res._valueStr = new char[res._digitNum + 1];
            strcpy(res._valueStr, str + i);
            break;
        }
    }
    if ((this->_isNegative && obj._isNegative) || (this->_isPositive && obj._isPositive)) {
        res._isPositive = true;
        res._isNegative = false;
    }
    else if ((this->_isNegative && obj._isPositive) || (this->_isPositive && obj._isNegative)) {
        res._isPositive = false;
        res._isNegative = true;
    }
    else {
        res._isPositive = false;
        res._isNegative = false;
    }
    delete[] str;
    return res;
}

longnumber longnumber::fact(const int& n) {
    longnumber res = longnumber(1);
    for (int i = 2; i <= n; i++) {
        res = res * longnumber(i);
    }
    return res;
}

bool longnumber::_isEqual(const longnumber& obj) {
    if (this->_isNegative != obj._isNegative ||this->_isPositive != obj._isPositive || this->_digitNum != obj._digitNum) {
        return false;
    }
    int pointer = 0;
    while (pointer < this->_digitNum) {
        if (this->_valueStr[pointer] != obj._valueStr[pointer]) {
            return false;
        }
        pointer++;
    }
    return true;;
}
//EOF


