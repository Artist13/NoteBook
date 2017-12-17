#ifndef BASETYPE_H
#define BASETYPE_H


class BaseType
{
public:
    BaseType();
    virtual ~BaseType();
    virtual int Price() = 0;
};

#endif // BASETYPE_H
