#include "server.h"


MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    if (!listen(QHostAddress::Any, 5555)) {
        qDebug() << "...Server not started...";
        return;
    }
    qDebug() << "...Server started...";
    connect(this, &MyTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

}

void MyTcpServer::sendToClient(QString data) {
    socket->write(data.toUtf8());
}

void MyTcpServer::slotNewConnection()
{
    qDebug() << "New client connected!";
    //socket->write("I am server");
    QTcpSocket* clientSocket = nextPendingConnection();
    Sockets.append(clientSocket);
    connect(clientSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}
void MyTcpServer::slotClientDisconnected()
{
    qDebug() << "Client  disconnected!";
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    Sockets.remove(clientSocket->socketDescriptor());
    clientSocket->deleteLater();
}


void MyTcpServer::slotServerRead()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());


    QString str;
    while (clientSocket->bytesAvailable()) {
        QByteArray data = clientSocket->readAll();
        str += QString::fromUtf8(data);
    }
    qDebug() << "From client" << clientSocket->socketDescriptor() << ": " << str;
    clientSocket->write(str.toUtf8());
}



