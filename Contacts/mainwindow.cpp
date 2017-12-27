#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstudent.h"
#include "addorder.h"
#include "listofsubjects.h"
#include "subjectswidget.h"

#include <QWidget>
#include <QMessageBox>
#include <QMenuBar>
#include <QFileDialog>
#include <QVBoxLayout>

#define MyStudents ListOfStudent::GetListOfStudent()
//#define ListOfSubjects ListOfSubjects::GetListOfSubject()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyBook = new BookOfOrder(MyStudents);
    MyStudents->Load("TestStudents.xml");
    ListOfSubjects::GetListOfSubject()->Load("TestSubjects.xml");
    UpdateList(MyStudents->Students);
}

MainWindow::~MainWindow()
{
    MyStudents->Save("TestStudents.xml");
    ListOfSubjects::GetListOfSubject()->Save("TestSubjects.xml");
    delete MyBook;
    delete ui;
}

void MainWindow::UpdateList(std::vector<Student*> students)
{
    ui->listWidget->clear();
    for(uint i = 0; i < students.size(); i++)
    {
        ui->listWidget->addItem(new QListWidgetItem(students[i]->ShowInfo()));
    }
}

void MainWindow::on_AddPerson_clicked()
{
    AddStudent *AddNew = new AddStudent();
    if(AddNew->exec() == QDialog::Accepted)
    {
        MyStudents->addStudent(AddNew->GetStudent());
    }
    UpdateList(MyStudents->Students);
    delete AddNew;
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    AddStudent *Edit = new AddStudent(MyStudents->Students[index.row()]);
    if(Edit->exec() == QDialog::Accepted)
    {
        MyStudents->Students[index.row()] = Edit->GetStudent();
    }
    UpdateList(MyStudents->Students);
    delete Edit;
}

void MainWindow::on_actionLoad_triggered()
{
    if(MyBook->Load(QFileDialog::getOpenFileName(this,
                                                 QString("Открыть список занятий"),
                                                 QString(),
                                                 QString("Список занятий(*.xml)"))))
        UpdateListOfOrder(MyBook->Orders);
}

void MainWindow::on_actionSave_triggered()
{
    MyBook->Save(QFileDialog::getSaveFileName(this,
                                              QString("Выберите файл для сохранения"),
                                              QString(),
                                              QString("Список занятий(*.xml)")));
}
void MainWindow::UpdateListOfOrder(std::vector<Order*> orders)
{
    ui->ListOfOrders->clear();
    for(uint i = 0; i < orders.size(); i++)
    {
        ui->ListOfOrders->addItem(new QListWidgetItem(orders[i]->ShowInfo()));
    }
}
void MainWindow::on_AddOrder_clicked()
{
    AddOrder *NewOrder = new AddOrder();
    if(NewOrder->exec() == QDialog::Accepted)
    {
        MyBook->AddOrder(NewOrder->GetOrder());
    }
    UpdateListOfOrder(MyBook->Orders);
    delete NewOrder;
}

void MainWindow::on_ListOfOrders_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
    {
        return;
    }
    AddOrder *Edit = new AddOrder(MyBook->Orders[index.row()]);
    if(Edit->exec() == QDialog::Accepted)
    {
        MyBook->Orders[index.row()] = Edit->GetOrder();
    }
    UpdateListOfOrder(MyBook->Orders);
    delete Edit;
}

void MainWindow::on_Delete_Student_clicked()
{
    MyStudents->Students.erase(MyStudents->Students.begin() + ui->listWidget->currentRow(), MyStudents->Students.begin() + ui->listWidget->currentRow() + 1);
    UpdateList(MyStudents->Students);
}

void MainWindow::on_Delete_Order_clicked()
{
    MyBook->Orders.erase(MyBook->Orders.begin() + ui->ListOfOrders->currentRow());
    UpdateListOfOrder(MyBook->Orders);
}

void MainWindow::on_CreateReport_clicked()
{
    MyBook->GetReport(QFileDialog::getSaveFileName());
}

void MainWindow::on_action_triggered()
{
    SubjectsWidget *MySubjects = new SubjectsWidget(this);
    MySubjects->show();
}
