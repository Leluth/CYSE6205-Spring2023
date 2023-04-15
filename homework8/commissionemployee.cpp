#include "commissionemployee.h"
#include "employee.h"

void commissionemployee::_init() {
    _w = nullptr;
    _s = 0;
}

void commissionemployee::_delete() {
    if (_w != nullptr) {
        delete[] _w;
    }
    _init();
}

void commissionemployee::_copy(const commissionemployee& ce) {
    verifyAndCopyString(_w, ce._w);
    _s = ce._s;
}

commissionemployee::commissionemployee() {
    _init();
}

commissionemployee::commissionemployee(const char* f, const char* l, const char* ssn, const char* w, const double& s):employee(f, l, ssn){
    if (_show) {
        cout << "In commissionemployee::commissionemployee constructor " << f << " " << l << " " << ssn << " " << w << " " << s << endl; 
    }
    _init();
    verifyAndCopyString(_w, w);
    _s = s;
}

commissionemployee::commissionemployee(const commissionemployee& ce):employee(ce){
    if (_show) {
        cout << "In commissionemployee copy constructor ";
        ce.commissionemployee::print(cout);
        cout << endl;
    }
    _init();
    _copy(ce);
}

commissionemployee::commissionemployee(commissionemployee&& ce) :employee(ce) {
    if (_show) {
        cout << "In commissionemployee copy constructor ";
        ce.commissionemployee::print(cout);
        cout << endl;
    }
    _init();
    _w = ce._w;
    _s = ce._s;
    ce._init();
}

commissionemployee::~commissionemployee() {
    if (_show) {
        cout << "In commissionemployee::~commissionemployee distructor ";
        cout << *this << endl; 
    }
    _delete();
}

commissionemployee& commissionemployee::operator=(const commissionemployee &ce) {
    if (this != &ce) {
        employee::operator=(ce);
        _delete();
        _copy(ce);
        if(_show) {
            cout << "In commissionemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

commissionemployee& commissionemployee::operator=(const employee& e) {
    if (this != &e) {
        employee::operator=(e);
        _delete();
        _copy(dynamic_cast<const commissionemployee&>(e));
        if(_show) {
            cout << "In commissionemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

ostream& commissionemployee::print(ostream &os) const {
    employee::print(os);
    os << " " << _w << " " << _s;
    return os;
}