#ifndef INDICATORTESTWINDOW_H
#define INDICATORTESTWINDOW_H
/*========================================================================================
    PROJECT Custom Qt Widgets plugin
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin "Indicator"
    FILE:         indicatortestwindow.h
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    Header file for definition of class "ArrowTestWindow".

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class IndicatorTestWindow;
}
QT_END_NAMESPACE

class IndicatorTestWindow : public QMainWindow
{
  Q_OBJECT

public:
  IndicatorTestWindow(QWidget* parent = nullptr);
  ~IndicatorTestWindow();

private:
  Ui::IndicatorTestWindow* ui;
};
#endif // INDICATORTESTWINDOW_H
