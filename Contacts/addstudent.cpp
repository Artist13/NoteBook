#include "addstudent.h"
#include "ui_addstudent.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QRegExpValidator>

AddStudent::AddStudent(Student *student, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    this->setModal(true);
    init();
    if(student != 0)
    {
        m_Name->setText(student->Name);
        m_SecondName->setText(student->SecondName);
        cbSubject->activated(student->Subject);
        if(student->ClassNumber > 0)
            m_ClassNumber->setText(QString::number(student->ClassNumber));
    }
}

void AddStudent::init()
{
    m_Name  = new QLineEdit;
    m_SecondName = new QLineEdit;
    cbSubject = new QComboBox();
    cbSubject->addItem("Информатика");
    cbSubject->addItem("Математика");
    cbSubject->addItem("Планшеты");
    m_ClassNumber = new QLineEdit;
    QLabel *lblName = new QLabel("Имя");
    QLabel *lblSecondName = new QLabel("Фамилия");
    QLabel *lblSubject = new QLabel("Предмет");
    QLabel *lblClassNumber = new QLabel("Класс");
    cmdOk = new QPushButton("OK");
    //Изначально кнопка недоступна
    cmdOk->setEnabled(false);

    cmdCancel = new QPushButton("Cancel");
    connect(cmdOk, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(cmdCancel, SIGNAL(clicked(bool)), SLOT(reject()));
    //Кнопка недоступна пока поля незаполнены
    connect(m_Name, SIGNAL(textChanged(QString)), SLOT(enableButton()));
    connect(m_SecondName, SIGNAL(textChanged(QString)), SLOT(enableButton()));
    connect(m_ClassNumber, SIGNAL(textChanged(QString)), SLOT(enableButton()));
    //----------------------------------------------------------------------
    //Проверка полей
    connect(m_Name, SIGNAL(textChanged(QString)), SLOT(checkingName()));
    connect(m_SecondName, SIGNAL(textChanged(QString)), SLOT(checkingSecondNmae()));
    connect(m_ClassNumber, SIGNAL(textChanged(QString)), SLOT(checkingClassNumber()));
    //--------------------------------------------------------------------------
    QGridLayout *Layout = new QGridLayout;
    Layout->addWidget(lblName, 0, 0);
    Layout->addWidget(m_Name, 0, 1);
    Layout->addWidget(lblSecondName, 1, 0);
    Layout->addWidget(m_SecondName, 1, 1);
    Layout->addWidget(lblSubject, 2, 0);
    Layout->addWidget(cbSubject, 2, 1);
    Layout->addWidget(lblClassNumber, 3, 0);
    Layout->addWidget(m_ClassNumber, 3, 1);
    Layout->addWidget(cmdOk , 4, 0);
    Layout->addWidget(cmdCancel, 4 ,1);
    setLayout(Layout);
    ui->setupUi(this);

}

void AddStudent::enableButton()
{
    if((m_Name->text().isEmpty()) || (m_SecondName->text().isEmpty()) || (m_ClassNumber->text().isEmpty()))
    {
        cmdOk->setEnabled(false);
    }
    else
    {
        cmdOk->setEnabled(true);
    }
}

bool AddStudent::checkingName()
{
    if(m_Name->text().isEmpty())
    {
        m_Name->setStyleSheet("QLineEdit {background-color: red;}");
        return false;
    }
    else
    {
        m_Name->setStyleSheet("QLineEdit {background-color: green;}");
        return true;
    }
}

bool AddStudent::checkingSecondNmae()
{
    if(m_SecondName->text().isEmpty())
    {
        m_SecondName->setStyleSheet("QLineEdit {background-color: red;}");
        return false;
    }
    else
    {
        m_SecondName->setStyleSheet("QLineEdit {background-color: green;}");
        return true;
    }
}

bool AddStudent::checkingClassNumber()
{
    int pos = 0;
    QRegExpValidator validator(QRegExp("[0-9][0-9]"));
    QString classNumber = m_ClassNumber->text();
    if((m_ClassNumber->text().isEmpty()) || validator.validate(classNumber, pos) == QValidator::Invalid)
    {
        m_ClassNumber->setStyleSheet("QLineEdit {background-color: red;}");
        return false;
    }
    else
    {
        m_ClassNumber->setStyleSheet("QLineEdit {background-color: green;}");
        return true;
    }
}

AddStudent::~AddStudent()
{
    delete m_Name;
    delete m_SecondName;
    delete cbSubject;
    delete m_ClassNumber;
    delete ui;
}

QString AddStudent::Name() const
{
    return m_Name->text();
}

QString AddStudent::SecondName() const
{
    return m_SecondName->text();
}

QString AddStudent::Subject() const
{
    return cbSubject->currentText();
}

int AddStudent::ClassNumber() const
{
    return m_ClassNumber->text().toInt();
}

Student* AddStudent::GetStudent() const
{
    return new Student(Name(), SecondName(), Subject(), ClassNumber());
}
