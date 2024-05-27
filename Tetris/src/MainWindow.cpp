#include "MainWindow.h"
#include <QFormLayout>
#include <QLineEdit>
#include <qboxlayout.h>
#include <qdebug.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <consoleclient.h>





MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{   client = SingClient::getInstance();
    init_window();
    init_widgets();
    connect_widgets();
    set_main_layout();
    show_auth_dialog();
    show_scores_button();
}

MainWindow::~MainWindow() {}

void MainWindow::show_auth_dialog()
{
    ad->show();
}

void MainWindow::init_window()
{
    setFixedSize(800, 600);
    setWindowTitle(QString("Tetris"));
}

void MainWindow::init_widgets()
{
    ad = new AuthDialog(this);
    timer = new QTimer(this);
    start_button = new QPushButton("Start");
    pause_button = new QPushButton("Pause");
    about_button = new QPushButton("About");
    register_button = new QPushButton("Register");
    sign_in_button = new QPushButton("Sign In");
    sign_up_button = new QPushButton("Sign Up");

    piece_randomizer = Tetris::core::TetrominoFactory::UniformPieceRandomizer;
    this->game_renderer = new Tetris::gui::GameRenderer();
}

void MainWindow::set_main_layout()
{
    register_button->setFont(QFont("Arial", 14));

    buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(start_button);
    buttons_layout->addWidget(pause_button);
    buttons_layout->addWidget(about_button);

    game_renderer = new Tetris::gui::GameRenderer();

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
                     SLOT(init_game_area()));
    QObject::connect(pause_button, SIGNAL(clicked()), this,
                     SLOT(apply_pause_button()));
    QObject::connect(about_button, SIGNAL(clicked()), this,
                     SLOT(apply_about_button()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update_game_area()));
    QObject::connect(ad, SIGNAL(sign_up_clicked(const QString, const QString)), this,
                     SLOT(registration(const QString, const QString)));
}

void MainWindow::handle_sign_up_info(const QString username, const QString password)
{
    qDebug() << username << ' ' << password;
}

void MainWindow::init_game_area(){
    if(start_button->text() == "Resume"){
        timer->start();
        start_button->setText("Restart");
    }else{
        board.clear();
        board.setCurrentPiece(piece_randomizer());
        board.setNextPiece(piece_randomizer());
        game_renderer->setBoard(&board);
        game_renderer->setGameOver(false);

        start_button->setText(QString("Restart"));

        lines = 0;
        level = 0;
        score = 0;

        qDebug() << "init_game_area() successfull";
        timer->start(200);
    }
}


void MainWindow::update_game_area()
{
    qDebug() << "Frame\n";
    if (!board.canMoveCurrentPieceDown()) {
        board.dropCurrentPiece();
        board.swapPieces(piece_randomizer());
        //m_renderPreview->setTetromino(board.getNextPiece());

        if (auto completedRange = board.hasCompletedLines(); completedRange.first && completedRange.second) {
            lines += completedRange.second - completedRange.first;
            // addScore(completedRange.second - completedRange.first);
            // m_labelLines->setText(QString("Lines\n") + QString::number(lines));
            // m_labelScore->setText(QString("Score\n") + QString::number(score));
            // if (m_lines / 10 > (m_lines - (completedRange.second - completedRange.first)) / 10) {
            //     m_level++;
            //     m_labelLevel->setText(QString("Level\n") + QString::number(m_level));
            //     m_timer->stop();
            //     m_timer->start(m_timeUpdate * std::pow(1 - m_timeDecreaseRate, m_level));
            // }

            timer->stop();
            //blinkLines(completedRange.first, completedRange.second);
            timer->start();
            board.eraseLines(completedRange);

        } else if (board.isGameOver()) {
            game_renderer->setGameOver(true);
            game_renderer->update();
            timer->stop();
        }
        //m_renderPreview->update();
    } else {
        board.getCurrentPiece()->setY(board.getCurrentPiece()->getY() + 1);
    }
    game_renderer->update();
}

