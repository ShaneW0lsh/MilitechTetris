#pragma once

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <qboxlayout.h>

#include "GameRenderer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:

  private:
    void init_window();
    void init_widgets();
    QPushButton *start_button;
    QPushButton *pause_button;
    QPushButton *about_button;

    QHBoxLayout *main_layout;
    QHBoxLayout *buttons_layout;

    GameRenderer *game_renderer;
};
