/***********************************************************************************/
/*!
 *  \brief       Class Indicator
 *  \details     Custom plugins for Qt Creator QWidgets projects.
 *  \copyright   Copyright © 2020-2021. All Rights Reserved.
 *
 *  \file        indicator.cpp
 *  \author      Sergey Burkin
 *  \version     1.0
 */
/***********************************************************************************/

#include "indicator.h"

Indicator::Indicator(QWidget* parent)
    : QWidget(parent)
{
  // Test:

  m_LevelValue = 95;

  m_StartWidth     = 50;
  m_LevelMinMin    = 5;
  m_LevelMin       = 10;
  m_LevelMax       = 85;
  m_LevelMaxMax    = 90;
  m_LevelMaxMaxMax = 95;
}
//-----------------------------------------------------------------------------

void Indicator::RescaleImage(QImage& TempImage)
{
  if(m_StartWidth == 0)
    setStartWidth(m_DefaultWidth);
  if(m_Scale == 0)
    setScale(100);

  int newWidth {0};

  if(m_Scale == 100)
    newWidth = m_StartWidth;
  else
  {
    double TempWidth = static_cast<double>(m_StartWidth) * m_Scale / 100.0;
    newWidth         = floor(TempWidth + 0.5);
  } // else if(Scale == 100)

  if(TempImage.width() != newWidth)
    TempImage = TempImage.scaledToWidth(newWidth, Qt::SmoothTransformation);
}
//-----------------------------------------------------------------------------

void Indicator::setScale(const int& scale)
{
  if(m_Scale == scale) // ignore if this isn't a change
    return;
  m_Scale = scale; // store the new value
  emit ScaleChanged(m_Scale);
  update();
}
//-----------------------------------------------------------------------------

void Indicator::SetLevel(float LevelValue)
{
  if(m_LevelValue != LevelValue) // ignore if this isn't a change
  {
    m_LevelValue = LevelValue; // store the new value
    update();
  }
}
//-----------------------------------------------------------------------------

void Indicator::SetLevelLimits(const float& MinMin, const float& Min, const float& Max, const float& MaxMax,
                               const float& MaxMaxMax)
{
  m_LevelMinMin    = MinMin;
  m_LevelMin       = Min;
  m_LevelMax       = Max;
  m_LevelMaxMax    = MaxMax;
  m_LevelMaxMaxMax = MaxMaxMax;
  update();
}
//-----------------------------------------------------------------------------

void Indicator::setIndicatorTyp(const Indicator::TypeOfIndicator& IndicatorTyp)
{
  if(m_IndicatorTyp == IndicatorTyp) // ignore if this isn't a change
    return;
  m_IndicatorTyp = IndicatorTyp; // store the new value
  emit IndicatorTypChanged(m_IndicatorTyp);
  update();
}
//-----------------------------------------------------------------------------

void Indicator::setIndicatorColor(const Indicator::ColorOfIndicator& IndicatorColor)
{
  if(m_IndicatorColor == IndicatorColor) // ignore if this isn't a change
    return;
  m_IndicatorColor = IndicatorColor; // store the new value
  emit IndicatorColorChanged(m_IndicatorColor);
  update();
}
//-----------------------------------------------------------------------------

void Indicator::setStartWidth(const int& startWidth)
{
  if(m_StartWidth == startWidth) // ignore if this isn't a change
    return;
  m_StartWidth = startWidth; // store the new value
  emit StartWidthChanged(m_StartWidth);
  update();
}
//-----------------------------------------------------------------------------

void Indicator::setDefaultWidth(const int& defaultWidth)
{
  m_DefaultWidth = defaultWidth;
}
//-----------------------------------------------------------------------------

