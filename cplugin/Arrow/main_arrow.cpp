/*========================================================================================
    PROJECT Custom Qt Widgets plugin
==========================================================================================
    Copyright (c) 2021. Sergey Burkin.
    GNU GENERAL PUBLIC LICENSE Version 2, June 1991.

    SUBSYSTEM:    Custom Qt Widgets plugin "Arrow"
    FILE:         main_arrow.cpp
    AUTHOR:       Sergey Burkin

    OVERVIEW
    ========
    main.cpp

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
==========================================================================================*/
#include "arrowtestwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  ArrowTestWindow w;
  w.show();
  return a.exec();
}
