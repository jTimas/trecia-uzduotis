#include "includes/studentas.h"

int main() {
//  Zmogus z("Test", "Test");
//  std::cout << z.vardas();
  for(int i = 10; i <= 100000; i *= 10)
  {
    Generuoti(i);
    pirmaStrategija(std::to_string(i));
    antraStrategija(std::to_string(i));
    stablePartition(std::to_string(i));
  }
  return 0;
}
