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
    QString Name();
    int ClassNumber();
    int Price();
    QLineEdit *NameOfSubject;
    QLineEdit *PriceOfSubject;
    QLineEdit *ClassOfSubject;
    QPushButton *cmdOk;
    QPushButton *cmdClose;
};

#endif // ADDSUBJECT_H
