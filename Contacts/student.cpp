#include "student.h"

Student::Student() : Persone()
{

}

Student::Student(QString name, QString secondName) : Persone(name, secondName)
{
    ClassNumber = 0;
}

Student::Student(QString name, QString secondName, Subject studentSubject, int classNumber) : Persone(name, secondName)
{
    StudentSubject = studentSubject;
    ClassNumber = classNumber;
}

Student::~Student()
{

}

QString Student::ShowInfo()
{
    QString tempInfo = "";
    tempInfo = SecondName + "   " + Name + "   " + StudentSubject.Name + " " + StudentSubject.ClassNumber;
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
    this->StudentSubject = student->StudentSubject;
    this->ClassNumber = student->ClassNumber;
    return this;
}
