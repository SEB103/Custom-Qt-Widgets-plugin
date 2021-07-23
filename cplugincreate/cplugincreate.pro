#Project: Create dll and lib for custom Qt Widgets plugin.

#FILE: CustomPlugin.pro
#AUTHOR: Sergey Burkin

#OVERVIEW
#========
#QMake project file

CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(custom_plugin)
TEMPLATE    = lib

HEADERS     += \
    cp.h \
    cpindicatorplugin.h \
    cparrowplugin.h \

SOURCES     += \
    cp.cpp \
    cpindicatorplugin.cpp \
    cparrowplugin.cpp \

RESOURCES   = icons.qrc

#SEB: Der Pfad für die Bibliothek ist eine Ebene höher als der aktuelle:
DESTDIR = $$PWD/../lib
#DLLDESTDIR = $$PWD/../../../../Qt/Tools/QtCreator/bin/plugins/designer/new_plugins


INCLUDEPATH += \
     $$PWD/../cplugin/Arrow \
     $$PWD/../cplugin/Indicator \

LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(cparrow.pri)
include(cpindicator.pri)



