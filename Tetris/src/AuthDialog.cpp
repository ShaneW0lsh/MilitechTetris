/**
 * @file AuthDialog.h
 * @brief Заголовочный файл для класса AuthDialog
 */

#pragma once

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QFont>
#include <QLayoutItem>

/**
 * @class AuthDialog
 * @brief Класс диалога аутентификации
 */
class AuthDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AuthDialog
     * @param parent Родительский виджет
     */
    AuthDialog(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Зарегистрироваться"
     */
    void on_sign_up_button_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Войти"
     */
    void on_log_in_button_clicked();

signals:
    /**
     * @brief Сигнал о нажатии кнопки "Зарегистрироваться"
     * @param username Имя пользователя
     * @param password Пароль
     */
    void sign_up_clicked(const QString& username, const QString& password);

private:
    QPushButton *log_in_button; ///< Кнопка "Войти"
    QPushButton *sign_up_button; ///< Кнопка "Зарегистрироваться"
    QLineEdit *username_line_edit; ///< Поле для ввода имени пользователя
    QLineEdit *password_line_edit; ///< Поле для ввода пароля
};
