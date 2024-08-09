#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtWidgets>

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);

signals:
    // 注册按钮的信号
    void sig_registerPushButton();

private:
    void setLoginDialogWindow(void);

private:
    QVBoxLayout *m_verticalLayout_2;

    QLabel *m_errTipLabel;

    QWidget *m_headWidget;
    QLabel *m_headlabel;

    QLabel *m_emailLabel;
    QLineEdit *m_emailLineEdit;

    QLabel *m_passwordLabel;
    QLineEdit *m_passwordLineEdit;

    QLabel *m_forgetPasswordLabel;

    QPushButton *m_loginPushButton;
    QPushButton *m_registerPushButton;

};

#endif // LOGINDIALOG_H
