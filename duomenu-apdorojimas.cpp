#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int n, egz, suma = 0;
  std::cout << "Iveskite Varda: ";
  std::cin >> vardas;
  std::cout << "Iveskite Pavarde: ";
  std::cin >> pavarde;
  std::cout << "Iveskite egzamino rezultata: ";
  std::cin >> egz;
  std::cout << "Iveskite pazymiu skaiciu (n): ";
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    namu_darbai.push_back(input);
  }
  std::cout << "Studento Vardas Pavarde: " << vardas << " " << pavarde << std::endl;
  std::cout << "Studento namu darbu pazymiai: ";
  for(auto const& value: namu_darbai) {
      std::cout << value << " ";
      suma += value;
  }
  std::cout << std::endl;
  std::cout << "Egzamino rezultatai: " << egz << std::endl;
  std::cout << std::setprecision(2) << std::fixed << "Galutinis balas: " << 0.4 * suma/n + 0.6 * egz << std::endl;
  return 0;
}
