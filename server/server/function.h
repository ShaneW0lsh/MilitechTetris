#ifndef FUNCTION_H
#define FUNCTION_H


/**
 * @file function.h
 * @brief Заголовочный файл с объявлением функций для работы с пользователями.
 */
#include <QString>
#include <QStringList>
#include <singleton.h>


/**
 * @brief Функция для разбора запроса.
 * @param request - строка запроса
 * @return строка с результатом разбора запроса
 */
QString parsing(QString request);

/**
 * @brief Функция для аутентификации пользователя.
 * @param login - логин пользователя
 * @param password - пароль пользователя
 * @return true, если аутентификация прошла успешно, иначе false
 */
bool authentication(QString login, QString password);

/**
 * @brief Функция для регистрации нового пользователя.
 * @param login - логин нового пользователя
 * @param password - пароль нового пользователя
 * @return true, если регистрация прошла успешно, иначе false
 */
bool registration(QString login, QString password);

/**
 * @brief Функция для проверки пользователя.
 * @param login - логин пользователя
 * @param password - пароль пользователя
 * @return true, если пользователь существует и пароль верный, иначе false
 */
bool checkUser(QString login, QString password);

#endif // FUNCTION_H
