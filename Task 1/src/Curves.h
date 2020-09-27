//
// Created by OgRob on 27.09.2020.
//
#include <math.h>
#ifndef TASK_1_CURVES_H
#define TASK_1_CURVES_H

class Curves {

protected:

  struct point {
    double x;
    double y;
  };

  enum type {
    undefined=0,
    circle,
    ellipse,
  };

protected:
  double square; // Площадь фигуры
  point center; // Центр фигуры
  point semiaxis; // Полуоси Эллипса
  type figure_type; // Признак фигуры
  double radius; // Радиус фигуры

public:
  Curves() = default;
  virtual ~Curves();
  virtual double Square() const;

};

#endif // TASK_1_CURVES_H
