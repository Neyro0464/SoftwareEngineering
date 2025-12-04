#include "UsersData.h"
#include <QDebug>

UsersData::UsersData(QString surname, QString name, QString patronymic, QDate birthDate, QString sex):
    m_surname(surname), m_name(name), m_patronymic(patronymic), m_birthDate(birthDate), m_sex(sex)
{}

void UsersData::Init(QString surname, QString name, QString patronymic, QDate birthDate, QString sex){
    m_surname = surname;
    m_name = name;
    m_patronymic = patronymic;
    m_birthDate = birthDate;
    m_sex = sex;
}

QString UsersData::GetSurname(){
    return m_surname;
}
QString UsersData::GetName(){
    return m_name;
}
QString UsersData::GetPatronymic(){
    return m_patronymic;
}
QDate UsersData::GetBirthDate(){
    return m_birthDate;
}
QString UsersData::GetSex(){
    return m_sex;
}

void UsersData::ShowData(){
    qDebug() << "Surname:" << m_surname
             << "\nName:" << m_name
             << "\nPatronymic:" << m_patronymic
             << "\nDate of Birth:" << m_birthDate.toString("dd.MM.yyyy")
             << "\nSex:" << m_sex;
}
