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
    QString ShowOrders();
    void AddOrder(Order*);
    bool Load(const QString);
    bool Save(const QString);
    QString GetReport();


    std::vector<Order*> Orders;
private:
    ListOfStudent *AllStudents;
};

#endif // BOOKOFORDER_H
