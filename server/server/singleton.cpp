#include <QCoreApplication>
#include<singleton.h>
Singleton& Singleton::getInstance()
{

    static Singleton instance;
    return instance;
}


bool Singleton::connectToDb()
{
    QString currentDir = QCoreApplication::applicationDirPath();
    qDebug() << "Current Dir Path: " << currentDir << '\n';
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString databaseName = currentDir + "/../server/database.db";
    qDebug() << databaseName << '\n';
    //db.setDatabaseName("/home/shane/dev/MilitechTetrisV2/MilitechTetris/server/server/database.db");
    db.setDatabaseName(databaseName);
    QSqlQuery query(db);

    if (!db.open()) {
        qDebug() << "Database does not connected!";
        qDebug() << db.lastError().text();
        return false;
    }



    bool checkTable = query.exec("CREATE TABLE IF NOT EXISTS Players( Id INTEGER, Login TEXT, Password TEXT, MaxScore INTEGER, PRIMARY KEY(Id) )");

    if (!checkTable) {
        qDebug() << "Error of  creating table 'Players': " << query.lastError().text();
        db.close();
        return false;
    }
    qDebug() << "Database is connected!";
    return true;
}
void Singleton::close()
{
    db.close();
    qDebug() << "Database connection was closed";
}
Singleton::Singleton() {}
Singleton::Singleton(Singleton const&)  {}

void Singleton::operator=(Singleton const&)  {}
