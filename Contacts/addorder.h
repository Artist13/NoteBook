/*
Объект формы отвечающий за добавление/редактирование занятия
Создается при нажатии на кнопку(и) добавить/изменить занятие
*/
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
    QLineEdit *leDateTime;//Поле для ввода даты занятия
    QComboBox *cbSubject;//Комбо-бокс для выбора предмета
    QWidget *ui;//Указатель на ЮИ?
    QListWidget *OrderStudent;//Список студентов присутствовавших на занятии
    Order * currentOrder;//Указатель на текущее занятие, если производится редактирование
    QPushButton *cmdOk;//Кнопка подтверждения
    QPushButton *cmdCancel;//Кнопка отмены
    QLineEdit *leHours;//Поле для указания длительности занятия. Необходима для расчета стоимости
    void UpdateForm();
signals:

private slots:
    void on_AddStudent_clicked();//Обработка нажатия на кнопку добавить ученика
    void on_ListOfStudent_dbclicked(const QModelIndex &index);//Обработка нажатия на ученика в списке всех учеников???
    void on_Student_dblclicked(const QModelIndex &index);//Вот это обработка нажатия на ученика
    void enableButton();//Активирует кнопку подтверждения при заполнении всех полей

};

#endif // ADDORDER_H
