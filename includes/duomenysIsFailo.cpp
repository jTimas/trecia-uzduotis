bool pagalVarda(const StudentasF& x, const StudentasF& y) { return x.vardas < y.vardas; }

void duomenysIsFailo() {
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  double vidurkis = 0;
  double mediana;
  std::ifstream fin;
  try {  // išimtys yra apdorojamos žemiau
    fin.open ("kursiokai.txt", std::ios::in | std::ios::binary);
    if( !fin ) throw std::ios::failure( "Error opening file!");
    int input;
    std::vector<StudentasF> stud;
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
      std::sort(namu_darbai.begin(), namu_darbai.end());
      if (namu_darbai.size() % 2 == 0)
        mediana = (namu_darbai[namu_darbai.size() / 2] + namu_darbai[(namu_darbai.size()  / 2) - 1]) / 2.0;
      else
        mediana = namu_darbai[(namu_darbai.size() / 2)];
      vidurkis = (double) vidurkis / namu_darbai.size();
      vidurkis = 0.4 * vidurkis + 0.6 * egz;
      mediana = 0.4 * mediana + 0.6 * egz;
      stud.push_back({vardas, pavarde, vidurkis, mediana});
      namu_darbai.clear();
      vidurkis = 0;
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
