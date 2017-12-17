#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bookoforder.h"
#include "listofstudent.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void UpdateList(std::vector<Student*>);
    void UpdateListOfOrder(std::vector<Order*>);

    BookOfOrder *MyBook;
    ListOfStudent *MyStudents;

private slots:
    void on_AddPerson_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_AddOrder_clicked();

    void on_ListOfOrders_doubleClicked(const QModelIndex &index);

    void on_Delete_Student_clicked();

    void on_Delete_Order_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
