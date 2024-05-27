/**
 * @file logindialog.h
 * @brief Заголовочный файл для диалогового окна аутентификации
 */

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QScreen>

/**
 * @class AuthDialog
 * @brief Класс диалогового окна аутентификации
 */
class AuthDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса
     * @param parent Родительский виджет (по умолчанию nullptr)
     */
    AuthDialog(QWidget *parent = nullptr);

signals:
    /**
     * @brief Сигнал о нажатии кнопки "Зарегистрироваться"
     * @param username Имя пользователя
     * @param password Пароль
     */
    void sign_up_clicked(const QString username, const QString password);

    /**
     * @brief Сигнал о нажатии кнопки "Войти"
     * @param username Имя пользователя
     * @param password Пароль
     */
    void log_in_clicked(const QString usirname, const QString password);

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "Зарегистрироваться"
     */
    void on_sign_up_button_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Войти"
     */
    void on_log_in_button_clicked();

private:
    QPushButton* sign_up_button; ///< Кнопка "Зарегистрироваться"
    QPushButton* log_in_button; ///< Кнопка "Войти"
    // QPushButton* real_log_in_button;

    QLineEdit* username_line_edit; ///< Поле для ввода имени пользователя
    QLineEdit* password_line_edit; ///< Поле для ввода пароля
};

#endif // LOGINDIALOG_H
*/
