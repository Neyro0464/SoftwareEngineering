#ifndef USERSDATACONTROLLER_H
#define USERSDATACONTROLLER_H

#include "UsersData.h"

class UsersDataController
{
public:
    UsersDataController();

    bool ValidateData(QString surname, QString name, QString patronymic, QString birthDate, QString sex);
    void SaveData(QString surname, QString name, QString patronymic, QString birthDate, QString sex);

};

#endif // USERSDATACONTROLLER_H
