#include "addorder.h"

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "addstudent.h"

//
AddOrder::AddOrder(ListOfStudent *myStudents, Order* order, QWidget *parent) : QDialog(parent)
{
    ui = new QWidget();
    AllStudents = myStudents;
    QGridLayout *OrderLayout = new QGridLayout(ui);
    QLabel *lblDateTime = new QLabel("Дата");
    //Заменить String на выбор предмета из ComboBox
    cbSubject = new QComboBox();
    cbSubject->addItem("Информатика");
    cbSubject->addItem("Математика");
    cbSubject->addItem("Плашеты");
    QLabel *lblSubject = new QLabel("Предмет");
    leDateTime = new QLineEdit();
    QLabel *lblHours = new QLabel("Часы");
    leHours = new QLineEdit();
    QPushButton *cmdOk = new QPushButton("OK");
    QPushButton *cmdCancel = new QPushButton("Отмена");

    connect(cmdOk, SIGNAL(clicked(bool)), SLOT(accept()));
    connect(cmdCancel, SIGNAL(clicked(bool)), SLOT(reject()));
    if(order == 0)
    {
        currentOrder = new Order();
        OrderLayout->addWidget(lblDateTime, 0, 0, 1, 2);
        OrderLayout->addWidget(leDateTime, 0, 1);
        OrderLayout->addWidget(lblSubject, 1, 0);
        OrderLayout->addWidget(cbSubject, 1, 1);
        OrderLayout->addWidget(lblHours, 2, 0);
        OrderLayout->addWidget(leHours, 2, 1);
        OrderLayout->addWidget(cmdOk, 3, 1);
        OrderLayout->addWidget(cmdCancel, 3, 2);
    }
    else
    {
        currentOrder = new Order(order);
        leDateTime->setText(order->DateTime.toString("dd.MM.yyyy"));
        cbSubject->activated(order->Subject);
        if(order->Subject == "Информатика")
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
        }
        leHours->setText(QString::number(order->Hours));
        OrderStudent = new QListWidget(this);
        for(uint i = 0; i < order->Students.size(); i++)
        {
            OrderStudent->addItem(new QListWidgetItem(order->Students[i]->ShowInfo()));
        }
        QPushButton *cmdAdd = new QPushButton("Lj,fdbnm extybrf...");
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

AddOrder::~AddOrder()
{
    delete leDateTime;
    delete cbSubject;
    delete ui;
}

void AddOrder::UpdateForm()
{
    leDateTime->setText(currentOrder->DateTime.toString("dd.MM.yyyy"));
    cbSubject->activated(currentOrder->Subject);
    OrderStudent->clear();
    for(uint i = 0; i < currentOrder->Students.size(); i++)
    {
        OrderStudent->addItem(new QListWidgetItem(currentOrder->Students[i]->ShowInfo()));
    }
}

void AddOrder::on_AddStudent_clicked()
{
    QDialog *StDial = new QDialog();
    QListWidget *MyStudents = new QListWidget(StDial);
    foreach (Student* st, AllStudents->Students)
    {
        MyStudents->addItem(new QListWidgetItem(st->ShowInfo()));
    }
    connect(MyStudents, SIGNAL(doubleClicked(QModelIndex)), SLOT(on_ListOfStudent_dbclicked(QModelIndex)));
    StDial->setModal(true);
    StDial->setMinimumSize(350, 200);
    MyStudents->setMinimumSize(350, 200);
    StDial->show();
}
//Выбор студента из существующего списка
void AddOrder::on_ListOfStudent_dbclicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    currentOrder->Students.push_back(AllStudents->Students[index.row()]);
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
    /*AddStudent *Edit = new AddStudent(currentOrder->Students[index.row()], this);
    if(Edit->exec() == QDialog::Accepted)
    {
        currentOrder->Students[index.row()] = Edit->GetStudent();
    }*/
    UpdateForm();
}

Order* AddOrder::GetOrder()
{
    currentOrder->DateTime = QDateTime::fromString(leDateTime->text(), "dd.MM.yyyy");
    currentOrder->Subject = cbSubject->currentText();
    return currentOrder;
}
