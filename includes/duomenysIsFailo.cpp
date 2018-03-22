bool pagalVarda(const StudentasF& x, const StudentasF& y) { return x.vardas < y.vardas; }
bool jeiVargsiukas(const StudentasF& item) { return item.vidurkis < 6; }
// Vektoriai
void duomenysIsFailoVector() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Vector] Time taken: " << elapsed.count() << " s\n";
}

void duomenysIsFailoVector1Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::vector<StudentasF> studentai;
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
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(studentai.begin(), studentai.end(), pagalVarda);
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Vector 1 Strategija] Time taken: " << elapsed.count() << " s\n";
}

void duomenysIsFailoVector2Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::vector<StudentasF> studentai;
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
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(studentai.begin(), studentai.end(), pagalVarda);
      std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), jeiVargsiukas);
      studentai.erase( remove_if(studentai.begin(), studentai.end(), jeiVargsiukas), studentai.end() );
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: studentai)
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Vector 2 Strategija] Time taken: " << elapsed.count() << " s\n";
}
// -----------------------------------------------------------------
void duomenysIsFailoList() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[List] Time taken: " << elapsed.count() << " s\n";
}
void duomenysIsFailoList1Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::list<StudentasF> studentai;
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
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      //std::sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
      studentai.sort(pagalVarda);
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[List 1 strategija] Time taken: " << elapsed.count() << " s\n";
}
void duomenysIsFailoList2Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::list<StudentasF> vargsiukai;
      std::list<StudentasF> studentai;
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
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      //std::sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
      studentai.sort(pagalVarda);
      vargsiukai.sort(pagalVarda);
      copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), jeiVargsiukas);
      studentai.erase( remove_if(studentai.begin(), studentai.end(), jeiVargsiukas), studentai.end() );
      //std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: studentai)
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[List 2 strategija] Time taken: " << elapsed.count() << " s\n";
}
void duomenysIsFailoDeque() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Deque] Time taken: " << elapsed.count() << " s\n";
}

void duomenysIsFailoDeque1Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::deque<StudentasF> studentai;
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
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        if(!kietiakas)
          vargsiukai.push_back({vardas, pavarde, vidurkis, mediana});
        else
          kietiakai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(studentai.begin(), studentai.end(), pagalVarda);
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Deque 1 Strategija] Time taken: " << elapsed.count() << " s\n";
}
void duomenysIsFailoDeque2Strategija() { // 0 - Vector, 1 - List, 2 - deque
  auto start = std::chrono::high_resolution_clock::now();
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
      std::deque<StudentasF> studentai;
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
        vidurkis = 0.4 * vidurkis + 0.6 * egz;
        mediana = 0.4 * mediana + 0.6 * egz;
        studentai.push_back({vardas, pavarde, vidurkis, mediana});
        namu_darbai.clear();
        vidurkis = 0;
      } while(!fin.eof());
      fin.close();
      std::sort(studentai.begin(), studentai.end(), pagalVarda);
      std::sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
      std::ofstream fout(std::to_string(file) + "-rezultatai.txt");
      copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), jeiVargsiukas);
      studentai.erase( remove_if(studentai.begin(), studentai.end(), jeiVargsiukas), studentai.end() );
      fout << "Kietiakai:" << std::endl;
      fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
      for(auto const& value: studentai)
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
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "[Deque 2 Strategija] Time taken: " << elapsed.count() << " s\n";
}
