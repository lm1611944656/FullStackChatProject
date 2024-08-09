#include "mainwindow.h"
#include "logindialog.h"
#include "registerdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMainWindow();

    connect(m_loginDialog, &LoginDialog::sig_registerPushButton, this, &MainWindow::slot_switchRegistrat);
}

MainWindow::~MainWindow() {
    // 不指定父窗口，需要手动删除对象
    // if(m_loginDialog){
    //     delete m_loginDialog;
    //     m_loginDialog = nullptr;
    // }

    // if(m_registerDialog){
    //     delete m_registerDialog;
    //     m_registerDialog = nullptr;
    // }
}

void MainWindow::slot_switchRegistrat()
{
    // 创建注册界面
    m_registerDialog = new RegisterDialog(this);
    this->setCentralWidget(m_registerDialog);

    // 隐藏登录界面
    m_loginDialog->hide();

    //显示注册界面
    m_registerDialog->getRegisterStackedWidget()->setCurrentIndex(0);

    // 显示注册成功界面
    //m_registerDialog->getRegisterStackedWidget()->setCurrentIndex(1);
}


void MainWindow::setMainWindow()
{
    this->setMinimumSize(300, 500);
    this->setMaximumSize(300, 500);

    this->setWindowTitle("WeChat");
    this->setWindowIcon(QIcon(":/res/icon.ico"));

    m_loginDialog = new LoginDialog(this);
    this->setCentralWidget(m_loginDialog);
    m_loginDialog->show();
}