void Indicator::paintEvent(QPaintEvent*)
{
  // *********** Creating the indicator body: *********************************
  int bodyImgWidth, bodyImgWHeight;

  switch(IndicatorTyp())
  {
  case atIndicator_1:
    //    resize(21, 109);
    bodyImgWidth   = 21;
    bodyImgWHeight = 109;
    break;
  case atIndicator_2:
    //    resize(17, 89);
    bodyImgWidth   = 17;
    bodyImgWHeight = 89;
    break;
  case atIndicator_3:
    //   resize(17, 59);
    bodyImgWidth   = 17;
    bodyImgWHeight = 59;
    break;
  } // switch (color)

  QPen Pen     = QPen(Qt::darkGray, 2, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
  QBrush Brush = QBrush(Qt::darkGray, Qt::SolidPattern);
  QImage bodyImg(bodyImgWidth, bodyImgWHeight, QImage::Format_ARGB32_Premultiplied);
  QPainter painter;

  painter.begin(&bodyImg);
  painter.setRenderHint(QPainter::Antialiasing, false);

  switch(IndicatorTyp())
  {
  case atIndicator_1:
    painter.eraseRect(rect());
    painter.fillRect(rect(), Qt::gray);
    painter.setPen(Pen);
    painter.setBrush(Brush);
    painter.drawRect(2, 2, bodyImg.width() - 4, bodyImg.height() - 4);

    Pen.setWidth(1);
    Pen.setColor(Qt::gray);
    painter.setPen(Pen);
    painter.drawLine(0, height() - 1, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(width() - 1, 0, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(3, 3, 3, bodyImg.height() - 5);
    painter.drawLine(3, 3, bodyImg.width() - 5, 3);

    painter.setPen(Qt::lightGray);
    painter.drawLine(0, 0, 0, bodyImg.height() - 2);
    painter.drawLine(0, 0, bodyImg.width() - 2, 0);
    painter.drawLine(3, bodyImg.height() - 4, bodyImg.width() - 4, bodyImg.height() - 4);
    painter.drawLine(bodyImg.width() - 4, 3, bodyImg.width() - 4, bodyImg.height() - 4);

    break;
  case atIndicator_2:
    painter.eraseRect(rect());
    painter.fillRect(rect(), Qt::gray);
    painter.setPen(Pen);
    painter.setBrush(Brush);
    painter.drawRect(2, 2, bodyImg.width() - 4, bodyImg.height() - 4);

    Pen.setWidth(1);
    Pen.setColor(Qt::gray);
    painter.setPen(Pen);
    painter.drawLine(0, height() - 1, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(width() - 1, 0, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(3, 3, 3, bodyImg.height() - 5);
    painter.drawLine(3, 3, bodyImg.width() - 5, 3);

    painter.setPen(Qt::lightGray);
    painter.drawLine(0, 0, 0, bodyImg.height() - 2);
    painter.drawLine(0, 0, bodyImg.width() - 2, 0);
    painter.drawLine(3, bodyImg.height() - 4, bodyImg.width() - 4, bodyImg.height() - 4);
    painter.drawLine(bodyImg.width() - 4, 3, bodyImg.width() - 4, bodyImg.height() - 4);

    break;
  case atIndicator_3:
    painter.eraseRect(rect());
    painter.fillRect(rect(), Qt::gray);
    painter.setPen(Pen);
    painter.setBrush(Brush);
    painter.drawRect(2, 2, bodyImg.width() - 4, bodyImg.height() - 4);

    Pen.setWidth(1);
    Pen.setColor(Qt::gray);
    painter.setPen(Pen);
    painter.drawLine(0, height() - 1, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(width() - 1, 0, bodyImg.width() - 1, bodyImg.height() - 1);
    painter.drawLine(3, 3, 3, bodyImg.height() - 5);
    painter.drawLine(3, 3, bodyImg.width() - 5, 3);

    painter.setPen(Qt::lightGray);
    painter.drawLine(0, 0, 0, bodyImg.height() - 2);
    painter.drawLine(0, 0, bodyImg.width() - 2, 0);
    painter.drawLine(3, bodyImg.height() - 4, bodyImg.width() - 4, bodyImg.height() - 4);
    painter.drawLine(bodyImg.width() - 4, 3, bodyImg.width() - 4, bodyImg.height() - 4);
    break;
  } // switch (color)
  m_DefaultWidth = bodyImg.width();
  painter.end();

  // *********** Create an indicator screen: ***********

  int displayWidth {0}, displayHeight {0}, correctionHeight {0}, stepLEDs {5};
  int schrittInVector {5};

  switch(IndicatorTyp())
  {
  case atIndicator_1:
    displayWidth     = 13;
    displayHeight    = 101;
    schrittInVector  = 5;
    m_ledHeight      = 3;
    m_ledWidth       = 10;
    m_ledLeft        = 1;
    correctionHeight = 5;
    break;
  case atIndicator_2:
    displayWidth     = 9;
    displayHeight    = 81;
    schrittInVector  = 5;
    m_ledHeight      = 2;
    m_ledWidth       = 6;
    m_ledLeft        = 1;
    correctionHeight = 4;
    stepLEDs         = 4;
    break;
  case atIndicator_3:
    displayWidth     = 9;
    displayHeight    = 51;
    schrittInVector  = 10;
    m_ledHeight      = 3;
    m_ledWidth       = 6;
    m_ledLeft        = 1;
    correctionHeight = 5;
    stepLEDs         = 5;
    break;
  default:
    break;
  } // switch (color)

  QImage displayImg(displayWidth, displayHeight, QImage::Format_ARGB32_Premultiplied);
  painter.begin(&displayImg);
  painter.eraseRect(rect());
  painter.fillRect(rect(), Qt::darkGray);

  for(int i = schrittInVector; i <= 100; i += schrittInVector)
  { // Alle INT-Werte sind hier = Pixels!
    static int Schritt;
    if(i == schrittInVector)
      Schritt = displayImg.height() - correctionHeight;
    LED led {Schritt, i};
    Schritt -= stepLEDs;
    LEDs.push_back(led);
  } // for(int i = 1; i <= 100 ; i+=5)

  enum color { lightgray, darkgray, yellow, stdcolor, orange, red, magenta }; // stdcolor = green || blue
  color IndicatorColor;

  for(uint i = 0; i < LEDs.size(); ++i)
  {
    if(LEDs[i].Tag <= m_LevelValue) //************************************
    {
      //LevelLimits Teil 1:
      if(LEDs[i].Tag <= m_LevelMinMin && m_LevelValue <= m_LevelMinMin)
        IndicatorColor = lightgray;
      else if(LEDs[i].Tag <= m_LevelMin && m_LevelValue <= m_LevelMin)
        IndicatorColor = yellow;
      else if(LEDs[i].Tag <= m_LevelMax)
        IndicatorColor = stdcolor;
      else if(LEDs[i].Tag > m_LevelMax && LEDs[i].Tag <= m_LevelMaxMax)
        IndicatorColor = orange;
      else if(LEDs[i].Tag > m_LevelMaxMax && LEDs[i].Tag <= m_LevelMaxMaxMax)
        IndicatorColor = red;
      else if(LEDs[i].Tag >= m_LevelMaxMaxMax)
        IndicatorColor = magenta;
    }    // if(LEDs->Tag <= FLevelValue)
    else // if(LEDs[i].Tag > m_LevelValue) //********************************
    {
      if(m_LevelValue > 0 && m_LevelValue <= m_LevelMinMin && (LEDs[i].Tag - m_LevelValue) < schrittInVector)
        IndicatorColor = lightgray;
      else if(m_LevelValue > m_LevelMinMin && m_LevelValue <= m_LevelMin && (LEDs[i].Tag - m_LevelValue) < schrittInVector)
        IndicatorColor = yellow;
      else if(m_LevelValue > m_LevelMin && m_LevelValue <= m_LevelMax && (LEDs[i].Tag - m_LevelValue) < schrittInVector)
        IndicatorColor = stdcolor;
      else if(m_LevelValue > m_LevelMax && m_LevelValue <= m_LevelMaxMax && (LEDs[i].Tag - m_LevelValue) < schrittInVector)
        IndicatorColor = orange;
      else if(m_LevelValue > m_LevelMaxMax && m_LevelValue <= m_LevelMaxMaxMax && (LEDs[i].Tag - m_LevelValue) < schrittInVector)
        IndicatorColor = red;
      else if(m_LevelValue > m_LevelMaxMaxMax)
        IndicatorColor = magenta;
      else
        IndicatorColor = darkgray;
    } // else if(LEDs[i].Tag > FLevelValue)

    switch(IndicatorColor) // color {lightgray, darkgray, yellow, stdcolor, orange, red, magenta}
    {
    case lightgray:
      painter.setPen(Qt::white);
      painter.setBrush(Qt::white);
      break;
    case darkgray:
      painter.setPen(Qt::gray);
      painter.setBrush(Qt::gray);
      break;
    case yellow:
      painter.setPen(Qt::yellow);
      painter.setBrush(Qt::yellow);
      break;
    case stdcolor:
      if(m_IndicatorColor == acGreen)
      {
        painter.setPen(Qt::green);
        painter.setBrush(Qt::green);
      }
      else
      {
        painter.setPen(Qt::blue);
        painter.setBrush(Qt::blue);
      }
      break;
    case orange:
      painter.setPen(QPen(QColor(255, 127, 0, 255)));
      painter.setBrush(QBrush(QColor(255, 127, 0, 255), Qt::SolidPattern));
      break;
    case red:
      painter.setPen(Qt::red);
      painter.setBrush(Qt::red);
      break;
    case magenta:
      painter.setPen(Qt::magenta);
      painter.setBrush(Qt::magenta);
      break;
    default:
      break;
    } // switch (color)

    painter.drawRect(m_ledLeft, LEDs[i].Top, m_ledWidth, m_ledHeight);
  } // for(uint i = 0; i < LEDs.size(); ++i)
  painter.end();

  painter.begin(&bodyImg);
  painter.drawImage(4, 4, displayImg);
  painter.end();

  RescaleImage(bodyImg);

  painter.begin(this);
  resize(bodyImg.width(), bodyImg.height());
  painter.fillRect(rect(), Qt::red);

  painter.drawImage(0, 0, bodyImg);
  painter.end();
}
//-----------------------------------------------------------------
