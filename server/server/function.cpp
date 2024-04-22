
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

    Singleton& dataBase = Singleton::getInstance();

    QSqlQuery sql(dataBase.db);
    sql.prepare("SELECT Login,Password FROM Players WHERE Login = :login AND Password = :password");
    sql.bindValue(":login", login);
    sql.bindValue(":password", password);

    if (sql.exec() && sql.first()) {
        return true;
    }
    return false;
}
bool registration(QString login,QString password) {

    if (!checkUser(login,password)) {
        Singleton& database = Singleton::getInstance();

        QSqlQuery sql(database.db);
        sql.prepare("INSERT INTO Players(Login,Password,MaxScore)  VALUES (:login, :password,0)");
        sql.bindValue(":login", login);
        sql.bindValue(":password", password);

        if (!sql.exec()) {
            qDebug() << "Error of registration";
            qDebug() << sql.lastError();
            return false;
        }
        return true;
    }

    return false;
}
bool checkUser(QString login,QString password) {


    Singleton& dataBase = Singleton::getInstance();

    QSqlQuery sql(dataBase.db);
    sql.prepare("SELECT Login,Password FROM Players WHERE Login = :login AND Password = :password");
    sql.bindValue(":login", login);
    sql.bindValue(":password", password);

    if (sql.exec() && sql.first()) {
        return true;
    }
    return false;



}
