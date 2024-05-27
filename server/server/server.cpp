/**
 * @file server.cpp
 * @brief Реализация класса MyTcpServer.
 */
#include "server.h"

/**
 * @brief Конструктор класса MyTcpServer.
 * @param parent - родительский объект
 */
MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    if (!listen(QHostAddress::Any, 5555)) {
        qDebug() << "...Сервер не запущен...";
        return;
    }
    qDebug() << "...Сервер запущен...";
    connect(this, &MyTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);
    connectToDatabase();
}

/**
 * @brief Отправляет данные клиенту.
 * @param data - данные для отправки
 */
void MyTcpServer::sendToClient(QString data) {
    socket->write(data.toUtf8());
}

/**
 * @brief Слот для обработки новых подключений клиентов.
 */
void MyTcpServer::slotNewConnection()
{
    qDebug() << "Новый клиент подключился!";
    //socket->write("Я сервер");
    QTcpSocket* clientSocket = nextPendingConnection();
    Sockets.append(clientSocket);
    connect(clientSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

/**
 * @brief Слот для обработки отключения клиента.
 */
void MyTcpServer::slotClientDisconnected()
{
    qDebug() << "Клиент отключился!";
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    Sockets.remove(clientSocket->socketDescriptor());
    clientSocket->deleteLater();
}

/**
 * @brief Устанавливает соединение с базой данных.
 */
void MyTcpServer::connectToDatabase()
{
    Singleton& db = Singleton::getInstance();
    if (!db.connectToDb()) {
        qDebug() << "Не удалось подключиться к базе данных";
    }
}

/**
 * @brief Слот для чтения данных от клиента.
 */
void MyTcpServer::slotServerRead()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    QString str;
    while (clientSocket->bytesAvailable()) {
        QByteArray data = clientSocket->readAll();
        str += QString::fromUtf8(data);
    }
    str = str.trimmed();
    QString response = parsing(str);

    qDebug() << "От клиента" << clientSocket->socketDescriptor() << ": " << str;
    clientSocket->write(response.toUtf8());
}
