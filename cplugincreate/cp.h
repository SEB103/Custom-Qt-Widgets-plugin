#ifndef CP_H
#define CP_H
/*========================================================================================
    PROJECT Create .dll and .lib for custom Qt Widgets plugin.
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin
    FILE:         cp.h
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    Header file for definition of class "cp".(custom plugin)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include <QtDesigner>
#include <qplugin.h>

class cp : public QObject, public QDesignerCustomWidgetCollectionInterface
{
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)
#if QT_VERSION >= 0x050000
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
#endif // QT_VERSION >= 0x050000

public:
  explicit cp(QObject* parent = 0);

  virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

private:
  QList<QDesignerCustomWidgetInterface*> m_widgets;
};

#endif // CP_H
