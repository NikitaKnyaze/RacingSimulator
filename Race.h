#pragma once
#include <iostream>
#include "Evehicles.h"
using std::string;

class race {
protected:
   int   V{}, t_race{}, type_v{};
   double time_finish{ 0.0 }; int S_of_rest{}, clientdist{};
   string name;
   int Number_of_rests{}, time_spends_rests{};

public:

   bool init_client_dist(int client_dist);

   bool init_t_r(int t_r);

   bool check_race(int type_v, int t_race);

   virtual void init(int a);

   double get_finish_time();

  string get_name();

};