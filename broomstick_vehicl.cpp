#include "broomstick_vehicl.h"

   void broomstick_vehicl::init(int clientdist) {
      name = "Метла";
      d = (100 - (clientdist / 1000)) * 0.01;
      time_finish = ((double)clientdist * d) / V;
   };
