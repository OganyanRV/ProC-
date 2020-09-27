//
// Created by OgRob on 27.09.2020.
//

const double Pi = 3.141592653589;
#include "Curves.h"
#include <stdexcept>

#ifndef TASK_1_ELLIPSE_H
#define TASK_1_ELLIPSE_H

class Ellipse : public Curves {
  Ellipse(double center_x = 0.0, double center_y = 0.0, double semiaxis_x = 1.0, double semiaxis_y = 1.0) {
    if (semiaxis_x < 0 || semiaxis_y <0 ) {
      throw std::runtime_error("Semiaxis are incorrect");
    }
    center.x = center_x;
    center.y = center_y;
    semiaxis.x = semiaxis_x;
    semiaxis.y = semiaxis_y;
    figure_type = ellipse;
  };

  double Square() const override {
    return Pi * semiaxis.x * semiaxis.y;
  };
};

#endif // TASK_1_ELLIPSE_H
