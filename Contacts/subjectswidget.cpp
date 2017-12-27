#include "subjectswidget.h"
#include <QGridLayout>
#include "addsubject.h"
#include "listofsubjects.h"

#define MySubjects ListOfSubjects::GetListOfSubject()

SubjectsWidget::SubjectsWidget(QWidget *parent) : QDialog(parent)
{
    this->setMinimumHeight(400);
    this->setMinimumWidth(400);
    QGridLayout *MyLayout = new QGridLayout(this);
    MyListOfSubjects = new QListWidget();
    cmdAddSubject = new QPushButton("Добавить предмет");
    cmdClose = new QPushButton("Закрыть");

    connect(cmdAddSubject, SIGNAL(clicked(bool)), SLOT(on_add_subject_clicked()));
    connect(cmdClose, SIGNAL(clicked(bool)), SLOT(reject()));
    connect(MyListOfSubjects, SIGNAL(doubleClicked(QModelIndex)), SLOT(on_subject_dbl_clicked(QModelIndex)));

    MyLayout->addWidget(MyListOfSubjects, 0,0, 1, 2);
    MyLayout->addWidget(cmdAddSubject, 1,0,1,1);
    MyLayout->addWidget(cmdClose, 1, 1, 1, 1);

    UpdateList();
}

void SubjectsWidget::UpdateList()
{
    MyListOfSubjects->clear();
    foreach (Subject subj, MySubjects->Subjects)
    {
        MyListOfSubjects->addItem(new QListWidgetItem(subj.GetName() + " " + QString::number(subj.GetClassNumber())));
    }
}

void SubjectsWidget::on_add_subject_clicked()
{
    AddSubject* addSubject = new AddSubject();
    if(addSubject->exec() == QDialog::Accepted)
    {
        MySubjects->AddSubject(addSubject->GetSubject());
    }
    UpdateList();
    delete addSubject;
}

void SubjectsWidget::on_close_clicked()
{

}

void SubjectsWidget::on_subject_dbl_clicked(QModelIndex index)
{
    if(!index.isValid())
    {
        return;
    }
    MySubjects->Subjects.erase(MySubjects->Subjects.begin() + index.row(), MySubjects->Subjects.begin() + index.row() + 1);
    UpdateList();
}
