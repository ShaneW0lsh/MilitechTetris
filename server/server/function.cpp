/**
 * @file function.h
 * @brief Заголовочный файл с объявлением функций для работы с базой данных.
 */

#include<function.h>

/**
 * @brief Функция для разбора запроса от клиента.
 * @param request - строка с запросом от клиента
 * @return строка с ответом на запрос от клиента
 */
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

/**
 * @brief Функция для аутентификации пользователя.
 * @param login - логин пользователя
 * @param password - пароль пользователя
 * @return true, если аутентификация прошла успешно, иначе false
 */
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

/**
 * @brief Функция для регистрации нового пользователя.
 * @param login - логин нового пользователя
 * @param password - пароль нового пользователя
 * @return true, если регистрация прошла успешно, иначе false
 */
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

/**
 * @brief Функция для проверки существования пользователя в базе данных.
 * @param login - логин пользователя
 * @param password - пароль пользователя
 * @return true, если пользователь существует в базе данных, иначе false
 */
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
