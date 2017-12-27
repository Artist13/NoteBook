#ifndef ORDER_H
#define ORDER_H

#include "student.h"
#include "subject.h"
#include <vector>
#include <QDateTime>
#include "basetype.h"

class Order
{
public:
    Order();
    Order(Order*);
    QString ShowInfo();
    void AddStudent(Student*);
    int Price();

    BaseType *TypeSubject;
    std::vector<Student*> Students;
    QDateTime DateTime;
    Subject OrderSubject;
    //QString Subject;
    double Hours;
};

#endif // ORDER_H
