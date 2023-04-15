#include "salariedemployee.h"
#include "employee.h"

void salariedemployee::_init() {
    _w = nullptr;
    _s = 0;
}

void salariedemployee::_delete() {
    if (_w != nullptr) {
        delete[] _w;
    }
    _init();
}

void salariedemployee::_copy(const salariedemployee& se) {
    verifyAndCopyString(_w, se._w);
    _s = se._s;
}

salariedemployee::salariedemployee() {
    _init();
}

salariedemployee::salariedemployee(const char* f, const char* l, const char* ssn, const char* w, const double& s):employee(f, l, ssn){
    if (_show) {
        cout << "In salariedemployee::salariedemployee constructor " << f << " " << l << " " << ssn << " " << w << " " << s << endl; 
    }
    _init();
    verifyAndCopyString(_w, w);
    _s = s;
}

salariedemployee::salariedemployee(const salariedemployee& se):employee(se){
    if (_show) {
        cout << "In salariedemployee copy constructor ";
        cout << se << endl; 
    }
    _init();
    _copy(se);
}

salariedemployee::salariedemployee(salariedemployee&& se):employee(se) {
    if (_show) {
        cout << "In salariedemployee copy constructor ";
        cout << se << endl; 
    }
    _init();
    _w = se._w;
    _s = se._s;
    se._init();
}

salariedemployee::~salariedemployee() {
    if (_show) {
        cout << "In salariedemployee::~salariedemployee distructor ";
        cout << *this << endl; 
    }
    _delete();
}

salariedemployee& salariedemployee::operator=(const salariedemployee &se) {
    if (this != &se) {
        employee::operator=(se);
        _delete();
        _copy(se);
        if (_show) {
            cout << "In salariedemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

salariedemployee& salariedemployee::operator=(const employee& e) {
    if (this != &e) {
        employee::operator=(e);
        _delete();
        _copy(dynamic_cast<const salariedemployee&>(e));
        if (_show) {
            cout << "In salariedemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

ostream& salariedemployee::print(ostream &os) const {
    employee::print(os);
    os << " " << _w << " " << _s;
    return os;
}