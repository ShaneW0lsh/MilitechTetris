#ifndef FUNCTION_H
#define FUNCTION_H
#include <QString>
#include<QstringList>
#include<singleton.h>

QString parsing(QString request);
bool authentication(QString login, QString password);
bool registration(QString login, QString password);
bool checkUser(QString login, QString password);

#endif // FUNCTION_H
