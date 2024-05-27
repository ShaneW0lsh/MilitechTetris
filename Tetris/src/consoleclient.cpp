/**
 * @file consoleclient.h
 * @brief Заголовочный файл для класса SingClient
 */

#pragma once

#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QDebug>

/**
 * @class SingClient
 * @brief Класс клиента для общения с сервером
 */
class SingClient : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса SingClient
     */
    SingClient();

    /**
     * @brief Деструктор класса SingClient
     */
    ~SingClient();

    /**
     * @brief Получение экземпляра класса SingClient
     * @return Указатель на экземпляр класса SingClient
     */
    static SingClient* getInstance();

    /**
     * @brief Отправка сообщения на сервер
     * @param msg Сообщение для отправки
     * @return Ответ от сервера
     */
    QString sendToServer(const QString& msg);

private slots:
    /**
     * @brief Слот для чтения данных от сервера
     */
    void slot_readFromServer();

private:
    QTcpSocket *socket; ///< Сокет для соединения с сервером
    static SingClient *p_instance; ///< Указатель на экземпляр класса SingClient
    QString Message; ///< Сообщение от сервера

    /**
     * @brief Конструктор копирования класса SingClient
     */
    SingClient(const SingClient&) = delete;

    /**
     * @brief Оператор присваивания класса SingClient
     */
    SingClient& operator=(const SingClient&) = delete;

    /**
     * @brief Уничтожение экземпляра класса SingClient
     */
    class SingClientDestroyer {
    public:
        /**
         * @brief Инициализация уничтожителя
         * @param p Указатель на экземпляр класса SingClient
         */
        void initialize(SingClient *p) {
            p_instance = p;
        }

        /**
         * @brief Деструктор уничтожителя
         */
        ~SingClientDestroyer() {
            delete p_instance;
        }
    };

    static SingClientDestroyer destroyer; ///< Уничтожитель экземпляра класса SingClient
};
