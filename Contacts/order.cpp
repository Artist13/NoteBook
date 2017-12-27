#include "order.h"

Order::Order()
{

}

Order::Order(Order* myOrder)
{
    this->DateTime = myOrder->DateTime;
    this->OrderSubject = myOrder->OrderSubject;
    foreach (Student* st, myOrder->Students)
    {
        this->Students.push_back(st);
    }
}

void Order::AddStudent(Student* student)
{
    Students.push_back(student);
}
//Возвращает стоимость занятия с учетом ставки за него и дополнитьльной суммы за колличество учеников
int Order::Price()
{
    int price = 0;
    if(Students.size() > 5)
        price += 100;
    return price ;//+= TypeSubject->Price();
}

QString Order::ShowInfo()
{
    QString tempInfo = "";
    tempInfo += DateTime.toString("dd.MM.yyyy");
    tempInfo += "   " + OrderSubject.Name + " " + QString::number(OrderSubject.ClassNumber);
    return tempInfo;
}
