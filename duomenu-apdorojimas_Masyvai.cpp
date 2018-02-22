#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int randPazymys();

int main() {
  std::string vardas, pavarde;
  int n, egz, ivestis, ifRandom;
  double vidurkis = 0;
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
  }
  std::cout << "Iveskite pazymiu skaiciu (n): ";
  std::cin >> n;
  int *namu_darbai = new int [n];
  if(ifRandom == 0) {
    for (int i = 0; i < n; i++) {
      std::cin >> namu_darbai[i];
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
