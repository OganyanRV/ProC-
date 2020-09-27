//
// Created by OgRob on 27.09.2020.
//
#include "Curves.h"
#include "vector"
#include <memory>
#ifndef TASK_1_CURVES_CONTAINER_H
#define TASK_1_CURVES_CONTAINER_H

class Curves_Container {
  private:
    std::vector<std::unique_ptr<Curves>> container;
};

#endif // TASK_1_CURVES_CONTAINER_H
