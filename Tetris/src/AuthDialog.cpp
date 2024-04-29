#include "AuthDialog.h"

AuthDialog::AuthDialog(QWidget *parent) : QDialog(parent)
{
    setFixedSize(400, 300);
    move(screen()->geometry().center() - frameGeometry().center());
    this->log_in_button = new QPushButton("Войти");
    this->sign_up_button = new QPushButton("Зарегистрироваться");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(log_in_button);
    layout->addWidget(sign_up_button);

    setLayout(layout);

    connect(log_in_button, &QPushButton::clicked, this, &AuthDialog::on_log_in_button_clicked);
    connect(sign_up_button, &QPushButton::clicked, this, &AuthDialog::on_sign_up_button_clicked);
}

void AuthDialog::on_sign_up_button_clicked()
{
    QGridLayout *gridLayout = new QGridLayout;
    QVBoxLayout *vboxLayout = new QVBoxLayout;
    QHBoxLayout *hboxLayout = new QHBoxLayout;
    QVBoxLayout *topLayout = new QVBoxLayout;

    username_line_edit = new QLineEdit;
    password_line_edit = new QLineEdit;
    password_line_edit->setEchoMode(QLineEdit::Password);

    const QString field_style = "QLineEdit { background-color: white; color: black; }";

    username_line_edit->setStyleSheet(field_style);
    password_line_edit->setStyleSheet(field_style);

    username_line_edit->setFont(QFont("Arial", 14));
    password_line_edit->setFont(QFont("Arial", 14));

    username_line_edit->setPlaceholderText("Username");
    password_line_edit->setPlaceholderText("Password");

    gridLayout->addWidget(username_line_edit, 0, 1);
    gridLayout->addWidget(password_line_edit, 1, 1);

    sign_up_button->setFont(QFont("Arial", 14));
    sign_up_button->setMinimumWidth(username_line_edit->minimumSizeHint().width());
    hboxLayout->addWidget(sign_up_button);

    vboxLayout->addLayout(gridLayout);
    vboxLayout->addLayout(hboxLayout);

    topLayout->addLayout(vboxLayout);
    topLayout->setContentsMargins(100, 0, 100, 0);

    QLayoutItem *item;
    while ((item = layout()->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    delete layout();

    qDebug() << "Hello again";
    disconnect(sign_up_button, &QPushButton::clicked, this, &AuthDialog::on_sign_up_button_clicked);
    connect(sign_up_button, &QPushButton::clicked, this, [this]() {
        qDebug() << "Hello";
        emit sign_up_clicked(username_line_edit->text(), password_line_edit->text());
    });

    setLayout(topLayout);
    // close();
}

void AuthDialog::on_log_in_button_clicked()
{
    QGridLayout *gridLayout = new QGridLayout;
    QVBoxLayout *vboxLayout = new QVBoxLayout;
    QHBoxLayout *hboxLayout = new QHBoxLayout;
    QVBoxLayout *topLayout = new QVBoxLayout;

    username_line_edit = new QLineEdit;
    password_line_edit = new QLineEdit;
    password_line_edit->setEchoMode(QLineEdit::Password);

    const QString field_style = "QLineEdit { background-color: white; color: black; }";

    username_line_edit->setStyleSheet(field_style);
    password_line_edit->setStyleSheet(field_style);

    username_line_edit->setFont(QFont("Arial", 14));
    password_line_edit->setFont(QFont("Arial", 14));

    username_line_edit->setPlaceholderText("Username");
    password_line_edit->setPlaceholderText("Password");

    gridLayout->addWidget(username_line_edit, 0, 1);
    gridLayout->addWidget(password_line_edit, 1, 1);

    log_in_button->setFont(QFont("Arial", 14));
    log_in_button->setMinimumWidth(username_line_edit->minimumSizeHint().width());
    hboxLayout->addWidget(this->log_in_button);

    vboxLayout->addLayout(gridLayout);
    vboxLayout->addLayout(hboxLayout);

    topLayout->addLayout(vboxLayout);
    topLayout->setContentsMargins(100, 0, 100, 0);

    QLayoutItem *item;
    while ((item = layout()->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    delete layout();

    setLayout(topLayout);
}
