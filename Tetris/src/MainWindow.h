#pragma once

#include <iostream>

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include<consoleclient.h>
#include <QTableWidget>
#include <QStackedLayout>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QTimer>

#include "GameRenderer.hpp"

//#include "RegisterWidget.h"
#include "AuthDialog.h"
//#include "GameWidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SingClient* client;

public slots:
    void apply_start_button();
    void apply_pause_button();
    void apply_about_button();
    void apply_register_button();
    void handle_sign_up_info(const QString username, const QString password);

    void registration(const QString login, const QString password);

    void init_game_area();
    void set_main_layout();

    void update_game_area();

    void on_showScoresButton_clicked();
    void handleUserScores(const QVector<QPair<QString, int>> &userScores);



private:
    //RegisterWidget *register_widget;
    void init_window();
    void init_widgets();
    void show_auth_dialog();
    void show_scores_button();




    void connect_widgets();

    QTimer *timer;
    Tetris::core::Board board;

    std::function<std::unique_ptr<Tetris::core::Tetromino>()> piece_randomizer;

    QPushButton *start_button;
    QPushButton *pause_button;
    QPushButton *about_button;
    QPushButton *register_button;
    QPushButton *sign_in_button;
    QPushButton *sign_up_button;



    QPushButton *showScoresButton;






    QHBoxLayout *main_layout;
    QHBoxLayout *buttons_layout;

    QLineEdit *username_line_edit;
    QLineEdit *password_line_edit;

    AuthDialog* ad;

    Tetris::gui::GameRenderer *game_renderer;

    unsigned lines;
    unsigned level;
    unsigned score;
protected:
    void keyReleaseEvent(QKeyEvent* e) override;
};
