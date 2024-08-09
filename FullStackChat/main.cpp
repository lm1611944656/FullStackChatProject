#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载qss文件
    QFile m_qss(":/style/stylesheet.qss");
    if(m_qss.open(QFile::ReadOnly)){
        qDebug() << "打开成功！";
        QString style = QLatin1String(m_qss.readAll());
        a.setStyleSheet(style);
        m_qss.close();
    }else {
        qDebug() << "样式表打开失败！";
    }
    MainWindow w;
    w.show();
    return a.exec();
}
