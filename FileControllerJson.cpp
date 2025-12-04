#include "FileControllerJson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDate>

UsersData FileControllerJson::ReadFile(QString filePath){
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw "[LicenseFileJson] : Json file already open";
    }

    QString val = file.readAll();
    file.close();

    QJsonObject obj = QJsonDocument::fromJson(val.toUtf8()).object();
    QJsonValue value = obj.value(QString("usersData"));
    QJsonObject item = value.toObject();

    UsersData res(item["surname"].toString(), item["name"].toString(), item["patronymic"].toString(), QDate::fromString(item["birthDate"].toString(), "dd.MM.yyyy"), item["sex"].toString());
    return res;
}

bool FileControllerJson::CreateFile(QString filePath, UsersData data){
    QFile jsonFile(filePath);

    if (!jsonFile.open(QFile::WriteOnly | QFile::Text ))
    {
        qDebug() << "Already opened or there is another issue";
        jsonFile.close();
        return false;
    }

    // Add a value using QJsonArray and write to the file
    QJsonObject item;
    item.insert("surname", data.GetSurname());
    item.insert("name", data.GetName());
    item.insert("patronymic", data.GetPatronymic());
    item.insert("birthDate", data.GetBirthDate().toString("dd.MM.yyyy"));
    item.insert("sex", data.GetSex());

    QJsonObject licenseObj;
    licenseObj.insert("usersData",item);

    QJsonDocument doc(licenseObj);

    jsonFile.write(doc.toJson());
    return true;
}
