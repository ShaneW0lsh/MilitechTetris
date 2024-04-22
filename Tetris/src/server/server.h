#pragma once
#include "function.h"
#include "singleton.h"
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

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
    QTcpSocket *socket;
    QList<QTcpSocket *> Sockets;
};
