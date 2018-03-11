/*
 * Класс описывающий предмет
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>


class Subject
{
public:
    Subject();
    Subject(QString name, int classNumber, int price);

    int GetPrice();//Получить цену
    QString GetName();//Получить имя
    int GetClassNumber();//Получить номер класса
    QString GetInfo();//Передает объект для отображения
private:
    QString Name;//Название
    int Price;//Цена
    int ClassNumber;//Номер класса
};

#endif // SUBJECT_H
