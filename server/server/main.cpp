#include <QCoreApplication>
#include <server.h>

int main(int argc, char *argv[])
{
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");
    QCoreApplication a(argc, argv);
    MyTcpServer server;

    return a.exec();
}
