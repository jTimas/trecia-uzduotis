bool pagalVarda(const Studentas& x, const Studentas& y) { return x.vardas < y.vardas; }

void duomenysIsFailo() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  double vidurkis = 0;
  double mediana;
  std::ifstream fin;
  try {  // išimtys yra apdorojamos žemiau
    fin.open ("kursiokai.txst", std::ios::in | std::ios::binary);
    if( !fin ) throw std::ios::failure( "Error opening file!");
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
        mediana = (namu_darbai[namu_darbai.size() / 2] + namu_darbai[(namu_darbai.size()  / 2) - 1]) / 2.0;
      else
        mediana = namu_darbai[(namu_darbai.size() / 2)];
      vidurkis = (double) vidurkis / namu_darbai.size();
      stud.push_back({vardas, pavarde, vidurkis, mediana});
    } while(!fin.eof());
    fin.close();
    std::sort(stud.begin(), stud.end(), pagalVarda);
    for(auto const& value: stud) {
      std::cout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
    }
  } catch (const std::ifstream::failure &e) {
    std::cout << e.what() << std::endl;
  }
}
