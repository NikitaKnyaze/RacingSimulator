#include "Fast_Camel.h"

   void fast_camel_vehicl::init(int clientdist) {
      name = "Верблюд-быстроход";
      S_of_rest = V * t_before_rest;
      Number_of_rests = clientdist / S_of_rest;
      time_finish = ((double)clientdist / V);
      if (Number_of_rests < 1) {
         time_finish;
         return;
      }
      else if (Number_of_rests < 2) {
         time_finish = time_finish + t_rest1;
         return;
      }
      else if (Number_of_rests < 3) {
         time_spends_rests = t_rest1 + t_rest2;
         time_finish = time_finish + time_spends_rests;
         return;
      }
      else {
         time_spends_rests = t_rest1 + t_rest2 + (t_rest3 * (Number_of_rests - 2));
         time_finish = time_finish + time_spends_rests;
         return;
      }
   };
