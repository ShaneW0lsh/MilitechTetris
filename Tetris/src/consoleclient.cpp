
#include<consoleclient.h>
SingClient::SingClient()
{
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1", 5555);
    connect(socket,&QTcpSocket::readyRead,this,&SingClient::slot_readFromServer);
}
SingClient::~SingClient()
{
    socket->close();
    delete p_instance;
}

SingClient* SingClient::getInstance() {
    if(!p_instance)
    {
        p_instance = new SingClient();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

QString SingClient::sendToServer(const QString& msg)
{
    try {
        socket->write(msg.toUtf8());
        socket->waitForReadyRead();
        return Message;
    } catch (const std::exception& e){
        socket->disconnectFromHost();
        return "Disconnecting";
    }
}


void SingClient::slot_readFromServer()
{
    QByteArray data;
    QString message;
    while(socket->bytesAvailable()){
        data = socket->readAll();
        message.append(data);
    }
    data.clear();
    Message = message;

    // Проверяем, что полученный ответ содержит список пользователей и их счета
    if (Message.startsWith("[") && Message.endsWith("]")) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(Message.toUtf8());
        if (jsonDoc.isArray()) {
            QVector<QPair<QString, int>> userScores;
            QJsonArray jsonArray = jsonDoc.array();
            foreach (const QJsonValue &value, jsonArray) {
                if (value.isObject()) {
                    QJsonObject obj = value.toObject();
                    QString login = obj["login"].toString();
                    int maxScore = obj["max_score"].toInt();
                    userScores.append(qMakePair(login, maxScore));
                }
            }
            emit userScoresReceived(userScores);
        }
    }
}

SingClient * SingClient::p_instance;
SingClientDestroyer SingClient::destroyer;