void MainWindow::apply_start_button()
{
    qDebug() << "Start Button Applied!";
    timer->start(200);
}

void MainWindow::apply_pause_button()
{
    qDebug() << "Pause Button Applied!";
    timer->stop();
    start_button->setText("Resume");
}

void MainWindow::apply_register_button()
{
    QString login = username_line_edit->text();
    QString password = password_line_edit->text();
    std::cout << login.toStdString() << ' ' << password.toStdString() << '\n';

    registration(login, password);
}

void MainWindow::registration(const QString login, const QString password)
{
    qDebug() << "reg " << login << " " << password;
    client->sendToServer("reg " + login + " " + password);
    ad->close();
}

void MainWindow::apply_about_button()
{
    qDebug() << "About Button Applied!";
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left) {
        qDebug() << "Left button pressed";
        if (board.canMoveCurrentPieceLeft()) {
            game_renderer->update();
            board.getCurrentPiece()->setX(board.getCurrentPiece()->getX() - 1);
        }
    } else if (e->key() == Qt::Key_Right) {
        qDebug() << "Right button pressed";
        if (board.canMoveCurrentPieceRight()) {
            game_renderer->update();
            board.getCurrentPiece()->setX(board.getCurrentPiece()->getX() + 1);
        }
    } else if (e->key() == Qt::Key_Up) {
        qDebug() << "Up button pressed";
        if (board.canRotateCurrentPiece()) {
            game_renderer->update();
            board.getCurrentPiece()->setOrientation((board.getCurrentPiece()->getOrientation() + 1) % 4);
        }
    } else if (e->key() == Qt::Key_Down) {
        qDebug() << "Down button pressed";
        if (board.canMoveCurrentPieceDown()) {
            game_renderer->update();
            board.getCurrentPiece()->setY(board.getCurrentPiece()->getY() + 1);
        }
    }
}
void MainWindow::show_scores_button() {
    showScoresButton = new QPushButton("Show User Scores", this);
    main_layout->addWidget(showScoresButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(main_layout);
    setCentralWidget(centralWidget);

    connect(showScoresButton, &QPushButton::clicked, this, &MainWindow::on_showScoresButton_clicked);
    connect(client, &SingClient::userScoresReceived, this, &MainWindow::handleUserScores);
}
void MainWindow::on_showScoresButton_clicked()
{
    resize(width() + 100, height() + 100);
    client->sendToServer("get_user_scores");


}

void MainWindow::handleUserScores(const QVector<QPair<QString, int>> &userScores)
{
    // Создаем новое диалоговое окно
    QDialog *userScoresDialog = new QDialog(this);
    userScoresDialog->setWindowTitle("User Scores");

    // Создаем таблицу для отображения пользовательских оценок
    QTableWidget *tableWidget = new QTableWidget(userScoresDialog);
    tableWidget->setRowCount(userScores.size());
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels({"Username", "Max Score"});

    // Заполняем таблицу данными
    for (int i = 0; i < userScores.size(); ++i) {
        QTableWidgetItem *usernameItem = new QTableWidgetItem(userScores[i].first);
        QTableWidgetItem *maxScoreItem = new QTableWidgetItem(QString::number(userScores[i].second));
        tableWidget->setItem(i, 0, usernameItem);
        tableWidget->setItem(i, 1, maxScoreItem);
    }

    // Создаем кнопку для закрытия окна
    QPushButton *closeButton = new QPushButton("Close", userScoresDialog);
    QObject::connect(closeButton, &QPushButton::clicked, userScoresDialog, &QDialog::close);

    // Создаем компоновку для размещения таблицы и кнопки
    QVBoxLayout *layout = new QVBoxLayout(userScoresDialog);
    layout->addWidget(tableWidget);
    layout->addWidget(closeButton);

    // Устанавливаем компоновку для диалогового окна
    userScoresDialog->setLayout(layout);

    // Показываем диалоговое окно
    userScoresDialog->exec();
}




