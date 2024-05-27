
/**
 * @file singleton.h
 * @brief Заголовочный файл с объявлением класса Singleton.
 */
#ifndef SINGLETON_H
#define SINGLETON_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief Класс Singleton для управления единственным экземпляром объекта.
 */
class Singleton
{
public:
    /**
     * @brief Метод для получения экземпляра класса Singleton.
     * @return экземпляр класса Singleton
     */
    static Singleton& getInstance();

    QSqlDatabase db; ///< Объект для работы с базой данных.

    /**
     * @brief Метод для подключения к базе данных.
     * @return true, если подключение успешно, иначе false
     */
    bool connectToDb();

    /**
     * @brief Метод для отключения от базы данных.
     */
    void close();

private:
    Singleton(); ///< Приватный конструктор.
    Singleton(Singleton const&); ///< Приватный конструктор копирования.
    void operator=(Singleton const&); ///< Приватный оператор присваивания.
};

#endif // SINGLETON_H
