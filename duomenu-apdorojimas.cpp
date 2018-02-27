#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
int randPazymys();

struct Studentas {
  std::string vardas, pavarde;
  int vidurkis, mediana;
};

bool is_younger(const Studentas& x, const Studentas& y) { return x.vardas < y.vardas; }
int main() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz, ivestis, ifRandom;
  bool isFailo;
  double vidurkis = 0;
  double mediana;
  std::cout << "Ivesti duomenis - 0, skaityti is failo - 1: ";
  std::cin >> isFailo;
  if(!isFailo) {
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
    if(ifRandom == 0) {
      std::cout << "Iveskite pazymius, jei norite nutraukti ivedima irasykite -1: ";
      int input;
      while (std::cin >> input) {
        if(input < 0) break;
        namu_darbai.push_back(input);
      }
    }
    else {
      int n;
      std::cout << "Iveskite pazymiu skaiciu n: ";
      std::cin >> n;
      for (int i = 0; i < n; i++)
        namu_darbai.push_back(randPazymys());
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
    vidurkis = (double) vidurkis / namu_darbai.size();
    std::cout << "Egzamino rezultatai: " << egz << std::endl;
    std::cout << std::setprecision(2) << std::fixed << "Galutinis balas: " << 0.4 * (ivestis == 0 ? mediana : vidurkis) + 0.6 * egz << std::endl;
  } else {
    std::ifstream fin ("kursiokai.txt");
    int input;
    std::vector<Studentas> stud;
    getline(fin, pavarde);
    std::cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
    do {
      fin >> pavarde;
      if(fin.eof()) break;
      fin >> vardas;
      for (int i = 0; i < 5; i++)
      {
        fin >> input;
        namu_darbai.push_back(input);
        vidurkis += input;
      }
      fin >> egz;
      if (namu_darbai.size() % 2 == 0)
        mediana = (namu_darbai[namu_darbai.size() / 2] + namu_darbai[(namu_darbai.size() / 2) - 1]) / 2.0;
      else
        mediana = namu_darbai[(namu_darbai.size() / 2)];
      vidurkis = (double) vidurkis / namu_darbai.size();
      stud.push_back({vardas, pavarde, vidurkis, mediana});
    } while(!fin.eof());
    fin.close();
    std::sort(stud.begin(), stud.end(), is_younger);
    for(auto const& value: stud) {
      std::cout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl; 
    }
  }
  return 0;
}

int randPazymys() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}
