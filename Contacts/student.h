/*
 * Класс описывающий ученика
 */
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
    QString ShowInfo();//Передает объект для отображения в программе
    ~Student();

    Student* operator =(Student*);

    Subject StudentSubject;//Предмет, который изучает учник. Можно сделать список, если ученик изучает несколько предметов
    int ClassNumber;//В каком классе учится ученик
};

#endif // STUDENT_H
