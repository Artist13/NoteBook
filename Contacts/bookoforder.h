/*
 * Объект для хранения списка занятий.
 */
#ifndef BOOKOFORDER_H
#define BOOKOFORDER_H
#include "order.h"
#include <vector>
#include "listofstudent.h"

class BookOfOrder
{
public:
    BookOfOrder(ListOfStudent *myStudents);
    ~BookOfOrder();
    QString ShowOrders();//Возвращает строку с названием предмета
    void AddOrder(Order*);//Функция для добавления занятия, путем передачи его по указателю
    bool Load(const QString);//Загрузка списка из xml файла
    bool Save(const QString);//Сохранение в xml файл
    void GetReport(const QString outputFile);//Преобразование данных списка в ежемесячный отчет. Не используется в связи с отменой отчетов.


    std::vector<Order*> Orders;//Список занятий
private:
    ListOfStudent *AllStudents;//Список студентов??? Студенты хранятся в "одиночках"
};

#endif // BOOKOFORDER_H
