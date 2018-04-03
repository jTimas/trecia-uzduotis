#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>
#include <list>
#include "includes/studentas.h"
#include "includes/studentasIsFailo.h"
#include "includes/randPazymys.cpp"
#include "includes/pazymiuIvedimas.cpp"
#include "includes/failuGeneravimas.cpp"
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
	Generuoti(10);
	Generuoti(100);
	Generuoti(1000);
	Generuoti(10000);
	Generuoti(100000);
    duomenysIsFailoVector();
    duomenysIsFailoList();
    duomenysIsFailoDeque();
  }
  return 0;
}
