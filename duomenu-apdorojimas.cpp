#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "includes/studentas.h"
#include "includes/randPazymys.cpp"
#include "includes/pazymiuIvedimas.cpp"
#include "includes/duomenysIsFailo.cpp"

int main() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  bool isFailo;
  double vidurkis = 0;
  double mediana;
  std::cout << "Ivesti duomenis - 0, skaityti is failo - 1: ";
  std::cin >> isFailo;
  if(!isFailo) {
    ivedimas();
  } else {
    duomenysIsFailo();
  }
  return 0;
}
