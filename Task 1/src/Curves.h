//
// Created by OgRob on 27.09.2020.
//
#include <math.h>
#ifndef TASK_1_CURVES_H
#define TASK_1_CURVES_H

class Curves {

protected:

  struct point {
    int x;
    int y;
  };

  enum type {
    Undefined=0,
    Circle,
    Ellipse,
  };

private:
  double square; // Площадь фигуры
  point center; // Центр фигуры
  point semiaxis; // Полуоси Эллипса
  type figure_type; // Признак фигуры

public:
  Curves() = default;
  virtual ~Curves();
  virtual double Square() const;



};

#endif // TASK_1_CURVES_H
