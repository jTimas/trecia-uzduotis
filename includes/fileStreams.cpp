#include <fstream>
#include <iomanip>

void readFromFile(std::vector<Studentas> &stud, std::string file) {
  std::ifstream fin;
  try {
    std::string input;
    fin.open (file, std::ios::in | std::ios::binary);
    if( !fin ) throw std::ios::failure( "Error opening file!");
    getline(fin, input);
    while(fin >> input) {
      Studentas placeholder;
      double paz;
      placeholder.setlName(input);
      fin >> input;
      placeholder.setfName(input);
      for(int i = 0; i < 5; i++) {
        fin >> paz;
        placeholder.addND(paz);
      }
      fin >> paz;
      placeholder.setEgz(paz);
      stud.push_back(placeholder);
    }
  } catch (const std::ifstream::failure &e) {
    std::cout << e.what() << std::endl;
  }
  fin.close();
}

void printToFile(std::vector<Studentas> &kietiakai, std::vector<Studentas> &vargsiukai, std::string file) {
  std::ofstream fout(file);
  fout << "Kietiakai:" << std::endl;
  fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
  for(auto &value: kietiakai)
    fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde() << std::setw(15) << value.vardas() << std::setw(20) << value.vidurkis() << std::setw(20) << value.mediana() << std::endl;
  fout << "Vargsiukai:" << std::endl;
  fout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis-vidurkis" << std::setw(20) << "Galutinis-mediana" << std::endl;
  for(auto &value: vargsiukai)
    fout << std::left << std::setprecision(2) << std::fixed << std::setw(15) << value.pavarde() << std::setw(15) << value.vardas() << std::setw(20) << value.vidurkis() << std::setw(20) << value.mediana() << std::endl;
  fout.close();
}
