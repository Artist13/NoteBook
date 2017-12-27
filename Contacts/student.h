#ifndef STUDENT_H
#define STUDENT_H
#include "persone.h"
#include "listofsubjects.h"

class Student : public Persone
{
public:
    Student();
    Student(QString name, QString secondName);
    Student(QString name, QString secondName, Subject studentSubject, int classNumber);
    QString ShowInfo();
    ~Student();

    Student* operator =(Student*);

    Subject StudentSubject;
    int ClassNumber;
};

#endif // STUDENT_H
