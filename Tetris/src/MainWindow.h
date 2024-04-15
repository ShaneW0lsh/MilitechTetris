#pragma once

#include <iostream>

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>

#include <QTimer>

#include "GameRenderer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void apply_start_button();
    void apply_pause_button();
    void apply_about_button();
    void apply_register_button();

    void update_game_area();

  private:
    void init_window();
    void init_widgets();
    void connect_widgets();

    QTimer *timer;

    QPushButton *start_button;
    QPushButton *pause_button;
    QPushButton *about_button;
    QPushButton *register_button;

    QHBoxLayout *main_layout;
    QHBoxLayout *buttons_layout;

    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;

    GameRenderer *game_renderer;
};
