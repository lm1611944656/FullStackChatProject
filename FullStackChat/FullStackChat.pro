QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# 可执行文件的文件名
TARGET = WeChat

TEMPLATE = app

# 指定可执行文件的图标
RC_ICON = icon.ico

# 可执行文件的生成目录
DESTDIR = ./bin

SOURCES += \
    global.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    registerdialog.cpp

HEADERS += \
    global.h \
    logindialog.h \
    mainwindow.h \
    registerdialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rc.qrc
