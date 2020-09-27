//
// Created by OgRob on 27.09.2020.
//
#include "Curves.h"
#include "vector"
#include <exception>
#include <memory>
#include <random>

#ifndef TASK_1_CURVES_CONTAINER_H
#define TASK_1_CURVES_CONTAINER_H

class Curves_Container {
private:
  std::vector<std::shared_ptr<Curves>> container;

  class Random {
  public:
    static double Next(double left_border, double right_border) {
      static Random rand = Random(left_border, right_border);
      return rand.dist_(rand.gen_);
    }

  private:
    Random(double left_border, double right_border) {
      std::random_device device;
      gen_ = std::mt19937(device());
      dist_ = std::uniform_real_distribution<>(left_border, right_border);
    }

    std::mt19937 gen_;
    std::uniform_real_distribution<> dist_;
  };

public:
  std::shared_ptr<Curves> RandomGenerate() {

  };

};

#endif // TASK_1_CURVES_CONTAINER_H
