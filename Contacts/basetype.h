/*
 * Основа для создания модели рассчета цены. От этого класса наследуются разные виды предметов.
 * Пока не используется???
 */
#ifndef BASETYPE_H
#define BASETYPE_H


class BaseType
{
public:
    BaseType();
    virtual ~BaseType();//Виртуальный конструктор???
    virtual int Price() = 0;//Основная функция - возвращает значение цены за час
};

#endif // BASETYPE_H
