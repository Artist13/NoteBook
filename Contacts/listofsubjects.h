/*
 * Список предметов. Шаблон "одиночка"
 */
#ifndef LISTOFSUBJECTS_H
#define LISTOFSUBJECTS_H

#include "subject.h"
#include <QVector>

class ListOfSubjects
{
public:
    static ListOfSubjects* GetListOfSubject();//Сущность списка
    Subject operator[](int index);//Нужно ли это здесь
    QVector<Subject> Find(QString name);//Поиск предметов по нназванию
    void AddSubject(Subject subject);//Добавление предмета по значению
    int Size();//Колличество предметов. А это используется где-то?
    QVector<Subject> Subjects;//Список предметов
    void Load(const QString);//Загрузка из xml файла
    void Save(const QString);//Сохранение в xml файл
private:
    ListOfSubjects();

};

#endif // LISTOFSUBJECTS_H
