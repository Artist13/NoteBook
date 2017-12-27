#include "listofsubjects.h"

ListOfSubjects::ListOfSubjects()
{

}

ListOfSubjects* ListOfSubjects::GetListOfSubject()
{
    static ListOfSubjects MyListOfSubjects;
    return &MyListOfSubjects;
}

Subject ListOfSubjects::operator[](int index)
{
    if(index < Subjects.size())
        return Subjects[index];
    else
        throw;
}

QVector<Subject> ListOfSubjects::Find(QString name)
{
    QVector<Subject> temp;
    for(int i = 0; i < Subjects.size(); i++)
    {
        if(Subjects[i].GetName() == name)
            temp.push_back(Subjects[i]);
    }
    return temp;
}

void ListOfSubjects::AddSubject(Subject subject)
{
    Subjects.push_back(subject);
}

int ListOfSubjects::Size()
{
    return Subjects.size();
}
