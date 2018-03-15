bool pagalVarda(const StudentasF& x, const StudentasF& y) { return x.vardas < y.vardas; }

void duomenysIsFailoVector() { // 0 - Vector, 1 - List, 2 - deque
  clock_t tStart = clock();
  std::vector<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  double vidurkis = 0;
  double mediana;
  int file = 10;
  std::ifstream fin;
  for(int i = 0; i < 5; i++)
  {
    // Generuoti(file);
    try {  // išimtys yra apdorojamos žemiau
      fin.open (std::to_string(file) + ".txt", std::ios::in | std::ios::binary);
      if( !fin ) throw std::ios::failure( "Error opening file!");
      int input;
      std::vector<StudentasF> kietiakai;
      std::vector<StudentasF> vargsiukai;
      getline(fin, pavarde);
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
        bool kietiakas = true;
        if(vidurkis < 6) kietiakas = false;
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
      std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: kietiakai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout << "Vargsiukai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: vargsiukai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout.close();
    } catch (const std::ifstream::failure &e) {
      std::cout << e.what() << std::endl;
    }
    file *= 10;
  }
  printf("[Vector] Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

void duomenysIsFailoList() { // 0 - Vector, 1 - List, 2 - deque
  clock_t tStart = clock();
  std::list<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  double vidurkis = 0;
  double mediana;
  int file = 10;
  std::ifstream fin;
  for(int i = 0; i < 5; i++)
  {
    // Generuoti(file);
    try {  // išimtys yra apdorojamos žemiau
      fin.open (std::to_string(file) + ".txt", std::ios::in | std::ios::binary);
      if( !fin ) throw std::ios::failure( "Error opening file!");
      int input;
      std::list<StudentasF> kietiakai;
      std::list<StudentasF> vargsiukai;
      getline(fin, pavarde);
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
        //std::sort(namu_darbai.begin(), namu_darbai.end());
        namu_darbai.sort();
        std::list<int>::iterator it = namu_darbai.begin();
	      std::advance(it, namu_darbai.size() / 2);
        if (namu_darbai.size() % 2 == 0) {
          mediana = (*it + (*it - 1)) / 2.0;
        } else {
          mediana = *it;
        }
        vidurkis = (double) vidurkis / namu_darbai.size();
        bool kietiakas = true;
        if(vidurkis < 6) kietiakas = false;
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      //std::sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
      kietiakai.sort(pagalVarda);
      vargsiukai.sort(pagalVarda);
      //std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: kietiakai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout << "Vargsiukai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: vargsiukai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout.close();
    } catch (const std::ifstream::failure &e) {
      std::cout << e.what() << std::endl;
    }
    file *= 10;
  }
  printf("[List] Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}


void duomenysIsFailoDeque() { // 0 - Vector, 1 - List, 2 - deque
  clock_t tStart = clock();
  std::deque<int> namu_darbai;
  std::string vardas, pavarde;
  int egz;
  double vidurkis = 0;
  double mediana;
  int file = 10;
  std::ifstream fin;
  for(int i = 0; i < 5; i++)
  {
    // Generuoti(file);
    try {  // išimtys yra apdorojamos žemiau
      fin.open (std::to_string(file) + ".txt", std::ios::in | std::ios::binary);
      if( !fin ) throw std::ios::failure( "Error opening file!");
      int input;
      std::deque<StudentasF> kietiakai;
      std::deque<StudentasF> vargsiukai;
      getline(fin, pavarde);
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
        bool kietiakas = true;
        if(vidurkis < 6) kietiakas = false;
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
      std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: kietiakai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout << "Vargsiukai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: vargsiukai)
        fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde << std::setw(15) << value.vardas << std::setw(20) << value.vidurkis << std::setw(20) << value.mediana << std::endl;
      fout.close();
    } catch (const std::ifstream::failure &e) {
      std::cout << e.what() << std::endl;
    }
    file *= 10;
  }
  printf("[Deque] Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
