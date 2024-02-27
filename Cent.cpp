#include "Cent.h"

   void cent_vehicl::init(int clientdist) {
      name = "Кентавр";
      S_of_rest = V * t_before_rest;
      Number_of_rests = clientdist / S_of_rest;
      time_spends_rests = t_rest1 * Number_of_rests;
      time_finish = ((double)clientdist / V) + time_spends_rests;
   };

