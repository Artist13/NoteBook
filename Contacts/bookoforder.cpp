#include "bookoforder.h"
#include <QFile>
#include <QXmlStreamReader>

BookOfOrder::BookOfOrder(ListOfStudent *myStudents)
{
    AllStudents = myStudents;
}

BookOfOrder::~BookOfOrder()
{
    delete AllStudents;
}

void BookOfOrder::AddOrder(Order* order)
{
    Orders.push_back(order);
}

bool BookOfOrder::Load(const QString inputFile)
{
    QFile *file = new QFile(inputFile);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    Orders.clear();
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument)
            continue;
        if((xml.name() == "Order") && (xml.tokenType() == QXmlStreamReader::StartElement))
        {
            Order *tempOrder = new Order();
            foreach (const QXmlStreamAttribute &attr, xml.attributes())
            {
                if(attr.name() == "dateTime")
                    tempOrder->DateTime = QDateTime::fromString(attr.value().toString(), "dd.MM.yyyy");
                if(attr.name() == "subject")
                    tempOrder->Subject = attr.value().toString();
            }
            while((xml.tokenType() != QXmlStreamReader::EndElement) || (xml.name() != "Students"))
            {
                if(xml.name() == "Student" && xml.tokenType() == QXmlStreamReader::StartElement)
                {
                    Student *tempStudent = new Student();
                    foreach (const QXmlStreamAttribute &attr, xml.attributes())
                    {
                        /*if(attr.name() == "name")
                            tempStudent->Name = attr.value().toString();
                        if(attr.name() == "secondName")
                            tempStudent->SecondName = attr.value().toString();
                        if(attr.name() == "subject")
                            tempStudent->Subject = attr.value().toString();
                        if(attr.name() == "classNumber")
                            tempStudent->ClassNumber = attr.value().toInt();*/
                        if(attr.name() == "id")
                        {
                            foreach (Student* st, AllStudents->Students)
                            {
                                if(st->ID == attr.value().toInt())
                                    tempStudent = st;
                            }
                        }
                    }
                    tempOrder->Students.push_back(tempStudent);
                }
                token = xml.readNext();
            }
            Orders.push_back(tempOrder);
        }
    }
    file->close();
    return true;
}

bool BookOfOrder::Save(const QString outputFile)
{
    QFile *file = new QFile(outputFile);
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Orders");
    for(uint i = 0; i < Orders.size(); i++)
    {
        xml.writeStartElement("Order");
        xml.writeAttribute("dateTime", Orders[i]->DateTime.toString("dd.MM.yyyy"));
        xml.writeAttribute("subject", Orders[i]->Subject);
        xml.writeStartElement("Students");
        for(uint j = 0 ; j < Orders[i]->Students.size(); j++)
        {
            xml.writeStartElement("Student");
            //xml.writeAttribute("name", Orders[i]->Students[j]->Name);
            //xml.writeAttribute("secondName", Orders[i]->Students[j]->SecondName);
            //xml.writeAttribute("subject", Orders[i]->Students[j]->Subject);
            //if(Orders[i]->Students[j]->ClassNumber > 0)
            //    xml.writeAttribute("classNumber", QString::number(Orders[i]->Students[j]->ClassNumber));
            //else
            //    xml.writeAttribute("classNumber", "0");
            xml.writeAttribute("id", QString::number(Orders[i]->Students[j]->ID));
            xml.writeEndElement();
        }
        xml.writeEndElement();
        xml.writeEndElement();
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
    return true;
}

QString BookOfOrder::GetReport()
{

}