#include "queue"
#include "src/Curves_Container.h"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::cout<<"Enter size of the container:"<<"\n";
  int size=0;
  do {
    std::cin>>size;
  } while (size<=0);
  std::cout<<"\n";
  Curves_Container cur_container;
  cur_container.RandomFill(size);
  cur_container.Print_container();
  cur_container.Sort();
  cur_container.Print_container();

  //auto ellipse_area = cur_container.CalculateArea(0);
  return 0;
}