/***********************************************************************************/
/*!
 *  \brief       Class Indicator
 *  \details     Custom plugins for Qt Creator QWidgets projects.
 *  \copyright   Copyright © 2020-2021
 *
 *  \file        indicator.h
 *  \author      Sergey Burkin
 *  \version     1.0
 */
/***********************************************************************************/

#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QtGui>
#include <vector>

struct LED
{
  // cppcheck-suppress unusedStructMember
  int Top {0};
  // cppcheck-suppress unusedStructMember
  int Tag {0};
};

class Indicator : public QWidget
{
  Q_OBJECT
  Q_PROPERTY(int Scale READ Scale WRITE setScale NOTIFY ScaleChanged)
  Q_PROPERTY(int StartWidth READ StartWidth WRITE setStartWidth NOTIFY StartWidthChanged)
  Q_PROPERTY(TypeOfIndicator IndicatorTyp READ IndicatorTyp WRITE setIndicatorTyp NOTIFY IndicatorTypChanged)
  Q_PROPERTY(ColorOfIndicator IndicatorColor READ IndicatorColor WRITE setIndicatorColor NOTIFY IndicatorColorChanged)

public:
  explicit Indicator(QWidget* parent = nullptr);

  enum TypeOfIndicator {
    atIndicator_1,
    atIndicator_2,
    atIndicator_3,
  };
  Q_ENUM(TypeOfIndicator)

  enum ColorOfIndicator {
    acGreen,
    acBlue,
  };
  Q_ENUM(ColorOfIndicator)

  inline TypeOfIndicator IndicatorTyp() const { return m_IndicatorTyp; }
  inline ColorOfIndicator IndicatorColor() const { return m_IndicatorColor; }
  inline int StartWidth() const { return m_StartWidth; };
  inline int Scale() const { return m_Scale; };
  virtual void SetLevel(float LevelValue);
  virtual void SetLevelLimits(const float& MinMin, const float& Min, const float& Max, const float& MaxMax,
                              const float& MaxMaxMax);

public slots:
  void setIndicatorTyp(const Indicator::TypeOfIndicator& IndicatorTyp);
  void setIndicatorColor(const Indicator::ColorOfIndicator& IndicatorColor);
  void setStartWidth(const int& startWidth);
  void setScale(const int& scale);

signals:
  void IndicatorTypChanged(Indicator::TypeOfIndicator IndicatorTyp);
  void IndicatorColorChanged(Indicator::ColorOfIndicator IndicatorColor);
  void ScaleChanged(int scale);
  void StartWidthChanged(int startWidth);

protected:
  virtual void RescaleImage(QImage& TempImage);
  virtual void paintEvent(QPaintEvent* event) override;
  virtual void setDefaultWidth(const int& DefaultWidth);

private:
  std::vector<LED> LEDs;
  QImage m_MainPicture;
  int m_ledHeight {3};
  int m_ledWidth {10};
  int m_ledLeft {1};
  int m_Scale {100};
  int m_DefaultWidth {0}; // Spezifizierte Standardbildbreite (Default width)
  int m_StartWidth {0};   // Spezifizierte Startbildbreite
  float m_LevelValue {-1};
  float m_LevelMinMin {0}, m_LevelMin {0}, m_LevelMax {0}, m_LevelMaxMax {0},
      m_LevelMaxMaxMax {0}; //Grenzwerte für den Füllstandsindikator
  TypeOfIndicator m_IndicatorTyp {atIndicator_1};
  ColorOfIndicator m_IndicatorColor {acGreen}; //  acGreen, acBlue
};

#endif // INDICATOR_H
