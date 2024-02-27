#pragma once
#include "Race.h"

class eagle_vehicl : public race {
private:
   int V = 8;
public:
   void init(int clientdist);
};