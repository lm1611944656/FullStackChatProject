#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    :QDialog(parent)
{
    this->setMinimumSize(300, 500);
    this->setMaximumSize(300, 500);
    setObjectName("LoginDialog");

    setLoginDialogWindow();

    // 设置Dialog为无边框的样式，这样会嵌入到MainWindow窗口中(LoginDialog的对象树指定了MainWindow)
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    connect(m_registerPushButton, &QPushButton::clicked, this, &LoginDialog::sig_registerPushButton);
}

void LoginDialog::setLoginDialogWindow(){
    // 总的垂直布局
    m_verticalLayout_2 = new QVBoxLayout(this);

    // 错误提示标签
    m_errTipLabel = new QLabel(this);
    m_verticalLayout_2->addWidget(m_errTipLabel);

    // 二维码位置
    m_headWidget = new QWidget(this);
    QVBoxLayout *m_vBoxLayout = new QVBoxLayout(m_headWidget);
    m_headlabel = new QLabel(this);
    m_headlabel->setPixmap(QPixmap(":/res/ice.png"));
    m_headlabel->setAlignment(Qt::AlignHCenter);
    m_vBoxLayout->addWidget(m_headlabel);
    m_headWidget->setLayout(m_vBoxLayout);
    m_verticalLayout_2->addWidget(m_headWidget);

    m_verticalLayout_2->addItem(new QSpacerItem(20, 25, QSizePolicy::Expanding, QSizePolicy::Fixed));

    // email填写位置
    QHBoxLayout *m_emailHBoxLayout = new QHBoxLayout();
    m_emailLabel = new QLabel(this);
    m_emailLabel->setText(tr("用户："));
    m_emailLineEdit = new QLineEdit(this);
    m_emailLineEdit->setMinimumHeight(25);
    m_emailLineEdit->setMaximumHeight(25);
    m_emailHBoxLayout->addWidget(m_emailLabel);
    m_emailHBoxLayout->addWidget(m_emailLineEdit);
    m_emailHBoxLayout->addItem(new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_verticalLayout_2->addLayout(m_emailHBoxLayout);

    // 密码填写位置
    QHBoxLayout *m_passwordHBoxLayout = new QHBoxLayout();
    m_passwordLabel = new QLabel(this);
    m_passwordLabel->setText(tr("密码："));
    m_passwordLineEdit = new QLineEdit(this);
    m_passwordLineEdit->setMinimumHeight(25);
    m_passwordLineEdit->setMaximumHeight(25);
    m_passwordHBoxLayout->addWidget(m_passwordLabel);
    m_passwordHBoxLayout->addWidget(m_passwordLineEdit);
    m_passwordHBoxLayout->addItem(new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_verticalLayout_2->addLayout(m_passwordHBoxLayout);

    // 忘记密码
    QHBoxLayout *m_forgetPasswordHBoxLayout = new QHBoxLayout();
    m_forgetPasswordLabel = new QLabel(this);
    m_forgetPasswordLabel->setText(tr("忘记密码"));
    m_forgetPasswordHBoxLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    m_forgetPasswordHBoxLayout->addWidget(m_forgetPasswordLabel);
    m_verticalLayout_2->addLayout(m_forgetPasswordHBoxLayout);

    m_verticalLayout_2->addItem(new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed));

    // 登录按钮
    QHBoxLayout *m_loginHBoxLayout = new QHBoxLayout();
    m_loginPushButton = new QPushButton(this);
    m_loginPushButton->setText(tr("登录"));
    m_loginHBoxLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_loginHBoxLayout->addWidget(m_loginPushButton);
    m_loginHBoxLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_verticalLayout_2->addLayout(m_loginHBoxLayout);

    // 注册按钮
    QHBoxLayout *m_registerHBoxLayout = new QHBoxLayout();
    m_registerPushButton = new QPushButton(this);
    m_registerPushButton->setText(tr("注册"));
    m_registerHBoxLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_registerHBoxLayout->addWidget(m_registerPushButton);
    m_registerHBoxLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed));
    m_verticalLayout_2->addLayout(m_registerHBoxLayout);

    m_forgetPasswordHBoxLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Expanding));
}
