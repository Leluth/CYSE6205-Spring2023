#pragma once
#include "employee.h"

class salariedemployee: public employee {
public:
    char* _w;
    double _s;

    salariedemployee();
    salariedemployee(const char* f, const char* l, const char* ssn, const char* w, const double& s);
    salariedemployee(const salariedemployee& se);
    salariedemployee(salariedemployee&& se);
    virtual ~salariedemployee();
    salariedemployee& operator=(const salariedemployee& se);
    virtual salariedemployee& operator=(const employee& e);
    virtual ostream& print(ostream& os) const;

private:
    void _init();
    void _delete();
    void _copy(const salariedemployee& se);
};