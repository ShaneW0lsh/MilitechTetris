#include "MainWindow.h"
#include <qboxlayout.h>
#include <qmainwindow.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    init_window();
    init_widgets();
}

MainWindow::~MainWindow() {}

void MainWindow::init_window()
{
    setFixedSize(800, 600);
    setWindowTitle(QString("Tetris"));
}

void MainWindow::init_widgets()
{
    start_button = new QPushButton("start", this);
    pause_button = new QPushButton("pause", this);
    about_button = new QPushButton("about", this);

    buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(start_button);
    buttons_layout->addWidget(pause_button);
    buttons_layout->addWidget(about_button);

    game_renderer = new GameRenderer();
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(2);
    game_renderer->setSizePolicy(spLeft);

    main_layout = new QHBoxLayout();
    main_layout->addWidget(game_renderer);
    main_layout->addLayout(buttons_layout);

    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(main_layout);
    setFocusPolicy(Qt::TabFocus);
    this->setCentralWidget(mainWidget);
}
