#pragma once
#include "Race.h"

class carpet_plane_vehicl : public race {
private:
   int V = 10;
public:
   void init(int clientdist);
};