
#include <QCoreApplication>
#include<consoleclient.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingClient* client = SingClient::getInstance();
    QString message = "reg misha admin";
    QString response = client->sendToServer(message);
    return a.exec();
}
