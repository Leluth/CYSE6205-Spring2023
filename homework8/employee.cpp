#include "employee.h"

bool employee::_show = true;

void employee::_init() {
    _f = nullptr;
    _l = nullptr;
    _s = nullptr;
}

void employee::_delete() {
    if (_f != nullptr) {
        delete[] _f;
    }
    if (_l != nullptr) {
        delete[] _l;
    }
    if (_s != nullptr) {
        delete[] _s;
    }
    _init();
}

employee::employee() {
    _init();
}

employee::employee(const char* f, const char* l, const char* s){
    if (_show) {
        printf("In employee::employee constructor %s %s %s\n", f, l, s); 
    }
    _init();
    verifyAndCopyString(_f, f);
    verifyAndCopyString(_l, l);
    verifyAndCopyString(_s, s);
}

employee::employee(const employee& e) {
    if (_show) {
        printf("In employee copy constructor %s %s %s\n", e._f, e._l, e._s); 
    }
    _init();
    _delete();
    verifyAndCopyString(_f, e._f);
    verifyAndCopyString(_l, e._l);
    verifyAndCopyString(_s, e._s);
}

employee::employee(employee&& e) {
    if(_show) {
        printf("In employee copy constructor %s %s %s\n", e._f, e._l, e._s); 
    }
    _init();
    _f = e._f;
    _l = e._l;
    _s = e._s;
    e._init();
}

employee::~employee() {
    if (_show) {
        printf("In employee::~employee distructor %s %s %s\n", _f, _l, _s); 
    }
    _delete();
}

void employee::setShow(bool show) {
    _show = show;
}

ostream& operator<<(ostream& os, const employee& e) {
    e.print(os);
    return os;
}

employee& employee::operator=(const employee &e) {
    if (this != &e) {
        _delete();
        verifyAndCopyString(_f, e._f);
        verifyAndCopyString(_l, e._l);
        verifyAndCopyString(_s, e._s);
        if (_show) {
            printf("In employee equal constructor ");
            cout << *this << endl; 
        }
    }
    return *this;
}

ostream& employee::print(ostream &os) const {
    os << _f << " " << _l << " " << _s;
    return os;
}

void employee::verifyAndCopyString(char*& s1, const char *s2) {
    if (s1 != nullptr) {
        delete[] s1;
    }
    if (s2 == nullptr) {
        s1 = nullptr;
        return;
    }
    s1 = new char[strlen(s2) + 1];
    strcpy(s1, s2);
}