#ifndef INFORMAT_H
#define INFORMAT_H

#include "basetype.h"

class Informat //: public virtual BaseType
{
public:
    Informat();
    ~Informat();
    int Price();
private:
    int Stavka;
};

#endif // INFORMAT_H
