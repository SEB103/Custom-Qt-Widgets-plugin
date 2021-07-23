/*========================================================================================
    PROJECT Create .dll and .lib for custom Qt Widgets plugin.
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin
    FILE:         cpindicatorplugin.cpp
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    Source file for definition of class "CpIndicatorPlugin".

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include "cpindicatorplugin.h"
#include "indicator.h"
#include <QtPlugin>

CpIndicatorPlugin::CpIndicatorPlugin(QObject* parent)
    : QObject(parent)
{
  m_initialized = false;
}

void CpIndicatorPlugin::initialize(QDesignerFormEditorInterface* /* core */)
{
  if(m_initialized)
    return;

  // Add extension registrations, etc. here

  m_initialized = true;
}

bool CpIndicatorPlugin::isInitialized() const
{
  return m_initialized;
}

QWidget* CpIndicatorPlugin::createWidget(QWidget* parent)
{
  return new Indicator(parent);
}

QString CpIndicatorPlugin::name() const
{
  return QLatin1String("CpIndicator");
}

QString CpIndicatorPlugin::group() const
{
  return QLatin1String("Custom widqets");
}

QIcon CpIndicatorPlugin::icon() const
{
  return QIcon(QLatin1String(":pictures/Indicator_64.png"));
}

QString CpIndicatorPlugin::toolTip() const
{
  return QLatin1String("");
}

QString CpIndicatorPlugin::whatsThis() const
{
  return QLatin1String("");
}

bool CpIndicatorPlugin::isContainer() const
{
  return false;
}

QString CpIndicatorPlugin::domXml() const
{
  return QLatin1String("<widget class=\"CpIndicator\" name=\"Indicator\">\n</widget>\n");
}

QString CpIndicatorPlugin::includeFile() const
{
  return QLatin1String("cpIndicator.h");
}
