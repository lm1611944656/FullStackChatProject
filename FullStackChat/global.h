#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtWidgets>
#include <QDebug>
#include <functional>       // 函数式编程使用
#include <QStyle>


#define m_cout qDebug()<< "[ "<< __FILE__<< ": "<< __LINE__ << "]"

// 定义一个函数指针用于刷新qss，函数的样式是：【void xxxx(QWidget *)】
extern std::function<void (QWidget *)> repolist;

#endif // GLOBAL_H
