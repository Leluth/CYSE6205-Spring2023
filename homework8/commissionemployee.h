#pragma once
#include "employee.h"

class commissionemployee: public employee {
public:
    char* _w;
    double _s;

    commissionemployee();
    commissionemployee(const char* f, const char* l, const char* ssn, const char* w, const double& s);
    commissionemployee(const commissionemployee& ce);
    commissionemployee(commissionemployee&& ce);
    virtual ~commissionemployee();
    commissionemployee& operator=(const commissionemployee& ce);
    virtual commissionemployee& operator=(const employee& e);
    virtual ostream& print(ostream& os) const;
    
private:
    void _init();
    void _delete();
    void _copy(const commissionemployee& ce);
};