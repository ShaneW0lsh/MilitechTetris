/**
 * @file singleton.h
 * @brief Описание класса Singleton
 */
#include <QCoreApplication>
#include<singleton.h>
/**
 * @class Singleton
 * @brief Класс Singleton для управления подключением к базе данных
 */

Singleton& Singleton::getInstance()
{
    /**
     * @brief Возвращает единственный экземпляр класса Singleton
     * @return Ссылка на экземпляр класса Singleton
     */
    static Singleton instance;
    return instance;
}

/**
     * @brief Устанавливает подключение к базе данных SQLite
     * @return true, если подключение успешно, иначе false
     */
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
/**
     * @brief Закрывает подключение к базе данных
    */
void Singleton::close()
{
    db.close();
    qDebug() << "Database connection was closed";
}
/**
     * @brief Конструктор по умолчанию
     */
Singleton::Singleton() {}
/**
     * @brief Конструктор копирования
     */
Singleton::Singleton(Singleton const&)  {}
/**
     * @brief Оператор присваивания
     */
void Singleton::operator=(Singleton const&)  {}
