#ifndef ADDORDER_H
#define ADDORDER_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QComboBox>
#include "order.h"
#include "listofstudent.h"


class AddOrder : public QDialog
{
    Q_OBJECT
public:
    explicit AddOrder(Order* = 0,QWidget *parent = nullptr);
    Order* GetOrder();
    ~AddOrder();
private:
    QLineEdit *leDateTime;
    QComboBox *cbSubject;
    QWidget *ui;
    QListWidget *OrderStudent;
    Order * currentOrder;
    QLineEdit *leHours;
    void UpdateForm();
signals:

public slots:
    void on_AddStudent_clicked();
    void on_ListOfStudent_dbclicked(const QModelIndex &index);
    void on_Student_dblclicked(const QModelIndex &index);

};

#endif // ADDORDER_H
