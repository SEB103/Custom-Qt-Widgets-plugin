#ifndef ARROWTESTWINDOW_H
#define ARROWTESTWINDOW_H
/*========================================================================================
    PROJECT Custom Qt Widgets plugin
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin "Arrow"
    FILE:         arrowtestwindow.h
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
class ArrowTestWindow;
}
QT_END_NAMESPACE

class ArrowTestWindow : public QMainWindow
{
  Q_OBJECT

public:
  ArrowTestWindow(QWidget* parent = nullptr);
  ~ArrowTestWindow();

private:
  Ui::ArrowTestWindow* ui;
};
#endif // ARROWTESTWINDOW_H
