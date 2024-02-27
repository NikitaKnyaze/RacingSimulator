#include "Carpet_Plane.h"

void carpet_plane_vehicl::init(int clientdist) {
   name = "Ковёр-самолёт";
   if (clientdist < 4999) {
      time_finish = (double)clientdist / V;
      return;
   }
   else if (clientdist < 5000) {
      time_finish = (double)(clientdist * 0.97) / V;
      return;
   }
   else if (clientdist < 10000) {

      time_finish = (double)(clientdist * 0.80) / V;
      return;
   }
   else if (clientdist >= 10000) {
      time_finish = (double)(clientdist * 0.95) / V;
      return;
   }
};