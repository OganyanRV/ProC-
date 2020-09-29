//
// Created by OgRob on 27.09.2020.
//
#include "Curves.h"
#include "Circle.h"
#include "Ellipse.h"
#include "vector"
#include <exception>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>

#ifndef TASK_1_CURVES_CONTAINER_H
#define TASK_1_CURVES_CONTAINER_H

class Curves_Container {
protected:
  /*
    enum type {
        undefined=0,
        circle,
        ellipse,
    };
    */
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
    std::uniform_real_distribution<double> dist_;
  };

public:
    Curves_Container() = default;

    Curves_Container(size_t size) {
        container.resize(size);
    }

  std::shared_ptr<Curves> RandomGenerate() {

    double center_x = Random::Next (0.0, 100.0);
    double center_y = Random::Next (0.0, 100.0);
    if ( Random::Next(1.0,2.0) <50.0) {
      double radius = Random::Next(1.0, 100.0);
      Circle object(center_x, center_y, radius);
      return std::make_shared<Circle>(object);
    }
    else {
      double semiaxis_x = Random::Next(1.0, 100.0);
      double semiaxis_y = Random::Next(1.0, 100.0);
      Ellipse object(center_x, center_y, semiaxis_x, semiaxis_y);
      return std::make_shared<Ellipse>(object);
    }
  };

  void RandomFill(std::size_t size) {
    for (std::size_t i=0; i<size; ++i) {
      container.push_back(RandomGenerate());
    }
  }

  double CalculateArea(int object_type = 2) const {
    double area = 0.0;
    if (object_type == 0) {
      for (std::size_t i; i < container.size(); ++i) {
        if (container[i]->Getfigure_type() == ellipse) {
          area += container[i]->Square();
        }
      }
    } else if (object_type == 1) {
      for (std::size_t i; i < container.size(); ++i) {
        if (container[i]->Getfigure_type() == circle) {
          area += container[i]->Square();
        }
      }
    } else {
      for (std::size_t i; i < container.size(); ++i) {
        area += container[i]->Square();
      }
    }
    return area;
  }
  static bool Comparator(std::shared_ptr<Curves> left, std::shared_ptr<Curves> right) {
      return left->Square() < right->Square();
  }
  void Sort() {
        std::sort(container.begin(), container.end(), Comparator);
  }

  void Print_container() {
      for (std::size_t i = 0; i < container.size(); ++i) {
          std::string info;
          if (container[i]->Getfigure_type() == ellipse) info = "Ellipse";
          else info = "Circle";
          std::cout<<info<<" "<<container[i]->Square()<<"\n";
      }
  }

};

#endif // TASK_1_CURVES_CONTAINER_H
