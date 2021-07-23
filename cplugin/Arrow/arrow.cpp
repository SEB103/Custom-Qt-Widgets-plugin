/***********************************************************************************/
/*!
 *  \brief       Class Arrow
 *  \details     Custom plugins for Qt Creator QWidgets projects.
 *  \copyright   Copyright © 2020-2021.
 *
 *  \file        arrow.cpp
 *  \author      Sergey Burkin
 *  \version     1.0
 */
/***********************************************************************************/
#include "arrow.h"

Arrow::Arrow(QWidget* parent)
    : QWidget(parent)
{}

Arrow::~Arrow()

{
  if(m_Pen != nullptr)
  {
    delete m_Pen;
    m_Pen = nullptr;
  }

  if(m_Brush != nullptr)
  {
    delete m_Brush;
    m_Brush = nullptr;
  }
}
//-----------------------------------------------------------------

void Arrow::paintEvent(QPaintEvent*)
{
  DrawArrow();
}
//-----------------------------------------------------------------

void Arrow::setX0(int Value)
{
  if(m_X0 != Value)

  {
    m_X0 = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setY0(int Value)
{
  if(m_Y0 != Value)
  {
    m_Y0 = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setX1(int Value)
{
  if(m_X1 != Value)
  {
    m_X1 = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setY1(int Value)
{
  if(m_Y1 != Value)
  {
    m_Y1 = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setArrow(TypeArrow ArrowValue)
{
  if(m_Arrow != ArrowValue)
  {
    m_Arrow = ArrowValue;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setLine(TypeLine LineValue)
{
  if(m_Line != LineValue)
  {
    m_Line = LineValue;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setDirection(TypeDirection DirectionValue)
{
  if(m_Direction != DirectionValue)
  {
    m_Direction = DirectionValue;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setLineSlope(bool Value)
{
  if(m_LineSlope != Value)
  {
    m_LineSlope = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setType(TypeArrow ArrowValue, TypeLine LineValue, TypeDirection DirectionValue, bool LineSlopeValue)
{
  //	int m_Type    -   Typ des Pfeils. Es gibt 14 Typen:
  //	0:  Simple arrow
  //	1:  Simple line with colored arrow
  //	2:  Color line with colored arrow
  //	3:  Simple arrow pointing first left/right then and up/down
  //	4:  Simple arrow pointing first up/down and then left/right
  //	5:  Simple line with colored arrow pointing first left/right and then
  //        up/down
  //	6:  Simple line with colored arrow pointing first up/down and then
  //        left/right
  //	7:  Color line with color arrow pointing first left/right and then
  //        up/down
  //	8:  Color line with color arrow pointing first up/down and  then
  //        left/right
  //	9:  Simple arrow with a 90 degree rotationand a slanting line first
  //        left/right and then up/down:
  //	10: Simple arrow with a 90 degree rotationand a slanting line first
  //        up/down and then left/right:
  //	11: Simple line with colored arrow with a 90 degree rotationand a
  //        slanting line first left/right and then up/down:
  //	12: Simple line with colored arrow with a 90 degree rotationand a
  //        slanting line first up/down and then left/right:
  //	13: Color arrow with a 90 degree rotationand a slanting line m_irst
  //        left/right and then up/down:
  //	14: Color arrow with a 90 degree rotationand a slanting line first
  //        up/down and then left/right:
  int temp = -1; // Temp variable for m_Type;
  if(ArrowValue == atSimple && LineValue == ltSimple)
  {
    switch(DirectionValue)
    {
    case dtNone:
    case dtUp:
    case dtDown:
    case dtLeft:
    case dtRight:
      temp = 0;
      break;
    case dtLeUp:
    case dtRiUp:
    case dtLeDown:
    case dtRiDown:
      LineSlopeValue ? temp = 9 : temp = 3;
      break;
    case dtUpLe:
    case dtUpRi:
    case dtDownLe:
    case dtDownRi:
      LineSlopeValue ? temp = 10 : temp = 4;
      break;
    default:
      break;
    } // switch (DirectionValue)
  }   // if (ArrowValue == sstSimple && LineValue ==  sstSimple)

  if(ArrowValue == atColor && LineValue == ltSimple)
  {
    switch(DirectionValue)
    {
    case dtNone:
    case dtUp:
    case dtDown:
    case dtLeft:
    case dtRight:
      temp = 1;
      break;
    case dtLeUp:
    case dtRiUp:
    case dtLeDown:
    case dtRiDown:
      LineSlopeValue ? temp = 11 : temp = 5;
      break;
    case dtUpLe:
    case dtUpRi:
    case dtDownLe:
    case dtDownRi:
      LineSlopeValue ? temp = 12 : temp = 6;
      break;
    default:
      break;
    } // switch (DirectionValue)
  }   // if (ArrowValue == sstColor && LineValue ==  sstSimple)

  if(ArrowValue == atColor && LineValue == ltColor)
  {
    switch(DirectionValue)
    {
    case dtNone:
    case dtUp:
    case dtDown:
    case dtLeft:
    case dtRight:
      temp = 2;
      break;
    case dtLeUp:
    case dtRiUp:
    case dtLeDown:
    case dtRiDown:
      LineSlopeValue ? temp = 13 : temp = 7;
      break;
    case dtUpLe:
    case dtUpRi:
    case dtDownLe:
    case dtDownRi:
      LineSlopeValue ? temp = 14 : temp = 8;
      break;
    default:
      break;
    } // switch (DirectionValue)
  }   // if (ArrowValue == satColor && LineValue ==  ltColor)

  if(m_Type != temp && temp >= 0 && temp < 15)
  {
    m_Type = temp;
    update();
  } // if (m_Type != temp)
}
//-----------------------------------------------------------------

void Arrow::setColorLineWidth(int Value)
{
  if(m_ColorLineWidth != Value)
  {
    m_ColorLineWidth = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setLineAngle(int Value)
{
  if(m_LineAngle != Value)
  {
    m_LineAngle = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setArrowAngle(int Value)
{
  if(m_ArrowAngle != Value)
  {
    m_ArrowAngle = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setArrowLen(int Value)
{
  if(m_ArrowLen != Value)
  {
    m_ArrowLen = Value;
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setPointerOnObj(int PointerOnObjValue)
{
  if(m_PointerOnObj == PointerOnObjValue)
    return;

  m_PointerOnObj = PointerOnObjValue;
}
//-----------------------------------------------------------------

void Arrow::setTag2(int Tag2Value)
{
  if(m_Tag2 == Tag2Value)
    return;
  m_Tag2 = Tag2Value;
}
//-----------------------------------------------------------------

void Arrow::setPenWidth(int width)
{
  if(m_Pen->width() != width)
  {
    m_Pen->setWidth(width);
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setPenColor(QColor color)
{
  if(m_PenColor != color)
  {
    m_PenColor = color;
    m_Pen->setColor(m_PenColor);
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::setBrushColor(QColor color)
{
  if(m_BrushColor != color)
  {
    m_BrushColor = color;
    m_Brush->setColor(m_BrushColor);
    update();
  }
}
//-----------------------------------------------------------------

void Arrow::DrawArrow()
{
  setType(m_Arrow, m_Line, m_Direction, m_LineSlope);

  QPainter Paint(this);
  Paint.setPen(*m_Pen);
  Paint.setBrush(*m_Brush);

  if(m_Pen->width() > 1)
    Paint.setRenderHint(QPainter::Antialiasing, true);
  else
    Paint.setRenderHint(QPainter::Antialiasing, false);

  int d {m_ArrowLen / 2};                     //"d" The distance between xr(yr) and xr0(yr1)
  int w {m_ColorLineWidth};                   //"w" - Color line width
  int k {static_cast<int>(m_ArrowLen * 0.5)}; //"k" shortens length of the line.

  // Calculation of rotation coordinates:
  double x0 {}, y0 {}, x1 {}, y1 {};

  switch(m_Direction)
  {
  case dtUp:
    x0 = m_ArrowLen;
    y0 = height() - d / 2;
    x1 = m_ArrowLen;
    y1 = d / 2;
    break;
  case dtDown:
    x0 = m_ArrowLen;
    y0 = d / 2;
    x1 = m_ArrowLen;
    y1 = height() - d / 2;
    break;
  case dtLeft:
    x0 = width() - d / 2;
    y0 = m_ArrowLen;
    x1 = d / 2;
    y1 = m_ArrowLen;
    break;
  case dtRight:
    x0 = d / 2;
    y0 = m_ArrowLen;
    x1 = width() - d / 2;
    y1 = m_ArrowLen;
    break;
  case dtLeUp:
    x0 = width() - d / 2;
    y0 = height() - d / 2;
    x1 = m_ArrowLen;
    y1 = d / 2;
    break;
  case dtUpLe:
    x0 = width() - d / 2;
    y0 = height() - d / 2;
    x1 = d / 2;
    y1 = m_ArrowLen;
    break;
  case dtRiUp:
    x0 = d / 2;
    y0 = height() - d / 2;
    x1 = width() - m_ArrowLen;
    y1 = d / 2;
    break;
  case dtUpRi:
    x0 = d / 2;
    y0 = height() - d / 2;
    x1 = width() - d / 2;
    y1 = m_ArrowLen;
    break;
  case dtLeDown:
    x0 = width() - d / 2;
    y0 = d / 2;
    x1 = m_ArrowLen;
    y1 = height() - d / 2;
    break;
  case dtDownLe:
    x0 = width() - d / 2;
    y0 = d / 2;
    x1 = d / 2;
    y1 = height() - m_ArrowLen;
    break;
  case dtRiDown:
    x0 = d / 2;
    y0 = d / 2;
    x1 = width() - m_ArrowLen;
    y1 = height() - d / 2;
    break;
  case dtDownRi:
    x0 = d / 2;
    y0 = d / 2;
    x1 = width() - d / 2;
    ;
    y1 = height() - m_ArrowLen;
    break;
  default: // dtNone !!
    x0 = static_cast<double>(m_X0);
    y0 = static_cast<double>(m_Y0);
    x1 = static_cast<double>(m_X1);
    y1 = static_cast<double>(m_Y1);
    break;
  } // switch (FDirection)

  double xr {0};  // X coordinate of rotation
  double yr {0};  // Y coordinate of rotation
  double xr0 {0}; // X starting coordinate of rotation
  double yr0 {0}; // Y starting coordinate of rotation
  double xr1 {0}; // X final coordinate of rotation
  double yr1 {0}; // Y final coordinate of rotation

  int y0_yr {0}; // The distance between y0 and yr
  int yr_y1 {0}; // The distance between yr and y1

  switch(m_Type)
  {
  case 0: // Simple arrow
  case 1: // Simple line with colored arrow
  case 2: // Color line with colored arrow
    xr = x0;
    yr = y0;
    break;
  case 3: // Simple arrow pointing first left/right and then up/down
  case 5: // Simple line with colored arrow pointing first left/right and
          // then up/down
  case 7: // Color line with color arrow pointing first left/right and then
    // up/down
    xr  = x1;
    yr  = y0;
    yr0 = yr;
    xr1 = xr;

    if(xr > x0)
      xr0 = xr - d;
    if(xr < x0)
      xr0 = xr + d;
    if(y1 > yr)
      yr1 = yr + d;
    if(y1 < yr)
      yr1 = yr - d;
    break;
  case 4: // Simple arrow pointing first up/down and then left/right
  case 6: // Simple line with colored arrow pointing first up/down and then
          // left/right
  case 8: // Color line with color arrow pointing first up/down and then
    // left/right
    xr  = x0;
    yr  = y1;
    xr0 = xr;
    yr1 = yr;

    if(yr > y0)
      yr0 = yr - d;
    if(yr < y0)
      yr0 = yr + d;
    if(x1 > xr)
      xr1 = xr + d;
    if(x1 < xr)
      xr1 = xr - d;
    break;
  case 9:  // Simple arrow with a 90 degree rotationand a slanting line first
           // left/right and then up/down:
  case 11: // Simple line with colored arrow with a 90 degree rotationand a
           // slanting line first left/right and then up/down:
  case 13: // Color arrow with a 90 degree rotationand a slanting line first
    // left/right and then up/down:
    if(x1 > x0)
      y0_yr = floor((x1 - x0) * (tan((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
    else if(x1 < x0)
      y0_yr = floor((x0 - x1) * (tan((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
    xr = x1;

    if(y1 > y0)
      yr = y0 + y0_yr;
    else if(y1 < y0)
      yr = y0 - y0_yr;
    break;
  case 10: // Simple arrow with a 90 degree rotationand a slanting line first
           // up/down and then left/right:
  case 12: // Simple line with colored arrow with a 90 degree rotationand a
           // slanting line first up/down and then left/right:
  case 14: // Color arrow with a 90 degree rotationand a slanting line first
    // up/down and then left/right:
    if(x1 > x0)
      yr_y1 = floor((x1 - x0) * (tan((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5); //
    else if(x1 < x0)
      yr_y1 = floor((x0 - x1) * (tan((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5); //
    xr = x0;

    if(y1 > y0)
      yr = y1 - yr_y1; // yr += yr_y1;
    else if(y1 < y0)
      yr = y1 + yr_y1; // yr -= yr_y1;
    break;
  default:
    break;
  } // switch (m_Type)

  double ArrowAngle = (static_cast<double>(m_ArrowAngle)) * M_PI / 180.0;
  // Length of the main line:
  int Len = sqrt((xr - x1) * (xr - x1) + (yr - y1) * (yr - y1));
  // Der Winkel der Hauptlinie:
  double Angle2 {0.0};
  if(xr == x1 && yr < y1)
    Angle2 = M_PI / 2.0;
  else if(xr == x1 && yr > y1)
    Angle2 = 3.0 * M_PI / 2.0;
  else if(xr > x1 && yr == y1)
    Angle2 = 0.0;
  else if(xr < x1 && yr == y1)
    Angle2 = M_PI;
  else if(xr > x1 && yr < y1)
    Angle2 = asin((y1 - yr) / Len);
  else if(xr < x1 && yr < y1)
    Angle2 = M_PI - asin((y1 - yr) / Len);
  else if(xr < x1 && yr > y1)
    Angle2 = M_PI - asin((y1 - yr) / Len);
  else if(xr > x1 && yr > y1)
    Angle2 = 2.0 * M_PI + asin((y1 - yr) / Len);

  int x2 {}, y2 {}, x3 {}, y3 {};

  if(m_Direction != dtNone)
  {
    if((((m_Type == 0 || m_Type == 1 || m_Type == 2) && m_Direction == dtDown) || m_Type == 3 || m_Type == 5 || m_Type == 7 ||
        m_Type == 9 || m_Type == 11 || m_Type == 13) &&
       (y0 < y1))
    {
      int c = int(floor(m_ArrowLen * cos(ArrowAngle) + 0.5));
      int s = int(floor(m_ArrowLen * sin(ArrowAngle) + 0.5));
      x2    = static_cast<int>(x1) + s;
      y2    = static_cast<int>(y1) - c;
      x3    = static_cast<int>(x1) - s;
      y3    = static_cast<int>(y1) - c;
    } // if ((((m_Type == 0 || m_Type == 1 || m_Type == 2) && FDirection ==
    // dtDown)
    // || m_Type == 3 || m_Type == 5 || m_Type == 7 || m_Type == 9 || m_Type == 11
    // || m_Type == 13)	&& (y0 < y1))
    else if((((m_Type == 0 || m_Type == 1 || m_Type == 2) && m_Direction == dtUp) || m_Type == 3 || m_Type == 5 || m_Type == 7 ||
             m_Type == 9 || m_Type == 11 || m_Type == 13) &&
            (y0 > y1))
    {
      int c = int(floor(m_ArrowLen * cos(ArrowAngle) + 0.5));
      int s = int(floor(m_ArrowLen * sin(ArrowAngle) + 0.5));
      x2    = static_cast<int>(x1) + s;
      y2    = static_cast<int>(y1) + c;
      x3    = static_cast<int>(x1) - s;
      y3    = static_cast<int>(y1) + c;
    } // if ((((m_Type == 0 || m_Type == 1 || m_Type == 2) && FDirection == dtUp)
    // || m_Type == 3 || m_Type == 5 || m_Type == 7 || m_Type == 9 || m_Type == 11
    // || m_Type == 13)	&& (y0 > y1))
    else if(((m_Type == 0 || m_Type == 1 || m_Type == 2) && (m_Direction == dtLeft || m_Direction == dtRight)) || m_Type == 4 ||
            m_Type == 6 || m_Type == 8 || m_Type == 10 || m_Type == 12 || m_Type == 14)
    {
      x2 = static_cast<int>(x1) + static_cast<int>(floor(m_ArrowLen * cos(Angle2 + ArrowAngle) +
                                                         0.5)); // The coordinate X of the second vertex of the triangle
      y2 = static_cast<int>(y1) - static_cast<int>(floor(m_ArrowLen * sin(Angle2 + ArrowAngle) +
                                                         0.5)); // The coordinate Y of the second vertex of the triangle
      x3 = static_cast<int>(x1) + static_cast<int>(floor(m_ArrowLen * cos(Angle2 - ArrowAngle) +
                                                         0.5)); // The coordinate X of the third vertex of the triangle
      y3 = static_cast<int>(y1) - static_cast<int>(floor(m_ArrowLen * sin(Angle2 - ArrowAngle) +
                                                         0.5)); // The coordinate Y of the third vertex of the triangle
    }  // else if ((m_Type == 4 || m_Type == 6 || m_Type == 8 || m_Type == 12 ||
       // m_Type == 14)	&& (y0 < y1))
  }    // if (FDirection != dtNone)
  else // FDirection == dtNone
  {
    x2 = static_cast<int>(x1) + static_cast<int>(floor(m_ArrowLen * cos(Angle2 + ArrowAngle) +
                                                       0.5)); // The coordinate X of the second vertex of the triangle
    y2 = static_cast<int>(y1) - static_cast<int>(floor(m_ArrowLen * sin(Angle2 + ArrowAngle) +
                                                       0.5)); // The coordinate Y of the second vertex of the triangle
    x3 = static_cast<int>(x1) + static_cast<int>(floor(m_ArrowLen * cos(Angle2 - ArrowAngle) +
                                                       0.5)); // The coordinate X of the third vertex of the triangle
    y3 = static_cast<int>(y1) - static_cast<int>(floor(m_ArrowLen * sin(Angle2 - ArrowAngle) +
                                                       0.5)); // The coordinate Y of the third vertex of the triangle
  }                                                           // else // if (FDirection != dtNone)

  QPoint* points1 {nullptr}; // A pointer to a dynamic array for poligon, which
                             // will be created in the next step if necessary.
  if(m_Type == 2)
    points1 = new QPoint[4];
  else if(m_Type == 7 || m_Type == 8)
    points1 = new QPoint[8];
  else if(m_Type == 13 || m_Type == 14)
    points1 = new QPoint[6];

  // Draw a line here:
  switch(m_Type)
  {
  case 0: // Simple arrow
  case 1: // Simple line with colored arrow
    Paint.drawLine(x0, y0, x1, y1);
    break;
  case 2: // Color line with colored arrow
    // Hier wird die Linie gezeichnet
    if(x1 == x0 && y1 > y0) // Arrow pointing udown
    {
      points1[0] = QPoint(x0 - w, y0);
      points1[1] = QPoint(x1 - w, y1 - k);
      points1[2] = QPoint(x1 + w, y1 - k);
      points1[3] = QPoint(x0 + w, y0);
    }                       // if(x1 == x0 && y1 > y0)
    if(x1 == x0 && y1 < y0) // Arrow pointing up
    {
      points1[0] = QPoint(x0 - w, y0);
      points1[1] = QPoint(x1 - w, y1 + k);
      points1[2] = QPoint(x1 + w, y1 + k);
      points1[3] = QPoint(x0 + w, y0);
    }                       // if(x1 == x0 && y1 < y0)
    if(y1 == y0 && x1 > x0) // Arrow pointing right
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(x1 - k, y1 - w);
      points1[2] = QPoint(x1 - k, y1 + w);
      points1[3] = QPoint(x0, y0 + w);
    }                       // if(y1 == y0 && x1 > x0)
    if(y1 == y0 && x1 < x0) // Arrow pointing left
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(x1 + k, y1 - w);
      points1[2] = QPoint(x1 + k, y1 + w);
      points1[3] = QPoint(x0, y0 + w);
    } // if(y1 == y0 && x1 < x0)
    Paint.drawPolygon(points1, 4);
    break;
  case 3: // Simple arrow pointing first left/right then and up/down
  case 4: // Simple arrow pointing first up/down and then left/right
  case 5: // Simple line with colored arrow pointing first left/right and
          // then up/down
  case 6: // Simple line with colored arrow pointing first up/down and then
    // left/right
    // Draw lines:
    Paint.drawLine(x0, y0, xr0, yr0);
    Paint.drawLine(xr0, yr0, xr1, yr1);
    Paint.drawLine(xr1, yr1, x1, y1);
    break;
  case 7: // Color line with color arrow pointing first left/right and then
          // up/down
  case 8: // Color line with color arrow pointing first up/down and  then
    // left/right
    // Draw poligon:
    if(xr > x0 && y1 > yr) // Arrow pointing left to right and down
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr0, yr0 - w);
      points1[2] = QPoint(xr1 + w, yr1);
      points1[3] = QPoint(x1 + w, y1 - k); //
      points1[4] = QPoint(x1 - w, y1 - k); //
      points1[5] = QPoint(xr1 - w, yr1 + w);
      points1[6] = QPoint(xr0 - w, yr0 + w);
      points1[7] = QPoint(x0, y0 + w);
    }                      // if(xr > x0 && y1 > yr)
    if(xr < x0 && y1 > yr) // Arrow pointing right to left  and down
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr0, yr0 - w);
      points1[2] = QPoint(xr1 - w, yr1);
      points1[3] = QPoint(x1 - w, y1 - k);
      points1[4] = QPoint(x1 + w, y1 - k);
      points1[5] = QPoint(xr1 + w, yr1 + w);
      points1[6] = QPoint(xr0 + w, yr0 + w);
      points1[7] = QPoint(x0, y0 + w);
    }                      // if(xr < x0 && y1 > yr)
    if(xr > x0 && y1 < yr) // Arrow pointing left to right and up
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr0 - w, yr0 - w);
      points1[2] = QPoint(xr1 - w, yr1 - w);
      points1[3] = QPoint(x1 - w, y1 + k);
      points1[4] = QPoint(x1 + w, y1 + k);
      points1[5] = QPoint(xr1 + w, yr1);
      points1[6] = QPoint(xr0, yr0 + w);
      points1[7] = QPoint(x0, y0 + w);
    }                      // if(xr > x0  && y1 < yr)
    if(xr < x0 && y1 < yr) // Arrow pointing right to left  and up
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr0 + w, yr0 - w);
      points1[2] = QPoint(xr1 + w, yr1 - w);
      points1[3] = QPoint(x1 + w, y1 + k);
      points1[4] = QPoint(x1 - w, y1 + k);
      points1[5] = QPoint(xr1 - w, yr1);
      points1[6] = QPoint(xr0, yr0 + w);
      points1[7] = QPoint(x0, y0 + w);
    }                      // if(xr < x0  && y1 < yr)
    if(yr > y0 && xr < x1) // Arrow pointing down and right
    {
      points1[0] = QPoint(x0 + w, y0);
      points1[1] = QPoint(xr0 + w, yr0 - w);
      points1[2] = QPoint(xr1 + w, yr1 - w);
      points1[3] = QPoint(x1 - k, y1 - w);
      points1[4] = QPoint(x1 - k, y1 + w);
      points1[5] = QPoint(xr1, yr1 + w);
      points1[6] = QPoint(xr0 - w, yr0);
      points1[7] = QPoint(x0 - w, y0);
    }                      // if(yr > y0 && xr < x1)
    if(yr > y0 && xr > x1) // Arrow pointing down and left
    {
      points1[0] = QPoint(x0 - w, y0);
      points1[1] = QPoint(xr0 - w, yr0 - w);
      points1[2] = QPoint(xr1 - w, yr1 - w);
      points1[3] = QPoint(x1 + k, y1 - w);
      points1[4] = QPoint(x1 + k, y1 + w);
      points1[5] = QPoint(xr1, yr1 + w);
      points1[6] = QPoint(xr0 + w, yr0);
      points1[7] = QPoint(x0 + w, y0);
    }                      // if(yr > y0 && xr > x1)
    if(yr < y0 && xr < x1) // Arrow pointing up and right
    {
      points1[0] = QPoint(x0 - w, y0);
      points1[1] = QPoint(xr0 - w, yr0);
      points1[2] = QPoint(xr1, yr1 - w);
      points1[3] = QPoint(x1 - k, y1 - w);
      points1[4] = QPoint(x1 - k, y1 + w);
      points1[5] = QPoint(xr1 + w, yr1 + w);
      points1[6] = QPoint(xr0 + w, yr0 + w);
      points1[7] = QPoint(x0 + w, y0);
    }                      // if(yr < y0 && xr < x1)
    if(yr < y0 && xr > x1) // Arrow pointing up and left
    {
      points1[0] = QPoint(x0 - w, y0);
      points1[1] = QPoint(xr0 - w, yr0 + w);
      points1[2] = QPoint(xr1 - w, yr1 + w);
      points1[3] = QPoint(x1 + k, y1 + w);
      points1[4] = QPoint(x1 + k, y1 - w);
      points1[5] = QPoint(xr1, yr1 - w);
      points1[6] = QPoint(xr0 + w, yr0);
      points1[7] = QPoint(x0 + w, y0);
    } // if(yr < y0 && xr > x1)
    Paint.drawPolygon(points1, 8);
    break;
  case 9:  // Simple arrow with a 90 degree rotationand a slanting line first
           // left/right and then up/down:
  case 10: // Simple arrow with a 90 degree rotationand a slanting line first
           // up/down and then left/right:
  case 11: // Simple line with colored arrow with a 90 degree rotationand a
           // slanting line first left/right and then up/down:
  case 12: // Simple line with colored arrow with a 90 degree rotationand a
    // slanting line first up/down and then left/right:
    // Draw lines:
    Paint.drawLine(x0, y0, xr, yr);
    Paint.drawLine(xr, yr, x1, y1);
    break;
  case 13: // Color arrow with a 90 degree rotationand a slanting line first
           // left/right and then up/down:
  case 14: // Color arrow with a 90 degree rotationand a slanting line first
    // up/down and then left/right:
    // Draw poligon:
    if(xr > x0 && y1 > yr) // Arrow pointing left to right and down
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr + w, yr - w * 0.5);
      points1[2] = QPoint(x1 + w, y1 - k);
      points1[3] = QPoint(x1 - w, y1 - k);
      points1[4] = QPoint(xr - w, yr + w * 0.5);
      points1[5] = QPoint(x0, y0 + w);
    }                      // if(xr > x0 && y1 > yr)
    if(xr < x0 && y1 > yr) // Arrow pointing right to left  and down
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr - w, yr - w * 0.5);
      points1[2] = QPoint(x1 - w, y1 - k);
      points1[3] = QPoint(x1 + w, y1 - k);
      points1[4] = QPoint(xr + w, yr + w * 0.5);
      points1[5] = QPoint(x0, y0 + w);
    }                      // if(xr < x0 && y1 > yr)
    if(xr > x0 && y1 < yr) // Arrow pointing left to right and up
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr - w, yr - w * 0.5);
      points1[2] = QPoint(x1 - w, y1 + k);
      points1[3] = QPoint(x1 + w, y1 + k);
      points1[4] = QPoint(xr + w, yr + w * 0.5);
      points1[5] = QPoint(x0, y0 + w);
    }                      // if(xr > x0  && y1 < yr)
    if(xr < x0 && y1 < yr) // Arrow pointing right to left  and up
    {
      points1[0] = QPoint(x0, y0 - w);
      points1[1] = QPoint(xr + w, yr - w * 0.5);
      points1[2] = QPoint(x1 + w, y1 + k);
      points1[3] = QPoint(x1 - w, y1 + k);
      points1[4] = QPoint(xr - w, yr + w * 0.5);
      points1[5] = QPoint(x0, y0 + w);
    }                      // if(xr < x0  && y1 < yr)
    if(yr > y0 && xr < x1) // Arrow pointing down and right
    {
      int x1_line = x1 - floor((k * cos((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
      int y1_line = y1 - floor((k * cos((static_cast<double>(90 - m_LineAngle)) * M_PI / 180)) + 0.5);
      points1[0]  = QPoint(x0 - w, y0);
      points1[1]  = QPoint(xr - w, yr + w * 0.5);
      points1[2]  = QPoint(x1_line, y1_line + w);
      points1[3]  = QPoint(x1_line, y1_line - w);
      points1[4]  = QPoint(xr + w, yr - w * 0.5);
      points1[5]  = QPoint(x0 + w, y0);
    }                      // if(yr > y0 && xr < x1)
    if(yr > y0 && xr > x1) // Arrow pointing down and left
    {
      int x1_line = x1 + floor((k * cos((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
      int y1_line = y1 - floor((k * cos((static_cast<double>(90 - m_LineAngle)) * M_PI / 180)) + 0.5);
      points1[0]  = QPoint(x0 - w, y0);
      points1[1]  = QPoint(xr - w, yr - w * 0.5);
      points1[2]  = QPoint(x1_line, y1_line - w);
      points1[3]  = QPoint(x1_line, y1_line + w);
      points1[4]  = QPoint(xr + w, yr + w * 0.5);
      points1[5]  = QPoint(x0 + w, y0);
    }                      // if(yr > y0 && xr > x1)
    if(yr < y0 && xr < x1) // Arrow pointing up and right
    {
      int x1_line = x1 - floor((k * cos((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
      int y1_line = y1 + floor((k * cos((static_cast<double>(90 - m_LineAngle)) * M_PI / 180)) + 0.5);
      points1[0]  = QPoint(x0 - w, y0);
      points1[1]  = QPoint(xr - w, yr - w * 0.5);
      points1[2]  = QPoint(x1_line, y1_line - w);
      points1[3]  = QPoint(x1_line, y1_line + w);
      points1[4]  = QPoint(xr + w, yr + w * 0.5);
      points1[5]  = QPoint(x0 + w, y0);
    }                      // if(yr < y0 && xr < x1)
    if(yr < y0 && xr > x1) // Arrow pointing up and left
    {
      int x1_line = x1 + floor((k * cos((static_cast<double>(m_LineAngle)) * M_PI / 180)) + 0.5);
      int y1_line = y1 + floor((k * cos((static_cast<double>(90 - m_LineAngle)) * M_PI / 180)) + 0.5);
      points1[0]  = QPoint(x0 + w, y0);
      points1[1]  = QPoint(xr + w, yr - w * 0.5);
      points1[2]  = QPoint(x1_line, y1_line - w);
      points1[3]  = QPoint(x1_line, y1_line + w);
      points1[4]  = QPoint(xr - w, yr + w * 0.5);
      points1[5]  = QPoint(x0 - w, y0);
    } // if(yr < y0 && xr > x1)
    Paint.drawPolygon(points1, 6);
  default:
    break;
  } // switch (m_Type)

  // Draw an arrow:
  QPoint* points = new QPoint[3];
  switch(m_Type)
  {
  case 0:  // Simple arrow
  case 3:  // Simple arrow pointing first left/right then and up/down
  case 4:  // Simple arrow pointing first up/down and then left/right
  case 9:  // Simple arrow with a 90 degree rotationand a slanting line first
           // left/right and then up/down:
  case 10: // Simple arrow with a 90 degree rotationand a slanting line first
    // up/down and then left/right:
    points[0] = QPoint(x2, y2);
    points[1] = QPoint(x1, y1);
    points[2] = QPoint(x3, y3);
    Paint.drawPolyline(points, 3);
    break;
  case 1:  // Simple line with colored arrow
  case 2:  // Color line with colored arrow
  case 5:  // Simple line with colored arrow pointing first left/right and
           // then up/down
  case 6:  // Simple line with colored arrow pointing first up/down and then
           // left/right
  case 7:  // Color line with color arrow pointing first left/right and then
           // up/down
  case 8:  // Color line with color arrow pointing first up/down and  then
           // left/right
  case 11: // Simple line with colored arrow with a 90 degree rotationand a
           // slanting line first left/right and then up/down:
  case 12: // Simple line with colored arrow with a 90 degree rotationand a
           // slanting line first up/down and then left/right:
  case 13: // Color arrow with a 90 degree rotationand a slanting line first
           // left/right and then up/down:
  case 14: // Color arrow with a 90 degree rotationand a slanting line first
    // up/down and then left/right:
    points[0] = QPoint(x2, y2);
    points[1] = QPoint(x1, y1);
    points[2] = QPoint(x3, y3);
    Paint.drawPolygon(points, 3);
    break;
  default:
    break;
  } // switch (m_Type)

  // Delete dynamic arrays:
  if(points1 != nullptr)
  {
    delete[] points1;
    points1 = nullptr;
  }

  if(points != nullptr)
  {
    delete[] points;
    points = nullptr;
  }

  return;
}
//-----------------------------------------------------------------
