/*
 *Объект создается при добавлении/изменении ученика
 */

#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QAbstractButton>
#include <QComboBox>
#include "student.h"

namespace Ui {
class AddStudent;//Отдельная ЮИ. Зачем?
}

class QLineEdit;
class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(Student* student = 0, QWidget *parent = 0);
    void init();
    ~AddStudent();
    QString GetName() const;//Получение значения имени
    QString GetSecondName() const;//Получение значения фамилии
    Subject GetSubject() const;//Получение значения предмета
    int GetClassNumber() const;//Получение значения класса
    Student* GetStudent() const;//Получение указателя на ученика
public slots:

private slots:
    void enableButton();//Делает кнопку доступной при заполнении всех полей
    bool checkingName();//Проверка валидности имени
    bool checkingSecondNmae();//Проверка валидности фамилии
    bool checkingClassNumber();//Проверка валидности номера класса

private:
    QLineEdit *m_Name;//Поле для имени
    QLineEdit *m_SecondName;//Поле для фамилии
    QLineEdit *m_ClassNumber;//Поле для номера класса
    QComboBox *cbSubject;//Комбо-бокс для выбора предмета
    QPushButton *cmdOk;//Кнопка подтверждения
    QPushButton *cmdCancel;//Кнопка отмены
    Ui::AddStudent *ui;//Указатель на ЮИ
};

#endif // ADDSTUDENT_H
