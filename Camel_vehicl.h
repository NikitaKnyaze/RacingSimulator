#pragma once
#include "Race.h"

class camel_vehicl : public race {
protected:
   const int V = 10, t_before_rest = 30, t_rest1 = 5, t_rest2 = 8;
   int Number_of_rests{};
public:
   void init(int clientdist);
};