#include "basepluscommissionemployee.h"
#include "commissionemployee.h"

void basepluscommissionemployee::_init() {
    _w = nullptr;
    _s = 0;
}

void basepluscommissionemployee::_delete() {
    if (_w != nullptr) {
        delete[] _w;
    }
    _init();
}

void basepluscommissionemployee::_copy(const basepluscommissionemployee& bce) {
    verifyAndCopyString(_w, bce._w);
    _s = bce._s;
}

basepluscommissionemployee::basepluscommissionemployee() {
    _init();
}

basepluscommissionemployee::basepluscommissionemployee(const char* f, const char* l, const char* ssn, const char* w1, const double& s1, const char* w2, const double& s2):commissionemployee(f, l, ssn, w1, s1){
    if (_show) {
        cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << f << " " << l << " " << ssn << " " << w1 << " " << s1 << " " << w2 << " " << s2 << endl; 
    }
    _init();
    verifyAndCopyString(_w, w2);
    _s = s2;
}

basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee& bce):commissionemployee(bce){
    if (_show) {
        cout << "In basepluscommissionemployee copy constructor ";
        cout << bce << endl;
    }
    _init();
    _copy(bce);
}

basepluscommissionemployee::basepluscommissionemployee(basepluscommissionemployee&& bce):commissionemployee(bce) {
    if (_show) {
        cout << "In basepluscommissionemployee copy constructor ";
        cout << bce << endl;
    }
    _init();
    _w = bce._w;
    _s = bce._s;
    bce._init();
}

basepluscommissionemployee::~basepluscommissionemployee() {
    if (_show) {
        cout << "In basepluscommissionemployee::~basepluscommissionemployee distructor ";
        cout << *this << endl; 
    }
    _delete();
}

basepluscommissionemployee& basepluscommissionemployee::operator=(const basepluscommissionemployee &bce) {
    if (this != &bce){
        commissionemployee::operator=(bce);
        _delete();
        _copy(bce);
        if(_show) {
            cout << "In basepluscommissionemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

basepluscommissionemployee& basepluscommissionemployee::operator=(const employee& e) {
    if (this != &e){
        commissionemployee::operator=(e);
        _delete();
        _copy(dynamic_cast<const basepluscommissionemployee&>(e));
        if(_show) {
            cout << "In basepluscommissionemployee equal constructor ";
            cout << *this << endl;
        }
    }
    return *this;
}

ostream& basepluscommissionemployee::print(ostream &os) const {
    commissionemployee::print(os);
    os << " " << _w << " " << _s;
    return os;
}