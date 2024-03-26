#ifndef SINGLETON_H
#define SINGLETON_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



class Singleton
{
public:
    static Singleton& getInstance();
    QSqlDatabase db;
    bool connectToDb();
    void close();

private:
    Singleton();
    Singleton(Singleton const&);
    void operator=(Singleton const&);


};

#endif // SINGLETON_H
