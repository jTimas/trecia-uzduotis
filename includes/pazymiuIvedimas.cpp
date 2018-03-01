void ivedimas() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz, ivestis, ifRandom;
  double vidurkis = 0;
  double mediana;
  Studentas student;
  std::cout << "Iveskite Varda: ";
  std::cin >> student.vardas;
  std::cout << "Iveskite Pavarde: ";
  std::cin >> student.pavarde;
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
  std::cout << "Studento Vardas Pavarde: " << student.vardas << " " << pavarde << std::endl;
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
}
