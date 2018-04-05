#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <deque>
#include <list>
#include "includes/studentas.h"
#include "includes/palyginimai.h"
#include "includes/randPazymys.cpp"
#include "includes/pazymiuIvedimas.cpp"
#include "includes/failuGeneravimas.cpp"
#include "includes/duomenysIsFailo.cpp"

int main() {
  bool isFailo;
  std::cout << "Ivesti duomenis - 0, skaityti is failo - 1: ";
  while(!(std::cin >> isFailo)){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "[KLAIDA!] Ivesti duomenis - 0, skaityti is failo - 1: ";
  }
  // std::cin >> isFailo;
  if(!isFailo) {
    ivedimas();
  } else {
	  Generuoti(10);
	  Generuoti(100);
	  Generuoti(1000);
	  Generuoti(10000);
	  Generuoti(100000);
    duomenysIsFailoVector();
    duomenysIsFailoVector1Strategija();
    duomenysIsFailoVector2Strategija();
    duomenysIsFailoList();
    duomenysIsFailoList1Strategija();
    duomenysIsFailoList2Strategija();
    duomenysIsFailoDeque();
    duomenysIsFailoDeque1Strategija();
    duomenysIsFailoDeque2Strategija();
  }
  return 0;
}
