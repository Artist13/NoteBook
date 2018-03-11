/*
 * Класс описывающий занятие
 */
#ifndef ORDER_H
#define ORDER_H

#include "student.h"
#include "subject.h"
#include <vector>
#include <QDateTime>
#include "basetype.h"

class Order
{
public:
    Order();
    Order(Order*);
    Order(QDateTime, Subject, double hours, std::vector<Student*> students);
    QString ShowInfo();//Функция для отображения занятия в программе
    void AddStudent(Student*);//Добавление ученика по указателю
    int Price();//Рассчет стоимости

    BaseType *TypeSubject;//Указатель на предмет
    std::vector<Student*> Students;//Список учеников
    QDateTime DateTime;//Дата занятия
    Subject OrderSubject;//Предмет. Два предмета
    //QString Subject;
    double Hours;//Длительность занятия
};

#endif // ORDER_H
