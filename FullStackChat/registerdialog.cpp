#include "registerdialog.h"
#include "global.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    :QDialog(parent)
{
    this->setMinimumSize(300, 500);
    this->setMaximumSize(300, 500);

    setObjectName("RegisterDialog");
    setRegisterDialogWindow();

    // 设置Dialog为无边框的样式，这样会嵌入到MainWindow窗口中[RegisterDialog(this))]
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

RegisterDialog::~RegisterDialog()
{

}

QStackedWidget *RegisterDialog::getRegisterStackedWidget()
{
    return m_registerStackedWidget;
}

void RegisterDialog::slot_verifCodeButClick()
{
    m_cout << "获取验证码！";
    auto email = m_registerEmailLineEdit->text();

    // 定义邮箱的正则表达式
    QRegularExpression emailRegex(R"((^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$))");

    // 检查输入的邮箱地址是否匹配正则表达式
    QRegularExpressionMatch match = emailRegex.match(email);

    // 判断邮箱是否匹配正确
    if(match.hasMatch()){
        // 发送http验证码
    }else{
        showTip(tr("邮箱地址不正确！"), false);
    }
}

void RegisterDialog::setRegisterDialogWindow()
{
    m_registerVBoxLayout = new QVBoxLayout(this);

    m_registerStackedWidget = new QStackedWidget(this);
    m_registerVBoxLayout->addWidget(m_registerStackedWidget);

    // 页面1
    m_registerWindow = new QWidget(m_registerStackedWidget);

    // 页面1中的垂直布局
    QVBoxLayout *layout1 = new QVBoxLayout(m_registerWindow);
    layout1->addItem(new QSpacerItem(20, 40, QSizePolicy::MinimumExpanding, QSizePolicy::Expanding));


    m_registerErrorTip = new QLabel(errTip, this);
    m_registerErrorTip->setAlignment(Qt::AlignCenter);
    m_registerErrorTip->setObjectName("m_registerErrorTip");
    // 标签设置一个状态(正常)
    m_registerErrorTip->setProperty("state_1", "normal");

    // 刷新错误提示的样式
    repolist(m_registerErrorTip);
    //m_registerErrorTip->hide();
    layout1->addWidget(m_registerErrorTip);

    QHBoxLayout *hBoxLayout1 = new QHBoxLayout();
    m_registerUserLabel = new QLabel(tr("用户："), this);
    m_registerUserLineEdit = new QLineEdit(this);
    hBoxLayout1->addWidget(m_registerUserLabel);
    hBoxLayout1->addWidget(m_registerUserLineEdit);
    layout1->addLayout(hBoxLayout1);

    QHBoxLayout *hBoxLayout2 = new QHBoxLayout();
    m_registerEmailLabel = new QLabel(tr("邮箱："), this);
    m_registerEmailLineEdit = new QLineEdit(this);
    hBoxLayout2->addWidget(m_registerEmailLabel);
    hBoxLayout2->addWidget(m_registerEmailLineEdit);
    layout1->addLayout(hBoxLayout2);

    QHBoxLayout *hBoxLayout3 = new QHBoxLayout();
    m_registerPasswordLabel = new QLabel(tr("密码："), this);
    m_registerPasswordLineEdit = new QLineEdit(this);
    m_registerPasswordLineEdit->setEchoMode(QLineEdit::Password);
    hBoxLayout3->addWidget(m_registerPasswordLabel);
    hBoxLayout3->addWidget(m_registerPasswordLineEdit);
    layout1->addLayout(hBoxLayout3);

    QHBoxLayout *hBoxLayout4 = new QHBoxLayout();
    m_registerConfirmPasswordLabel = new QLabel(tr("确认："), this);
    m_registerConfirmPasswordLineEdit = new QLineEdit(this);
    m_registerConfirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
    hBoxLayout4->addWidget(m_registerConfirmPasswordLabel);
    hBoxLayout4->addWidget(m_registerConfirmPasswordLineEdit);
    layout1->addLayout(hBoxLayout4);

    QHBoxLayout *hBoxLayout5 = new QHBoxLayout();
    m_registerVerificationCodeLabel = new QLabel(tr("验证码："), this);
    m_registerVerificationCodeLineEdit = new QLineEdit(this);
    m_registerGetVerificationCode = new QPushButton(tr("获取验证码"), this);
    connect(m_registerGetVerificationCode, &QPushButton::clicked, this, &RegisterDialog::slot_verifCodeButClick);
    hBoxLayout5->addWidget(m_registerVerificationCodeLabel);
    hBoxLayout5->addWidget(m_registerVerificationCodeLineEdit);
    hBoxLayout5->addWidget(m_registerGetVerificationCode);
    layout1->addLayout(hBoxLayout5);

    // 添加一个弹簧
    layout1->addItem(new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding));

    QHBoxLayout *hBoxLayout6 = new QHBoxLayout();
    m_registerConfirmButton = new QPushButton(tr("确认"), this);
    m_registerCancelButton = new QPushButton(tr("取消"), this);
    hBoxLayout6->addWidget(m_registerConfirmButton);
    hBoxLayout6->addWidget(m_registerCancelButton);
    layout1->addLayout(hBoxLayout6);

    layout1->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));

    m_registerStackedWidget->addWidget(m_registerWindow);

    // 页面2
    m_registerWindow2 = new QWidget(m_registerStackedWidget);

    // 页面2中的垂直布局
    QVBoxLayout *layout2 = new QVBoxLayout(m_registerWindow2);

    layout2->addItem(new QSpacerItem(20, 100, QSizePolicy::Expanding, QSizePolicy::Expanding));

    QHBoxLayout *hBoxLayout7 = new QHBoxLayout();
    m_registerSuccessfulTip = new QLabel(tr("注册成功"), this);
    hBoxLayout7->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));
    hBoxLayout7->addWidget(m_registerSuccessfulTip);
    hBoxLayout7->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));
    layout2->addLayout(hBoxLayout7);

    layout2->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));

    QHBoxLayout *hBoxLayout8 = new QHBoxLayout();
    m_registerBackLogin = new QPushButton(tr("返回登录"), this);
    hBoxLayout8->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));
    hBoxLayout8->addWidget(m_registerBackLogin);
    hBoxLayout8->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));
    layout2->addLayout(hBoxLayout8);

    layout2->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));

    m_registerStackedWidget->addWidget(m_registerWindow2);

    m_registerVBoxLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));
}

void RegisterDialog::showTip(QString str, bool isMatch)
{
    if(!isMatch){
        // 设置错误提示标签为错误状态
        m_registerErrorTip->setProperty("state_1", "err");
    }

    // 修改错误提示标签的提示信息
    m_registerErrorTip->setText(str);

    // 刷新状态
    repolist(m_registerErrorTip);
}

