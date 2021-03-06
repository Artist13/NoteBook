#include "addorder.h"

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "addstudent.h"
#include "listofsubjects.h"

#define MyStudents ListOfStudent::GetListOfStudent()->Students
#define MySubjects ListOfSubjects::GetListOfSubject()->Subjects

//
AddOrder::AddOrder(Order* order, QWidget *parent) : QDialog(parent)
{
    ui = new QWidget();
    QGridLayout *OrderLayout = new QGridLayout(ui);
    QLabel *lblDateTime = new QLabel("Дата");
    cbSubject = new QComboBox();
    foreach (Subject subj, MySubjects)
    {
        cbSubject->addItem(subj.Name + " " + QString::number(subj.ClassNumber));
    }
    //cbSubject->addItem("Информатика");
    //cbSubject->addItem("Математика");
    //cbSubject->addItem("Плашеты");
    QLabel *lblSubject = new QLabel("Предмет");
    leDateTime = new QLineEdit();
    QLabel *lblHours = new QLabel("Часы");
    leHours = new QLineEdit();
    cmdOk = new QPushButton("OK");
    cmdOk->setEnabled(false);
    cmdCancel = new QPushButton("Отмена");

    connect(cmdOk, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(cmdCancel, SIGNAL(clicked(bool)), SLOT(reject()));
    //Кнопка недоступна при незаполненых полях
    connect(leDateTime, SIGNAL(textChanged(QString)), SLOT(enableButton()));
    connect(leHours, SIGNAL(textChanged(QString)), SLOT(enableButton()));
    if(order == 0)
    {
        currentOrder = new Order();
        OrderLayout->addWidget(lblDateTime, 0, 0, 1, 2);
        OrderLayout->addWidget(leDateTime, 0, 1);
        OrderLayout->addWidget(lblSubject, 1, 0);
        OrderLayout->addWidget(cbSubject, 1, 1);
        OrderLayout->addWidget(lblHours, 2, 0);
        OrderLayout->addWidget(leHours, 2, 1);
        OrderLayout->addWidget(cmdOk, 3, 0);
        OrderLayout->addWidget(cmdCancel, 3, 1);
    }
    else
    {
        currentOrder = new Order(order);//Чтобы в конце вывести
        leDateTime->setText(order->DateTime.toString("dd.MM.yyyy"));
        cbSubject->activated(order->OrderSubject.Name + " " + QString::number(order->OrderSubject.ClassNumber));
       /* if(order->Subject == "Информатика")
        {
            cbSubject->activated("Информатика");
        }
        if(order->Subject == "Математика")
        {
            cbSubject->activated("Математика");
        }
        if(order->Subject == "Планшеты")
        {
            cbSubject->activated("Планшеты");
        }*/
        leHours->setText(QString::number(order->Hours));
        OrderStudent = new QListWidget(this);
        for(uint i = 0; i < order->Students.size(); i++)
        {
            OrderStudent->addItem(new QListWidgetItem(order->Students[i]->ShowInfo()));
        }
        QPushButton *cmdAdd = new QPushButton("Добавить ученика...");
        connect(cmdAdd, SIGNAL(clicked(bool)), SLOT(on_AddStudent_clicked()));
        connect(OrderStudent, SIGNAL(doubleClicked(QModelIndex)), SLOT(on_Student_dblclicked(QModelIndex)));
        OrderLayout->addWidget(OrderStudent, 0, 0, 3, 1);
        OrderLayout->addWidget(lblDateTime, 0, 1, 1, 2);
        OrderLayout->addWidget(leDateTime, 0 ,2);
        OrderLayout->addWidget(lblSubject, 1, 1);
        OrderLayout->addWidget(cbSubject, 1, 2);
        OrderLayout->addWidget(lblHours, 2, 1);
        OrderLayout->addWidget(leHours, 2, 2);
        OrderLayout->addWidget(cmdAdd, 3, 0);
        OrderLayout->addWidget(cmdOk, 3, 2);
        OrderLayout->addWidget(cmdCancel, 3, 3);
    }
    setLayout(OrderLayout);
    //ui->show();
}

void AddOrder::enableButton()
{
    if((leDateTime->text().isEmpty()) || (leHours->text().isEmpty()))
    {
        cmdOk->setEnabled(false);
    }
    else
    {
        cmdOk->setEnabled(true);
    }
}

AddOrder::~AddOrder()
{
    delete ui;
}

void AddOrder::UpdateForm()
{
    leDateTime->setText(currentOrder->DateTime.toString("dd.MM.yyyy"));
    cbSubject->activated(currentOrder->OrderSubject.Name + " " + QString::number(currentOrder->OrderSubject.ClassNumber));
    OrderStudent->clear();
    for(uint i = 0; i < currentOrder->Students.size(); i++)
    {
        OrderStudent->addItem(new QListWidgetItem(currentOrder->Students[i]->ShowInfo()));
    }
}

void AddOrder::on_AddStudent_clicked()
{
    QDialog *StDial = new QDialog();
    QListWidget *myStudents = new QListWidget(StDial);
    foreach (Student* st, MyStudents)
    {
        myStudents->addItem(new QListWidgetItem(st->ShowInfo()));
    }
    connect(myStudents, SIGNAL(doubleClicked(QModelIndex)), SLOT(on_ListOfStudent_dbclicked(QModelIndex)));
    StDial->setModal(true);
    StDial->setMinimumSize(350, 200);
    myStudents->setMinimumSize(350, 200);
    StDial->show();
}
//Выбор студента из существующего списка
void AddOrder::on_ListOfStudent_dbclicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    currentOrder->Students.push_back(MyStudents[index.row()]);
    UpdateForm();
}

//Выбор студента из списка студентов этого занятия
void AddOrder::on_Student_dblclicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    currentOrder->Students.erase(currentOrder->Students.begin() + index.row());
    UpdateForm();
}
//Если дни предсталены числом состоящим из одной цифры
QString GetValidDate(QString DateTime)
{
    QStringList date = DateTime.split('.');
    if(date.first().size() < 2)
        date.first() = '0' + date.first();
    QString ValidDateTime = date.first() + '.' + date.at(1) + '.' + date.last();
    return ValidDateTime;
}

Order* AddOrder::GetOrder()
{

    currentOrder->DateTime = QDateTime::fromString(GetValidDate(leDateTime->text()), "dd.MM.yyyy");
    QStringList subject = cbSubject->currentText().split(' ');
    currentOrder->OrderSubject.Name = subject.first();
    QString classNumber = subject.last();
    currentOrder->OrderSubject.ClassNumber = classNumber.toInt();
    currentOrder->Hours = leHours->text().toDouble();
    return currentOrder;
}
