#include "listofsubjects.h"
#include <QFile>
#include <QXmlStreamReader>

ListOfSubjects::ListOfSubjects()
{

}

ListOfSubjects* ListOfSubjects::GetListOfSubject()
{
    static ListOfSubjects MyListOfSubjects;
    return &MyListOfSubjects;
}

Subject ListOfSubjects::operator[](int index)
{
    if(index < Subjects.size())
        return Subjects[index];
    else
        throw;
}

QVector<Subject> ListOfSubjects::Find(QString name)
{
    QVector<Subject> temp;
    for(int i = 0; i < Subjects.size(); i++)
    {
        if(Subjects[i].GetName() == name)
            temp.push_back(Subjects[i]);
    }
    return temp;
}

void ListOfSubjects::AddSubject(Subject subject)
{
    Subjects.push_back(subject);
}

int ListOfSubjects::Size()
{
    return Subjects.size();
}

void ListOfSubjects::Load(const QString inputFile)
{
    QFile *file = new QFile(inputFile);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //return false;
        return;
    }
    Subjects.clear();
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument)
            continue;
        if((xml.name() == "Subject") && (xml.attributes().size() > 0))
        {
            Subject currentSubject = Subject();
            foreach (const QXmlStreamAttribute &attr, xml.attributes())
            {
                if(attr.name() == "name")
                    currentSubject.Name = attr.value().toString();
                if(attr.name() == "classNumber")
                    currentSubject.ClassNumber = attr.value().toInt();
                if(attr.name() == "price")
                    currentSubject.Price = attr.value().toInt();
            }
            Subjects.push_back(currentSubject);
        }
    }
    file->close();
}

void addSubjectToXml(Subject subject, QXmlStreamWriter &xml)
{
    xml.writeStartElement("Subject");
    xml.writeAttribute("name", subject.Name);
    xml.writeAttribute("classNumber", QString::number(subject.ClassNumber));
    xml.writeAttribute("price", QString::number(subject.Price));
    xml.writeEndElement();
}

void ListOfSubjects::Save(const QString outputFile)
{
    QFile *file = new QFile(outputFile);
    if(!file->open(QIODevice::WriteOnly))
    {
        return;
    }
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("Subjects");
    for(int i = 0; i < Subjects.size(); i++)
    {
        addSubjectToXml(Subjects[i], xml);
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file->close();
}
