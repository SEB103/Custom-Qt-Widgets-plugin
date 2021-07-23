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
    Source file for definition of class "CpArrowPlugin".

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include "cparrowplugin.h"
#include "arrow.h"

#include <QtPlugin>

CpArrowPlugin::CpArrowPlugin(QObject* parent)
    : QObject(parent)
{
  m_initialized = false;
}

void CpArrowPlugin::initialize(QDesignerFormEditorInterface* /* core */)
{
  if(m_initialized)
    return;

  // Add extension registrations, etc. here

  m_initialized = true;
}

bool CpArrowPlugin::isInitialized() const
{
  return m_initialized;
}

QWidget* CpArrowPlugin::createWidget(QWidget* parent)
{
  return new Arrow(parent);
}

QString CpArrowPlugin::name() const
{
  return QLatin1String("CpArrow");
}

QString CpArrowPlugin::group() const
{
  return QLatin1String("Custom widqets");
}

QIcon CpArrowPlugin::icon() const
{
  return QIcon(QLatin1String(":pictures/Arrow_64.png"));
}

QString CpArrowPlugin::toolTip() const
{
  return QLatin1String("");
}

QString CpArrowPlugin::whatsThis() const
{
  return QLatin1String("");
}

bool CpArrowPlugin::isContainer() const
{
  return false;
}

QString CpArrowPlugin::domXml() const
{
  return QLatin1String("<widget class=\"CpArrow\" name=\"Arrow\">\n</widget>\n");
}

QString CpArrowPlugin::includeFile() const
{
  return QLatin1String("cparrow.h");
}
