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

private:

  struct point {
    double x;
    double y;
  };

protected:

  point center; // Центр фигуры
  point semiaxis; // Полуоси Эллипса
  type figure_type; // Признак фигуры
  double radius; // Радиус фигуры

public:

  Curves() = default;
  virtual ~Curves() = default;
  virtual double Square() const = 0;
  type Getfigure_type() const {
      return figure_type;
  };

};

#endif // TASK_1_CURVES_H
