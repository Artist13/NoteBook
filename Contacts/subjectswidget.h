/*
 * Класс описывающий виджет спискаа предметов???
 */
#ifndef SUBJECTSWIDGET_H
#define SUBJECTSWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QListWidget>
#include <QPushButton>

class SubjectsWidget : public QDialog
{
    Q_OBJECT
public:
    explicit SubjectsWidget(QWidget *parent = nullptr);
    void UpdateList();

signals:

public slots:
    void on_add_subject_clicked();
    void on_close_clicked();
    void on_subject_dbl_clicked(QModelIndex);

private:
    QListWidget *MyListOfSubjects;
    QPushButton *cmdAddSubject;
    QPushButton *cmdClose;
};

#endif // SUBJECTSWIDGET_H
