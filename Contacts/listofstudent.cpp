#include "listofstudent.h"

#include <QListWidget>
#include <QFile>
#include <QXmlStreamReader>
//#include <QXmlStreamWriter>

ListOfStudent::ListOfStudent()
{
    last_id = 0;
}

ListOfStudent::ListOfStudent(ListOfStudent *myList)
{
    this->last_id = myList->last_id;
    foreach (Student* st, myList->Students)
    {
        this->Students.push_back(st);
    }
}

void ListOfStudent::addStudent(Student *student)
{
    student->SetID(++last_id);
    Students.push_back(student);
}

QString ListOfStudent::ShowStudents()
{
    QString tempInfo = "";
    for(int i = 0; i < Students.size(); i++)
    {
        tempInfo += Students[i]->ShowInfo() + "\n";
    }
    return tempInfo;
}

bool ListOfStudent::Load(const QString inputFile)
{
    QFile *file = new QFile(inputFile);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    Students.clear();
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument)
            continue;
        if((xml.name() == "Student") && (xml.attributes().size() > 0))
        {
            Student *tempStudent = new Student();
            foreach (const QXmlStreamAttribute &attr, xml.attributes())
            {
                if(attr.name() == "name")
                    tempStudent->Name = attr.value().toString();
                if(attr.name() == "secondName")
                    tempStudent->SecondName = attr.value().toString();
                if(attr.name() == "subject")
                    tempStudent->Subject = attr.value().toString();
                if(attr.name() == "classNumber")
                    tempStudent->ClassNumber = attr.value().toInt();
                if(attr.name() == "id")
                {
                    tempStudent->ID = attr.value().toInt();
                    last_id = attr.value().toInt();
                }
            }
            Students.push_back(tempStudent);
        }
    }
    file->close();
    return true;
}


void addStudentToXml(Student* student, QXmlStreamWriter &xml)
{
    xml.writeStartElement("Student");
    xml.writeAttribute("name", student->Name);
    xml.writeAttribute("secondName", student->SecondName);
    xml.writeAttribute("subject", student->Subject);
    if(student->ClassNumber > 0)
        xml.writeAttribute("classNumber", QString::number(student->ClassNumber));
    else
        xml.writeAttribute("classNumber", "0");
    xml.writeAttribute("id", QString::number(student->ID));
    xml.writeEndElement();
}

bool ListOfStudent::Save(const QString outputFile)
{
    QFile *file = new QFile(outputFile);
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Students");
    for(uint i = 0; i < Students.size(); i++)
    {
        addStudentToXml(Students[i], xml);
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
    return true;
}


