#pragma once
#include "commissionemployee.h"

class basepluscommissionemployee: public commissionemployee {
public:
    char* _w;
    double _s;

    basepluscommissionemployee();
    basepluscommissionemployee(const char* f, const char* l, const char* ssn, const char* w1, const double& s1, const char* w2, const double& s2);
    basepluscommissionemployee(const basepluscommissionemployee& bce);
    basepluscommissionemployee(basepluscommissionemployee&& bce);
    virtual ~basepluscommissionemployee();
    basepluscommissionemployee& operator=(const basepluscommissionemployee& bce);
    virtual basepluscommissionemployee& operator=(const employee& bce);
    virtual ostream& print(ostream& os) const;

private:
    void _init();
    void _delete();
    void _copy(const basepluscommissionemployee& bce);
};