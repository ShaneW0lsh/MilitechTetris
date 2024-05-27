#include <QCoreApplication>
#include <server.h>

/**
 * @file main.cpp
 * @brief Основная функция для запуска сервера.
 */

/**
 * @brief Основная функция для запуска сервера.
 * @param argc - количество аргументов командной строки
 * @param argv - массив аргументов командной строки
 * @return код завершения приложения
 */
int main(int argc, char *argv[])
{
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");
    QCoreApplication a(argc, argv);
    MyTcpServer server;

    return a.exec();
}
