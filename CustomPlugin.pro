#Project: Custom Qt Widgets plugin.

#FILE: CustomPlugin.pro
#AUTHOR: Sergey Burkin

#OVERVIEW
#========
#QMake project file

TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
        cplugin \
        cplugincreate \

