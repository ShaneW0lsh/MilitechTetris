/**
 * @file mainwindow.h
 * @brief Заголовочный файл для главного окна приложения
 */

#pragma once

#include <iostream>

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <consoleclient.h>

#include <QTimer>

#include "GameRenderer.hpp"

#include "RegisterWidget.h"
#include "AuthDialog.h"
// #include "GameWidget.h"

/**
 * @class MainWindow
 * @brief Класс для главного окна приложения
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr); ///< Конструктор
    ~MainWindow(); ///< Деструктор
    SingClient* client; ///< Клиент

public slots:
    void apply_start_button(); ///< Обработчик кнопки "Старт"
    void apply_pause_button(); ///< Обработчик кнопки "Пауза"
    void apply_about_button(); ///< Обработчик кнопки "О программе"
    void apply_register_button(); ///< Обработчик кнопки "Регистрация"
    void handle_sign_up_info(const QString username, const QString password); ///< Обработчик информации о регистрации

    void registration(const QString login, const QString password); ///< Регистрация

    void init_game_area(); ///< Инициализация игровой области
    void set_main_layout(); ///< Установка основного макета

    void update_game_area(); ///< Обновление игровой области

private:
    void init_window(); ///< Инициализация окна
    void init_widgets(); ///< Инициализация виджетов
    void show_auth_dialog(); ///< Отображение диалога аутентификации

    void connect_widgets(); ///< Подключение виджетов

    QTimer *timer; ///< Таймер
    Tetris::core::Board board; ///< Доска

    std::function<std::unique_ptr<Tetris::core::Tetromino>()> piece_randomizer; ///< Генератор случайной фигуры

    QPushButton *start_button; ///< Кнопка "Старт"
    QPushButton *pause_button; ///< Кнопка "Пауза"
    QPushButton *about_button; ///< Кнопка "О программе"
    QPushButton *register_button; ///< Кнопка "Регистрация"
    QPushButton *sign_in_button; ///< Кнопка "Вход"
    QPushButton *sign_up_button; ///< Кнопка "Регистрация"

    QHBoxLayout *main_layout; ///< Основной макет
    QHBoxLayout *buttons_layout; ///< Макет кнопок

    QLineEdit *username_line_edit; ///< Поле для ввода имени пользователя
    QLineEdit *password_line_edit; ///< Поле для ввода пароля

    AuthDialog* ad; ///< Диалог аутентификации

    Tetris::gui::GameRenderer *game_renderer; ///< Рендерер игры

    unsigned lines; ///< Количество строк
    unsigned level; ///< Уровень
    unsigned score; ///< Очки

protected:
    void keyReleaseEvent(QKeyEvent* e) override; ///< Обработчик отпускания клавиши
};
