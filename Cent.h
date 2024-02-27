#pragma once
#include "Race.h"

class cent_vehicl : public race {
protected:
   const int V = 15, t_before_rest = 8, t_rest1 = 2;
   int Number_of_rests{};
public:
   void init(int clientdist);
};