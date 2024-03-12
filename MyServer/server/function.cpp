#include<function.h>
QString parsing(QString request) {
    QStringList parseRequest = request.split(' ');
    QString action = parseRequest[0];
    QString response = "";

    if (action == "auth" && parseRequest.length() == 3) {
        if (authentication(parseRequest[1],parseRequest[2])) {
            response = "User is successfully authorized";
        } else {
            response = "Error authorizing";
        }
    }
    else if (action == "reg" && parseRequest.length() == 3) {
        if (registration(parseRequest[1],parseRequest[2])) {
            response =  "User is suceccfully registered";
        } else {
            response = "Error registration";
        }
    }
    return response;
}

bool authentication(QString login, QString password) {
    if (login == "admin" && password == "admin") {
        return true;
    }
    return false;
}
bool registration(QString login,QString password) {
    return true;
}
