#include "bookoforder.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QMap>
#include <QTextStream>
#include <QTextDocument>

#define studentID int
#define studentAmount int

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
    if(inputFile.isEmpty())
    {
        return false;
    }
    else
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
                    {
                        QStringList subject = attr.value().toString().split(' ');
                        tempOrder->OrderSubject.Name = subject.first();
                        QString classNumber = subject.last();
                        tempOrder->OrderSubject.ClassNumber = classNumber.toInt();
                    }
                    if(attr.name() == "hours")
                        tempOrder->Hours = attr.value().toDouble();
                }
                while((xml.tokenType() != QXmlStreamReader::EndElement) || (xml.name() != "Students"))
                {
                    if(xml.name() == "Student" && xml.tokenType() == QXmlStreamReader::StartElement)
                    {
                        Student *tempStudent = new Student();
                        foreach (const QXmlStreamAttribute &attr, xml.attributes())
                        {
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
        delete file;
        return true;
    }
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
        xml.writeAttribute("subject", Orders[i]->OrderSubject.Name + " " + QString::number(Orders[i]->OrderSubject.ClassNumber));
        xml.writeAttribute("hours", QString::number(Orders[i]->Hours));
        xml.writeStartElement("Students");
        for(uint j = 0 ; j < Orders[i]->Students.size(); j++)
        {
            xml.writeStartElement("Student");
            xml.writeAttribute("id", QString::number(Orders[i]->Students[j]->ID));
            xml.writeEndElement();
        }
        xml.writeEndElement();
        xml.writeEndElement();
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
    delete file;
    return true;
}

void BookOfOrder::GetReport(const QString outputFile)
{
    QMap<studentID, studentAmount> Report;
    for(uint i = 0; i < Orders.size(); i++)
    {
        foreach (Student* stud, Orders[i]->Students)
        {
            const int tempID = stud->ID;
            if(Report.contains(tempID))
            {
                Report[tempID]++;
            }
            else
            {
                Report.insert(tempID, 1);
            }
        }
    }
    QFile *file = new QFile(outputFile);
    if(file->open(QIODevice::WriteOnly))
    {
        QTextStream writer(file);
        //writer.setCodec("Windows-1251");
        QString HeadOne, HeadTwo, HeadThree;
        HeadOne = "Имя";
        HeadTwo = "Посещаемость";
        HeadThree = "Комментарий";
        writer << "<html>\n";
        writer << "<head>\n";
        writer << "</head>\n";
        writer << "<body>\n";

        writer << "<table>\n";

        writer << "<tr>\n";
        writer << "<td>" << HeadOne << "</td>\n";
        writer << "<td>" << HeadTwo << "</td>\n";
        writer << "<td>" << HeadThree << "</td>\n";
        writer << "</tr>";

        foreach(Student *stud, ListOfStudent::GetListOfStudent()->Students)
        {
            writer << "<tr>\n";
            QString firstColumn = stud->SecondName + " " + stud->Name;
            writer << "<td>\n" << firstColumn << "\n</td>\n";
            int tempAmount;
            if(Report.contains(stud->ID))
            {
                tempAmount = Report.find(stud->ID).value();
            }
            else
            {
                tempAmount = 0;
            }
            writer << "<td>\n" << QString::number(tempAmount) << "\n</td>\n";
            writer << "<td></td>\n";
            writer << "</tr>\n";
        }
        writer << "</table>\n";

        writer << "</body>\n";
        writer << "</html>\n";
    }
    file->close();
    delete file;
}
