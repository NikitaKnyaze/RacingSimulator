#include "Race.h"

bool race::init_client_dist(int client_dist) {
   if (client_dist <= 0)
      return true ;
   else
      return false;
};

bool race::init_t_r(int t_r) {
   if (t_r <= 0 || t_r > 3)
      return true;
   else
      return false;
};

   bool race::check_race(int type_v, int t_race) {

      if (t_race == 3) {
         return false;
      }
      else if ((type_v == vehicles::broomstick || type_v == 0 || type_v == vehicles::eagle || type_v == vehicles::carpet_plane) && t_race == 2) {
         return false;
      }
      else if ((type_v == vehicles::boots || type_v == vehicles::camel || type_v == vehicles::cent
         || type_v == vehicles::fast_camel || type_v == 0) && t_race == 1) {
         return false;
      }
   };

  void race::init(int a) {
      clientdist = a;
   };

  double race::get_finish_time() {
     return time_finish;
  };

  string race::get_name() {
     return name;
  };

