#ifndef CPARROWPLUGIN_H
#define CPARROWPLUGIN_H

/*========================================================================================
    PROJECT Create .dll and .lib for custom Qt Widgets plugin.
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin
    FILE:         cparrowplugin.cpp
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    Header file for definition of class "CpArrowPlugin".

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class CpArrowPlugin : public QObject, public QDesignerCustomWidgetInterface
{
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
  CpArrowPlugin(QObject* parent = 0);

  bool isContainer() const;
  bool isInitialized() const;
  QIcon icon() const;
  QString domXml() const;
  QString group() const;
  QString includeFile() const;
  QString name() const;
  QString toolTip() const;
  QString whatsThis() const;
  QWidget* createWidget(QWidget* parent);
  void initialize(QDesignerFormEditorInterface* core);

private:
  bool m_initialized;
};

#endif // CPARROWPLUGIN_H
