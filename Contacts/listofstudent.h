/*
 * Список студентов. Представляет из себя реализацию шаблона "Одиночкка"
 */
#ifndef LISTOFSTUDENT_H
#define LISTOFSTUDENT_H

#include "student.h"
#include <vector>

class ListOfStudent
{
public:
    //ListOfStudent(ListOfStudent*);
    static ListOfStudent *GetListOfStudent();//Указатель на сущность списка. Для получения объекта списка.
    QString ShowStudents();//Возвращает строку для вывода в программе. Фамилия имя класс
    void addStudent(Student*);//Добавляет ученика, переданного по указателю
    void addStudent(Student *, int id);//Добавляет ученика, переданного по указателю с учетом id???
    bool Load(const QString);//Загружает список из файла xml
    bool Save(const QString);//Сохраняет список в файл xml

    std::vector<Student*> Students;//Список учеников
    int last_id = 0;//ID последнего добавленного ученика
private:
    ListOfStudent();//Конструктор скрыт в соответствии с шаблоном
};

#endif // LISTOFSTUDENT_H
