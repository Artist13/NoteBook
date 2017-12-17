#include "persone.h"

Persone::Persone()
{
    Name = "Ivan";
    SecondName = "Ivanov";
}

Persone::Persone(QString name, QString secondName)
{
    Name = name;
    SecondName = secondName;
}

Persone::~Persone()
{

}

QString Persone::ShowInfo()
{
    QString tempInfo = Name + "   " + SecondName;
    return tempInfo;
}

void Persone::SetID(int id)
{
    ID = id;
}
