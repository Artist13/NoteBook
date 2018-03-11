/*
 * Класс модели предметов наследующийся от BaseType
 */
#ifndef INFORMAT_H
#define INFORMAT_H

#include "basetype.h"

class Informat //: public virtual BaseType
{
public:
    Informat();
    ~Informat();
    int Price();//Возвращает цену? Стоимость?
private:
    int Stavka;//Цена за час???
};

#endif // INFORMAT_H
