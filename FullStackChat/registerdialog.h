#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QtWidgets>

class RegisterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    QStackedWidget *getRegisterStackedWidget(void);

private slots:
    void slot_verifCodeButClick(void);


private:
    void setRegisterDialogWindow(void);

    // 邮箱填写错误的提示
    void showTip(QString str, bool isMatch);

private:
    QVBoxLayout *m_registerVBoxLayout;

    QStackedWidget *m_registerStackedWidget;

    QWidget *m_registerWindow;
    QWidget *m_registerWindow2;

    QLabel *m_registerErrorTip;

    QLabel *m_registerUserLabel;
    QLineEdit *m_registerUserLineEdit;

    QLabel *m_registerEmailLabel;
    QLineEdit *m_registerEmailLineEdit;

    QLabel *m_registerPasswordLabel;
    QLineEdit *m_registerPasswordLineEdit;

    QLabel *m_registerConfirmPasswordLabel;
    QLineEdit *m_registerConfirmPasswordLineEdit;

    QLabel *m_registerVerificationCodeLabel;
    QLineEdit *m_registerVerificationCodeLineEdit;

    QPushButton *m_registerGetVerificationCode;
    QPushButton *m_registerConfirmButton;
    QPushButton *m_registerCancelButton;

    QLabel *m_registerSuccessfulTip;
    QPushButton *m_registerBackLogin;

    // 错误提示信息
    QString errTip = "请正确填写注册信息";
};

#endif // REGISTERDIALOG_H
