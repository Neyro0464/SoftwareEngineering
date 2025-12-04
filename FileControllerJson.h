#ifndef FILECONTROLLERJSON_H
#define FILECONTROLLERJSON_H

#include <QString>
#include "UsersData.h"

class FileControllerJson
{
public:
    FileControllerJson() = delete;
    static UsersData ReadFile(QString filePath);
    static bool CreateFile(QString filePath, UsersData data);
};

#endif // FILECONTROLLERJSON_H
