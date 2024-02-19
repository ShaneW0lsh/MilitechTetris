#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QDataStream>


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

private:
    QTcpSocket* socket;
    QList<QTcpSocket*> Sockets;
};

#endif // MYTCPSERVER_H
