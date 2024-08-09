#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class LoginDialog;
class RegisterDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_switchRegistrat();


private:
    // 设置窗口尺寸
    void setMainWindow(void);

private:

    LoginDialog *m_loginDialog;
    RegisterDialog *m_registerDialog;
};
#endif // MAINWINDOW_H
