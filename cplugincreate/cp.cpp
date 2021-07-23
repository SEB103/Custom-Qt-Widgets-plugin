/*========================================================================================
    PROJECT Create .dll and .lib for custom Qt Widgets plugin.
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin
    FILE:         cp.cpp
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    Source file for definition of class "cp".(custom plugin)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include "cp.h"
#include "cparrowplugin.h"
#include "cpindicatorplugin.h"

cp::cp(QObject* parent)
    : QObject(parent)
{
  m_widgets.append(new CpArrowPlugin(this));
  m_widgets.append(new CpIndicatorPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> cp::customWidgets() const
{
  return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(custom_plugin, cplugin)
#endif // QT_VERSION < 0x050000
