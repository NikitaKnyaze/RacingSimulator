#include "Camel_vehicl.h"

   void camel_vehicl::init(int clientdist) {
      name = "Верблюд";
      S_of_rest = V * t_before_rest;
      Number_of_rests = clientdist / S_of_rest;
      if (Number_of_rests < 1) {
         time_finish = ((double)clientdist / V);
         return;
      }
      else if (Number_of_rests < 2) {
         time_finish = ((double)clientdist / V) + t_rest1;
         return;
      }
      else {
         time_spends_rests = t_rest1 + (t_rest2 * (Number_of_rests - 1));
         time_finish = ((static_cast<double>(clientdist) / V)) + time_spends_rests;
         return;
      }
};