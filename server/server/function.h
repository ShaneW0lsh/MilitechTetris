#ifndef FUNCTION_H
#define FUNCTION_H
#include <QString>
#include <QStringList>
#include <singleton.h>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QString parsing(QString request);
bool authentication(QString login, QString password);
bool registration(QString login, QString password);
bool checkUser(QString login, QString password);
QVector<QPair<QString, int>> getUserScores();
#endif // FUNCTION_H
