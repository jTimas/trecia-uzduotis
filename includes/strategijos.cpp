#include <chrono>

void pirmaStrategija (std::string file) {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Studentas> stud;
  std::vector<Studentas> vargsiukai;
  std::vector<Studentas> kietiakai;
  readFromFile(stud, file + ".txt");
  for(auto &item: stud) {
    if(item.getVidurkis() < 6) vargsiukai.push_back(item);
    else kietiakai.push_back(item);
  }
  std::sort(stud.begin(), stud.end());
  std::sort(vargsiukai.begin(), vargsiukai.end());
  std::sort(kietiakai.begin(), kietiakai.end());
  printToFile(kietiakai, vargsiukai, file + "-rezultatai.txt");
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Duomenu kiekis: " << std::setw(6) << file << " [Vector 1 strategija] Time taken: " << elapsed.count() << " s\n";
  stud.clear();
}

void antraStrategija (std::string file) {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Studentas> stud;
  std::vector<Studentas> vargsiukai;
  readFromFile(stud, file + ".txt");
  std::sort(stud.begin(), stud.end());
  std::sort(vargsiukai.begin(), vargsiukai.end());
  copy_if(stud.begin(), stud.end(), back_inserter(vargsiukai), jeiVargsiukas);
  stud.erase(remove_if(stud.begin(), stud.end(), jeiVargsiukas), stud.end());
  printToFile(stud, vargsiukai, file + "-rezultatai.txt");
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Duomenu kiekis: " << std::setw(6) << file << " [Vector 2 strategija] Time taken: " << elapsed.count() << " s\n";
  stud.clear();
}
