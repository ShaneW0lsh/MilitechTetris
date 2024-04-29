#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QScreen>

class AuthDialog : public QDialog
{
    Q_OBJECT

  public:
    AuthDialog(QWidget *parent = nullptr);

  signals:
    void sign_up_clicked(const QString username, const QString password);
    void log_in_clicked(const QString usirname, const QString password);

  private slots:
    void on_sign_up_button_clicked();
    void on_log_in_button_clicked();

  private:
    QPushButton* sign_up_button;
    QPushButton* log_in_button;
    // QPushButton* real_log_in_button;

    QLineEdit* username_line_edit;
    QLineEdit* password_line_edit;
};

#endif // LOGINDIALOG_H
