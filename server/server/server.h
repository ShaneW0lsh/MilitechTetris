#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include "singleton.h"
#include "function.h"



class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);

private slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
    void sendToClient(QString data);
    void connectToDatabase();

private:
    QTcpSocket* socket;
    QList<QTcpSocket*> Sockets;
};

#endif // MYTCPSERVER_H
