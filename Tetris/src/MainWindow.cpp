
#include "MainWindow.h"
#include <QFormLayout>
#include <QLineEdit>
// #include <QString>
//#include "server/function.h"
#include <qboxlayout.h>
#include <qdebug.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <consoleclient.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    timer = new QTimer(this);
    timer->start(400);
    init_window();
    init_widgets();
    connect_widgets();
    this->client = SingClient::getInstance();
}

MainWindow::~MainWindow() {}

void MainWindow::init_window()
{
    setFixedSize(1000, 800);
    setWindowTitle(QString("Tetris"));
}

void MainWindow::init_widgets()
{
    start_button = new QPushButton("start", this);
    pause_button = new QPushButton("pause", this);
    about_button = new QPushButton("about", this);
    register_button = new QPushButton("register", this);
    register_button->setFixedWidth(this->width() / 6); // Set fixed width
    register_button->setFont(QFont("Arial", 14));      // Set font size to 14

    buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(start_button);
    buttons_layout->addWidget(pause_button);
    buttons_layout->addWidget(about_button);

    game_renderer = new GameRenderer();

    main_layout = new QHBoxLayout();
    main_layout->addWidget(game_renderer, 2);
    main_layout->addLayout(buttons_layout, 1);

    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(main_layout);
    setFocusPolicy(Qt::TabFocus);
    this->setCentralWidget(mainWidget);
}

void MainWindow::connect_widgets()
{
    QObject::connect(start_button, SIGNAL(clicked()), this,
                     SLOT(apply_start_button()));
    QObject::connect(pause_button, SIGNAL(clicked()), this,
                     SLOT(apply_pause_button()));
    QObject::connect(about_button, SIGNAL(clicked()), this,
                     SLOT(apply_about_button()));
    QObject::connect(register_button, SIGNAL(clicked()), this,
                     SLOT(apply_register_button()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_game_area()));
}

void MainWindow::update_game_area()
{ // std::cout << "Frame\n";
}

void MainWindow::apply_start_button()
{
    std::cerr << "Start Button Applied!\n";
    timer->start();
}

void MainWindow::apply_pause_button()
{
    std::cout << "Pause Button Applied!\n";
    timer->stop();
}

void MainWindow::apply_register_button()
{
    QString login = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    std::cout << login.toStdString() << ' ' << password.toStdString() << '\n';
    // if (registration(login, password) == 1) {
    //     std::cout << "Авторизация прошла успешно\n";
    //     close();
    // } else {
    //     std::cout << "Вы не авторизировались, попробуйте еще раз\n";
    // }
    registration(login,password);
}
void MainWindow::registration(QString login,QString password) {
    client->sendToServer("reg " + login + " " + password);
}

void MainWindow::apply_about_button()
{
    int window_width = this->width();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setAlignment(Qt::AlignCenter); // Center widgets vertically

    QFormLayout *layout = new QFormLayout();
    layout->setFormAlignment(Qt::AlignCenter);

    usernameLineEdit = new QLineEdit();
    usernameLineEdit->setFixedWidth(window_width / 4); // Set fixed width
    usernameLineEdit->setPlaceholderText("Username");
    usernameLineEdit->setFont(QFont("Arial", 14)); // Set font size to 14
    layout->addRow(usernameLineEdit);

    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setFixedWidth(window_width / 4); // Set fixed width
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setFont(QFont("Arial", 14)); // Set font size to 14
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    layout->addRow(passwordLineEdit);

    QLineEdit *confirmPasswordLineEdit = new QLineEdit();
    confirmPasswordLineEdit->setFixedWidth(window_width / 4); // Set fixed width
    // confirmPasswordLineEdit->setFont(QFont("Arial", 14)); // Set font size to
    // 14
    confirmPasswordLineEdit->setPlaceholderText("Confirm password");
    confirmPasswordLineEdit->setFont(QFont("Arial", 14)); // Set font size to 14
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
    layout->addRow(confirmPasswordLineEdit);

    /* QPushButton *registerButton = new QPushButton("Register"); */
    /* registerButton->setFixedWidth(window_width / 6); // Set fixed width */
    /* registerButton->setFont(QFont("Arial", 14));     // Set font size to 14
     */
    layout->addWidget(this->register_button);

    mainLayout->addLayout(layout); // Add form layout to main layout
    mainLayout->addWidget(
        register_button, 0,
        Qt::AlignCenter); // Add register button to main layout

    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setFocusPolicy(Qt::TabFocus);
    this->setCentralWidget(mainWidget);

    // this->setCentralWidget(game_renderer);
    std::cout << "About Button Applied!\n";
}
