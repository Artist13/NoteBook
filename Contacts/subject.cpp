#include "subject.h"

Subject::Subject()
{
    Name = "Some subject";
    ClassNumber = 0;
    Price = 0;
}

Subject::Subject(QString name, int classNumber, int price) : Name(name), ClassNumber(classNumber), Price(price)
{

}

QString Subject::GetName()
{
    return Name;
}

int Subject::GetClassNumber()
{
    return ClassNumber;
}

int Subject::GetPrice()
{
    return Price;
}

QString Subject::GetInfo()
{
    QString temp = Name;
    if(ClassNumber != 0)
        temp += " " + QString::number(ClassNumber);
    return temp;
}
