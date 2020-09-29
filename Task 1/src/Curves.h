//
// Created by OgRob on 27.09.2020.
//

#ifndef TASK_1_CURVES_H
#define TASK_1_CURVES_H
enum type {
  undefined=0,
  circle,
  ellipse,
};
const double pi = 3.141592653589;

class Curves {
protected:
  struct point {
    double x;
    double y;
  };
/*
  enum type {
    undefined=0,
    circle,
    ellipse,
  };
*/
protected:
  point center; // Центр фигуры
  point semiaxis; // Полуоси Эллипса
  type figure_type; // Признак фигуры
  double radius; // Радиус фигуры

public:
  Curves() = default;
  virtual ~Curves() {};
  virtual double Square() const {};
  type Getfigure_type() const {
      return figure_type;
  }

};

#endif // TASK_1_CURVES_H
