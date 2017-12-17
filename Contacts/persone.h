#ifndef PERSONE_H
#define PERSONE_H
#include <QString>


class Persone
{
public:
    Persone();
    Persone(QString, QString);
    ~Persone();
    QString ShowInfo();
    void SetID(int);

    QString Name;
    QString SecondName;
    int ID;
};

#endif // PERSONE_H
