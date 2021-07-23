#Project: Custom Qt Widgets plugin "Indicator".

#FILE: CustomPlugin.pro
#AUTHOR: Sergey Burkin

#OVERVIEW
#========
#QMake project file

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    indicator.cpp \
    indicatortestwindow.cpp \
    main_indicator.cpp

HEADERS += \
    indicator.h \
    indicatortestwindow.h

FORMS += \
    indicatortestwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
