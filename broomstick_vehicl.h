#pragma once
#include "Race.h"

class broomstick_vehicl : public race {
private:
   int V = 20; double d{};
public:
   void init(int clientdist);
};