#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>

class Subject
{
public:
    Subject();
    Subject(QString name, int classNumber, int price);

    int GetPrice();
    QString GetName();
    int GetClassNumber();
private:
    QString Name;
    int Price;
    int ClassNumber;
};

#endif // SUBJECT_H
