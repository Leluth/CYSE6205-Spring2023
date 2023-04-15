#pragma once

using namespace std;
#include <iostream>
#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif
#include <vector>
#include <string>

class employee {
public:
    char* _f;
    char* _l;
    char* _s;
    static bool _show;

    employee();
    employee(const char* f, const char* l, const char* s);
    employee(const employee& e);
    employee(employee&& e);
    virtual ~employee();
    static void setShow(bool show);
    friend ostream& operator<<(ostream& os, const employee& e);
    virtual employee& operator=(const employee& e);
    virtual ostream& print(ostream& os) const;
    void verifyAndCopyString(char* &s1, const char* s2);
    
private:
    void _init();
    void _delete();
};