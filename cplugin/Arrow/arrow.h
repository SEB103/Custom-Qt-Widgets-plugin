/***********************************************************************************/
/*!
 *  \brief       Class Arrow
 *  \details     Custom plugins for Qt Creator QWidgets projects.
 *  \copyright   Copyright Â© 2020-2021.
 *
 *  \file        arrow.h
 *  \author      Sergey Burkin
 *  \version     1.0
 */
/***********************************************************************************/

#ifndef ARROW_H
#define ARROW_H

#include <QWidget>
#include <QtGui>

using namespace Qt;

class Arrow : public QWidget
{
  Q_OBJECT

  Q_PROPERTY(int X0 READ X0 WRITE setX0 NOTIFY X0Changed)
  Q_PROPERTY(int Y0 READ Y0 WRITE setY0 NOTIFY Y0Changed)
  Q_PROPERTY(int X1 READ X1 WRITE setX1 NOTIFY X1Changed)
  Q_PROPERTY(int Y1 READ Y1 WRITE setY1 NOTIFY Y1Changed)
  Q_PROPERTY(TypeArrow Arrow READ getArrow WRITE setArrow NOTIFY ArrowChanged)
  Q_PROPERTY(TypeLine Line READ Line WRITE setLine NOTIFY LineChanged)
  Q_PROPERTY(TypeDirection Direction READ Direction WRITE setDirection NOTIFY DirectionChanged)
  Q_PROPERTY(bool LineSlope READ LineSlope WRITE setLineSlope NOTIFY LineSlopeChanged)
  Q_PROPERTY(int ColorLineWidth READ ColorLineWidth WRITE setColorLineWidth NOTIFY ColorLineWidthChanged)
  Q_PROPERTY(int LineAngle READ LineAngle WRITE setLineAngle NOTIFY LineAngleChanged)
  Q_PROPERTY(int ArrowAngle READ ArrowAngle WRITE setArrowAngle NOTIFY ArrowAngleChanged)
  Q_PROPERTY(int ArrowLen READ ArrowLen WRITE setArrowLen NOTIFY ArrowLenChanged)
  Q_PROPERTY(int PointerOnObj READ PointerOnObj WRITE setPointerOnObj NOTIFY PointerOnObjChanged)
  Q_PROPERTY(int Tag2 READ Tag2 WRITE setTag2 NOTIFY Tag2Changed)
  Q_PROPERTY(int PenWidth READ PenWidth WRITE setPenWidth NOTIFY PenWidthChanged)
  Q_PROPERTY(QColor PenColor READ PenColor WRITE setPenColor NOTIFY PenColorChanged)
  Q_PROPERTY(QColor BrushColor READ BrushColor WRITE setBrushColor NOTIFY BrushColorChanged)

public:
  explicit Arrow(QWidget* parent = nullptr);
  ~Arrow();

  // I use the enum keyword to define a set of constants of type int, called an
  // enumeration data type.
  enum TypeArrow { atSimple, atColor };
  Q_ENUM(TypeArrow)

  enum TypeLine { ltSimple, ltColor };
  Q_ENUM(TypeLine)

  enum TypeDirection {
    dtNone,
    dtUp,
    dtDown,
    dtLeft,
    dtRight,
    dtLeUp,
    dtRiUp,
    dtLeDown,
    dtRiDown,
    dtUpLe,
    dtUpRi,
    dtDownLe,
    dtDownRi
  };
  Q_ENUM(TypeDirection)

  // die Ã¼berschriebene Methode
  void setX0(int Value);
  void setY0(int Value);
  void setX1(int Value);
  void setY1(int Value);
  void setArrow(TypeArrow ArrowValue);
  void setLine(TypeLine LineValue);
  void setDirection(TypeDirection DirectionValue);
  void setLineSlope(bool Value);
  void setType(TypeArrow ArrowValue, TypeLine LineValue, TypeDirection DirectionValue, bool LineSlopeValue);
  void setColorLineWidth(int Value);
  void setLineAngle(int Value);
  void setArrowAngle(int Value);
  void setArrowLen(int Value);
  void setPointerOnObj(int PointerOnObjValue);
  void setTag2(int Tag2Value);
  void setPenWidth(int width);
  void setPenColor(QColor color);
  void setBrushColor(QColor color);

  inline int X0() const { return m_X0; }
  inline int Y0() const { return m_Y0; }
  inline int X1() const { return m_X1; }
  inline int Y1() const { return m_Y1; }
  inline TypeArrow getArrow() const { return m_Arrow; }
  inline TypeLine Line() const { return m_Line; }
  inline TypeDirection Direction() const { return m_Direction; }
  inline bool LineSlope() const { return m_LineSlope; }
  inline int ColorLineWidth() const { return m_ColorLineWidth; }
  inline int LineAngle() const { return m_LineAngle; }
  inline int ArrowAngle() const { return m_ArrowAngle; }
  inline int ArrowLen() const { return m_ArrowLen; }
  inline int PointerOnObj() const { return m_PointerOnObj; }
  inline int Tag2() const { return m_Tag2; }
  inline int PenWidth() const { return m_Pen->width(); };
  inline QColor PenColor() const { return m_Pen->color(); };
  inline QColor BrushColor() const { return m_Brush->color(); };

  //***********************************

private:
  int m_X0 {20};                        //   X starting coordinate of arrow
  int m_Y0 {10};                        //   Y starting coordinate of arrow
  int m_X1 {20};                        //   X final coordinate of arrow
  int m_Y1 {90};                        //   Y final coordinate of arrow
  TypeArrow m_Arrow {atSimple};         //  Simple/colored arrow
  TypeLine m_Line {ltSimple};           //  Simple/colored line
  TypeDirection m_Direction {dtRiDown}; //  Pointing first  left/right/up/down
  bool m_LineSlope {false};             //  Arrow line slope
  int m_Type {0};                       //  Type of arrow - 14 Typen.
  int m_ColorLineWidth {2};             // Farbzeilenbreite mit Vorwert = 1 Pixel
  int m_LineAngle {20};                 // Linienwinkel mit voreingestelltem Wert = 30.0
  int m_ArrowAngle {28};                // Pfeilspitzenwinkel mit voreingestelltem Wert = 30.0
  int m_ArrowLen {18};                  // Die Laenge der Hypotenuse des Pfeiles mit
                                        // voreingestelltem Wert = 15
  QPen* m_Pen     = new QPen(black, 2, SolidLine, RoundCap, MiterJoin);
  QBrush* m_Brush = new QBrush(green, SolidPattern);
  QColor m_PenColor;
  QColor m_BrushColor;
  int m_PointerOnObj {0};
  int m_Tag2 {-1};
  void DrawArrow();

protected:
  void paintEvent(QPaintEvent*);

signals:
  void X0Changed(int X0);
  void Y0Changed(int Y0);
  void X1Changed(int X1);
  void Y1Changed(int Y1);
  void ArrowChanged(Arrow::TypeArrow Arrow);
  void LineChanged(Arrow::TypeLine Line);
  void DirectionChanged(Arrow::TypeDirection Direction);
  void LineSlopeChanged(bool LineSlope);
  void ColorLineWidthChanged(int ColorLineWidth);
  void LineAngleChanged(int LineAngle);
  void ArrowAngleChanged(int ArrowAngle);
  void ArrowLenChanged(int ArrowLen);
  void PointerOnObjChanged(int PointerOnObj);
  void Tag2Changed(int Tag2);
  void PenWidthChanged(int PenWidth);
  void PenColorChanged(QColor PenColor);
  void BrushColorChanged(QColor BrushColor);
};

#endif // ARROW_H
