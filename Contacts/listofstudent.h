#ifndef LISTOFSTUDENT_H
#define LISTOFSTUDENT_H

#include "student.h"
#include <vector>

class ListOfStudent
{
public:
    //ListOfStudent(ListOfStudent*);
    static ListOfStudent *GetListOfStudent();
    QString ShowStudents();
    void addStudent(Student*);
    bool Load(const QString);
    bool Save(const QString);

    std::vector<Student*> Students;
    int last_id = 0;
private:
    ListOfStudent();
};

#endif // LISTOFSTUDENT_H
