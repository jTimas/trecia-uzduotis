#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int modernRand(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n);
    return dis(gen);
}

int main() {
  for(int i = 0; i < 15; i++)
    std::cout << modernRand(10) << std::endl;
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int n, egz, ivestis, ifRandom;
  double vidurkis = 0;
  double mediana;
  std::cout << "Iveskite Varda: ";
  std::cin >> vardas;
  std::cout << "Iveskite Pavarde: ";
  std::cin >> pavarde;
  std::cout << "Iveskite egzamino rezultata: ";
  std::cin >> egz;
  std::cout << "Iveskite pazymiu skaiciu (n): ";
  std::cin >> n;
  std::cout << "Pasirinkite pazymiu rezultatu ivedima (Ivesti pazymius - 0, Generuoti atsitiktinai - 1): ";
  std::cin >> ifRandom;
  if(ifRandom == 0) {
    for (int i = 0; i < n; i++) {
      int input;
      std::cin >> input;
      namu_darbai.push_back(input);
    }
  } else {
    for (int i = 0; i < n; i++)
      namu_darbai.push_back(modernRand(10));
  }
  std::cout << "Pasirinkite skaiciavimo buda (Mediana - 0, Vidurkis - 1): ";
  std::cin >> ivestis;
  std::cout << "Studento Vardas Pavarde: " << vardas << " " << pavarde << std::endl;
  std::sort(namu_darbai.begin(), namu_darbai.end());
  std::cout << "Studento namu darbu pazymiai: ";
  for(auto const& value: namu_darbai) {
      std::cout << value << " ";
      vidurkis += value;
  }
  std::cout << std::endl;
  if (namu_darbai.size() % 2 == 0)
    mediana = (namu_darbai[namu_darbai.size() / 2] + namu_darbai[(namu_darbai.size() / 2) - 1]) / 2.0;
  else
    mediana = namu_darbai[(namu_darbai.size() / 2)];
  vidurkis = (double) vidurkis / n;
  std::cout << "Egzamino rezultatai: " << egz << std::endl;
  std::cout << std::setprecision(2) << std::fixed << "Galutinis balas: " << 0.4 * (ivestis == 0 ? mediana : vidurkis) + 0.6 * egz << std::endl;
  return 0;
}
