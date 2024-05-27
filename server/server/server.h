#ifndef MYTCPSERVER_H

/**
 * @file mytcpserver.h
 * @brief Заголовочный файл с объявлением класса MyTcpServer.
 */

#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include "singleton.h"
#include "function.h"

/**
 * @brief Класс MyTcpServer для работы с TCP-сервером.
 */
class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор класса MyTcpServer.
     * @param parent - указатель на родительский объект
     */
    explicit MyTcpServer(QObject *parent = nullptr);

private slots:
    void slotNewConnection(); ///< Слот для обработки нового подключения к серверу.
    void slotServerRead(); ///< Слот для чтения данных от клиента.
    void slotClientDisconnected(); ///< Слот для обработки отключения клиента.
    void sendToClient(QString data); ///< Метод для отправки данных клиенту.
    void connectToDatabase(); ///< Метод для подключения к базе данных.

private:
    QTcpSocket* socket; ///< Сокет для обмена данными с клиентом.
    QList<QTcpSocket*> Sockets; ///< Список сокетов клиентов.
};

#endif // MYTCPSERVER_H
