// RacingSimulator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include "Race.h"
#include "Boots.h"
#include "Camel_vehicl.h"
#include "Cent.h"
#include "Fast_Camel.h"
#include "Carpet_Plane.h"
#include "eagle_vehicl.h"
#include "broomstick_vehicl.h"

using std::cout;
using std::cin;

//_______________________________________________________________________________________________________________________________
int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   int clientdist; int n = 0, t_r{}, type_vehicles, c = 1;
   string type_race[3]{"1.Гонка для наземного транспорта","2.Гонка для воздушного транспорта","3.Гонка для наземного и воздушного транспорта"};
   boots_vehicl boots_vehicl; camel_vehicl camel_vehicl; cent_vehicl cent_vehicl;
   fast_camel_vehicl fast_camel_vehicl;
   broomstick_vehicl broomstick_vehicl; eagle_vehicl eagle_vehicl; carpet_plane_vehicl carpet_plane_vehicl;
   int m_vehicles[9]{};
   race* race1[7];
   race check;

   do {
      cout << "Добро Пожаловать на симулятор гонок!\n" << type_race[0] << "\n" << type_race[1] << "\n" << type_race[2] << "\n";

      cout << "Выберите тип гонки: ";
      cin >> t_r;

      if (check.init_t_r(t_r))
      {
         cout << "Неверный выбор типа трассы!\n";
         continue;
      }

      cout << "\nУкажите длинну дистанции(должна быть положительна): ";
      cin >> clientdist;
  
      if (check.init_client_dist(clientdist))
      { cout << "Неверная дистанция!\n";
      continue;
      }

      cout << "\nНеобходимо зарегестрировать хотя бы 2 транспортных средства\n1.Зарегестрировать транспорт\nВыберите действие: ";
      cin >> n;

      int i = 0, j = 0, some=0;

      do {

         cout << type_race[n - 1] << ". " << "Расстояние: " << clientdist << "\n";

         cout << "1. Ботинки-вездеходы\n" << "2. Метла\n" << "3. Верблюд\n" << "4. Кентавр\n" << "5. Орёл\n" << "6. Верблюд - быстроход\n" << "7. Ковёр - самолёт\n"
            << "0. Закончить регистрацию\n" << "Выберете транспорт или 0 для завершения регистрации: ";
         cin >> type_vehicles;


         m_vehicles[i] = type_vehicles;
         j = i;
         if (i > 0) {
            for (; j > 0; --j) {
               if (m_vehicles[j - 1] == m_vehicles[i]) {
                  cout << "это тс уже зарегистрирован\n";
                  m_vehicles[i] = 0;
                  break;
               }
            }
         }


         if ((i == 0 && type_vehicles == 0) || (i == 1 && type_vehicles == 0)) {
            cout << "\nнужно зарегистрировать хотя бы два тс" << "\n\n";
            continue;
         }

         if (check.check_race(type_vehicles, t_r)) {
            cout << "\nне тот тип тс" << "\n\n";
            continue;
         }

         if (m_vehicles[i] != 0) {

            switch (type_vehicles) {
            case 1:  boots_vehicl.init(clientdist); race1[i]=&boots_vehicl; cout << "Ботинки-вездеходы зарегистрированы\n\n"; break;
            case 2:  broomstick_vehicl.init(clientdist); race1[i] = &broomstick_vehicl; cout << "Метла зарегистрирована\n\n"; break;
            case 3:  camel_vehicl.init(clientdist); race1[i] = &camel_vehicl; cout << "Верблюд зарегистрирован\n\n"; break;
            case 4:  cent_vehicl.init(clientdist); race1[i] = &cent_vehicl; cout << "Кентавр зарегистрирован\n\n"; break;
            case 5:  eagle_vehicl.init(clientdist); race1[i] = &eagle_vehicl; cout << "Орёл зарегистрирован\n\n"; break;
            case 6:  fast_camel_vehicl.init(clientdist); race1[i] = &fast_camel_vehicl; cout << "Верблюд-быстроход зарегистрирован\n\n"; break;
            case 7:  carpet_plane_vehicl.init(clientdist); race1[i] = &carpet_plane_vehicl; cout << "Ковёр-самолёт зарегистрирован\n\n"; break;
            default: break;
            }

            ++i;
         }
         if (type_vehicles == 0) {
            cout << "1. Зарегестрировать транспорт\n2.Начать гонку\nВыбрать действие: ";
            cin >> type_vehicles;
            if (type_vehicles == 2) {
               type_vehicles = 0;

            }
            break;
         }
      } while (type_vehicles || i < 2);

      race* race_bubble;

      for (int r = 0; r < i - 1; ++r) {
         int t = 0;
         for (int d = 1; d < i; ++d) {

            if (race1[d - 1]->get_finish_time() > race1[d]->get_finish_time()) {
               race_bubble = race1[d - 1];
               race1[d - 1] = race1[d];
               race1[d] = race_bubble;
            }
         }
      }

      cout << "Результат гонки: \n";
      for (int d = 1; d < i + 1; ++d) {
         cout << d << ". " << race1[d - 1]->get_name() << ": " << race1[d - 1]->get_finish_time() << "\n";
      }

      cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
      cin >> c;
   } while (c == 1);
}