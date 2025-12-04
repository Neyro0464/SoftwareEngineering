#include "FileControllerJson.h"
#include "UsersData.h"

#include <QDebug>

int main()
{
    UsersData a{FileControllerJson::ReadFile("./users_data.json")};
    qDebug() << FileControllerJson::CreateFile("test.json", a);
    a.ShowData();

    return 0;
}
