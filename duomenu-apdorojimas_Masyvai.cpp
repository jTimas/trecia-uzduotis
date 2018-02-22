#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int randPazymys();

int main() {
  std::string vardas, pavarde;
  int egz, ivestis, ifRandom;
  double vidurkis = 0;
  int n = 0;
  double mediana;
  std::cout << "Iveskite Varda: ";
  std::cin >> vardas;
  std::cout << "Iveskite Pavarde: ";
  std::cin >> pavarde;
  std::cout << "Pasirinkite pazymiu rezultatu ivedima (Ivesti pazymius - 0, Generuoti atsitiktinai - 1): ";
  std::cin >> ifRandom;
  if(ifRandom == 0) {
    std::cout << "Iveskite egzamino rezultata: ";
    std::cin >> egz;
  } else {
    egz = randPazymys();
    std::cout << "Iveskite pazymiu skaiciu (n): ";
    std::cin >> n;
  }
  int capacity = 1;
  int *namu_darbai = new int [capacity];
  if(ifRandom == 0) {
    int input;
    std::cout << "Iveskite pazymius, jei norite nutraukti iveskite -1: ";
    while (std::cin >> input) {
      if (input < 0) break;
      if(capacity > n) {
        namu_darbai[n] = input;
      }
      else {
        capacity *= n;
        auto *placeholder = new int[capacity];
        for (int i = 0; i < n; i++)
          placeholder[i] = namu_darbai[i];
        namu_darbai = placeholder;
        namu_darbai[n] = input;
      }
      n++;
    }
  } else {
  for (int i = 0; i < n; i++)
      namu_darbai[i] = randPazymys();
  }
  std::cout << "Pasirinkite skaiciavimo buda (Mediana - 0, Vidurkis - 1): ";
  std::cin >> ivestis;
  std::cout << "Studento Vardas Pavarde: " << vardas << " " << pavarde << std::endl;
  std::sort(namu_darbai, namu_darbai + n);
  std::cout << "Studento namu darbu pazymiai: ";
  for(int i = 0; i < n; i++) {
      std::cout << namu_darbai[i] << " ";
      vidurkis += namu_darbai[i];
  }
  std::cout << std::endl;
  if (n % 2 == 0)
    mediana = (namu_darbai[n / 2] + namu_darbai[(n / 2) - 1]) / 2.0;
  else
    mediana = namu_darbai[(n / 2)];
  vidurkis = (double) vidurkis / n;
  std::cout << "Egzamino rezultatai: " << egz << std::endl;
  std::cout << std::setprecision(2) << std::fixed << "Galutinis balas: " << 0.4 * (ivestis == 0 ? mediana : vidurkis) + 0.6 * egz << std::endl;
  return 0;
}

int randPazymys() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}
