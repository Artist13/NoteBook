#ifndef STUDENT_H
#define STUDENT_H
#include "persone.h"

class Student : public Persone
{
public:
    Student();
    Student(QString, QString);
    Student(QString, QString, QString, int);
    QString ShowInfo();
    ~Student();

    Student* operator =(Student*);

    QString Subject;
    int ClassNumber;
};

#endif // STUDENT_H
