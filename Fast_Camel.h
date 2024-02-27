#pragma once
#include "Race.h"

class fast_camel_vehicl : public race {
protected:
   const int V = 40, t_before_rest = 10, t_rest1 = 5, t_rest3 = 8;
   double t_rest2 = 6.5, time_spends_rests = 0.0;
   int Number_of_rests{};
public:
   void init(int clientdist);
};