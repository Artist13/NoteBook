/*
 * Базовый класс для ученика
 */
#ifndef PERSONE_H
#define PERSONE_H
#include <QString>


class Persone
{
public:
    Persone();
    Persone(QString, QString);
    ~Persone();
    QString ShowInfo();//Передает объект для отображения в программе
    void SetID(int);//Устанавливает указаннй ID

    QString Name;//Имя
    QString SecondName;//Фамилия
    int ID;//Должно быть скрыто в private. Иначе зачем SetID
};

#endif // PERSONE_H
