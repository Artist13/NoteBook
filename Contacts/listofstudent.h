#ifndef LISTOFSTUDENT_H
#define LISTOFSTUDENT_H

#include "student.h"
#include <vector>

class ListOfStudent
{
public:
    ListOfStudent();
    ListOfStudent(ListOfStudent*);
    QString ShowStudents();
    void addStudent(Student*);
    bool Load(const QString);
    bool Save(const QString);

    std::vector<Student*> Students;
    int last_id;
};

#endif // LISTOFSTUDENT_H
