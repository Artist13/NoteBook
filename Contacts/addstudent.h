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
    QString GetName() const;
    QString GetSecondName() const;
    Subject GetSubject() const;
    int GetClassNumber() const;
    Student* GetStudent() const;
public slots:

private slots:
    void enableButton();
    bool checkingName();
    bool checkingSecondNmae();
    bool checkingClassNumber();

private:
    QLineEdit *m_Name;
    QLineEdit *m_SecondName;
    QLineEdit *m_ClassNumber;
    QComboBox *cbSubject;
    QPushButton *cmdOk;
    QPushButton *cmdCancel;
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
