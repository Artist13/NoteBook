#include "addsubject.h"
#include <QGridLayout>

AddSubject::AddSubject(QWidget *parent) : QDialog(parent)
{
    QGridLayout *MyLayaout = new QGridLayout(this);
    QLabel *lblName = new QLabel("Название");
    QLabel *lblClass = new QLabel("Класс");
    QLabel *lblPrice = new QLabel("Цена");
    NameOfSubject = new QLineEdit();
    PriceOfSubject = new QLineEdit();
    ClassOfSubject = new QLineEdit();
    cmdClose = new QPushButton("Отмена");
    cmdOk = new QPushButton("Ок");

    connect(cmdOk, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(cmdClose, SIGNAL(clicked(bool)), SLOT(reject()));

    MyLayaout->addWidget(lblName, 0, 0);
    MyLayaout->addWidget(NameOfSubject, 0, 1);
    MyLayaout->addWidget(lblClass, 1, 0);
    MyLayaout->addWidget(ClassOfSubject, 1, 1);
    MyLayaout->addWidget(lblPrice, 2, 0);
    MyLayaout->addWidget(PriceOfSubject, 2, 1);
    MyLayaout->addWidget(cmdOk, 3, 0);
    MyLayaout->addWidget(cmdClose,3 , 1);
}

QString AddSubject::Name()
{
    return NameOfSubject->text();
}

int AddSubject::ClassNumber()
{
    return ClassOfSubject->text().toInt();
}

int AddSubject::Price()
{
    return PriceOfSubject->text().toInt();
}

Subject AddSubject::GetSubject()
{
    Subject currentSubject(Name(), ClassNumber(), Price());
    return currentSubject;
}
