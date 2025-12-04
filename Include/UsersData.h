#ifndef USERSDATA_H
#define USERSDATA_H

#include <QString>
#include <QDate>

class UsersData
{
public:
    UsersData() = default;
    UsersData(QString surname, QString name, QString patronymic, QDate birthDate, QString sex);
    ~UsersData() = default;

    void Init(QString surname, QString name, QString patronymic, QDate birthDate, QString sex);

    QString GetSurname();
    QString GetName();
    QString GetPatronymic();
    QDate GetBirthDate();
    QString GetSex();

    void ShowData();

private:
    QString m_surname;    // Фамилия
    QString m_name;       // Имя
    QString m_patronymic; // Отчество
    QDate m_birthDate;    // Дата рождения
    QString m_sex;        // Пол
};

#endif // USERSDATA_H
