#ifndef LISTOFSUBJECTS_H
#define LISTOFSUBJECTS_H

#include "subject.h"
#include <QVector>

class ListOfSubjects
{
public:
    static ListOfSubjects* GetListOfSubject();
    Subject operator[](int index);//Нужно ли это здесь
    QVector<Subject> Find(QString name);
    void AddSubject(Subject subject);
    int Size();
    QVector<Subject> Subjects;
    void Load(const QString);
    void Save(const QString);
private:
    ListOfSubjects();

};

#endif // LISTOFSUBJECTS_H
