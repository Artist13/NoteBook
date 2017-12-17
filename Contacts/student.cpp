#include "student.h"

Student::Student() : Persone()
{

}

Student::Student(QString name, QString secondName) : Persone(name, secondName)
{
    ClassNumber = 0;
}

Student::Student(QString name, QString secondName, QString subject, int classNumber) : Persone(name, secondName)
{
    Subject = subject;
    ClassNumber = classNumber;
}

Student::~Student()
{

}

QString Student::ShowInfo()
{
    QString tempInfo = "";
    tempInfo = SecondName + "   " + Name + "   " + Subject;
    if(ClassNumber > 0)
    {
        tempInfo += "   " + QString::number(ClassNumber);
    }
    return tempInfo;
}

Student* Student::operator =(Student *student)
{
    this->Name = student->Name;
    this->SecondName = student->SecondName;
    this->Subject = student->Subject;
    this->ClassNumber = student->ClassNumber;
    return this;
}
