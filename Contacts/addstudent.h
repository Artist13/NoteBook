#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QAbstractButton>
#include <QComboBox>
#include "student.h"

namespace Ui {
class AddStudent;
}

class QLineEdit;
class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(Student* student = 0, QWidget *parent = 0);
    void init();
    ~AddStudent();
    QString Name() const;
    QString SecondName() const;
    QString Subject() const;
    int ClassNumber() const;
    Student* GetStudent() const;

private slots:


private:
    QLineEdit *m_Name;
    QLineEdit *m_SecondName;
    QLineEdit *m_ClassNumber;
    QComboBox *cbSubject;
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
