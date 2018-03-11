/*
 * Объект для добавления/изменения предмета
 * Описание предметов хранится в xml файле(ах)
 */
#ifndef ADDSUBJECT_H
#define ADDSUBJECT_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "subject.h"


class AddSubject : public QDialog
{
    Q_OBJECT
public:
    explicit AddSubject(QWidget *parent = nullptr);
    Subject GetSubject();
signals:

public slots:
private:
    QString Name();//Название предмета
    int ClassNumber();//Каждый предмет рассчитан на опреленый класс
    int Price();//Цена за 1 час проведения занятия
    QLineEdit *NameOfSubject;//Поле для названия
    QLineEdit *PriceOfSubject;//Поле для ввода цены
    QLineEdit *ClassOfSubject;//Поле для ввода номера класса
    QPushButton *cmdOk;//Кнопка подтверждения
    QPushButton *cmdClose;//Кнопка отмены
};

#endif // ADDSUBJECT_H
