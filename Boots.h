#pragma once
#include "Race.h"

class boots_vehicl : public race {
protected:
   const int V = 6, t_before_rest = 60, t_rest1 = 10, t_rest2 = 5;

public:
   void init(int clientdist);
};