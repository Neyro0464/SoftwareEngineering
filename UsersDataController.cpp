#include "UsersDataController.h"

UsersDataController::UsersDataController() {}


bool UsersDataController::ValidateData(QString surname, QString name, QString patronymic, QString birthDate, QString sex){
    // Проверка на пустые поля
    if(surname.isEmpty() ||
        name.isEmpty() ||
        patronymic.isEmpty() ||
        birthDate.isEmpty() ||
        sex.isEmpty()){
        qDebug() << "[UsersDataController]: Empty field";
        return false;
    }

    // Проверка на валидность данных
    QDate date = QDate::fromString(birthDate, "dd.MM.yyyy");
    if(!surname.isValidUtf16() ||
        !name.isValidUtf16() ||
        !patronymic.isValidUtf16() ||
        !date.isValid() ||
        !sex.isValidUtf16()
            ){
        qDebug() << "[UsersDataController]: Invalid data";
        return false;
    }

    return true;
}

void UsersDataController::SaveData(QString surname, QString name, QString patronymic, QString birthDate, QString sex){
    UsersData data{surname, name, patronymic, QDate::fromString(birthDate, "dd.MM.yyyy"), sex};
}
