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
    QString Name;
    int Price;
    int ClassNumber;
private:

};

#endif // SUBJECT_H
