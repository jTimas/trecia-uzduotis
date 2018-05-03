#include <algorithm>
#include "studentas.h"
#include "fileStreams.cpp"
#include "randPazymys.cpp"

void Studentas::setfName(std::string x) {
   vardas_ = x;
}

void Studentas::setlName(std::string x) {
   pavarde_ = x;
}

void Studentas::addND(double x) {
  nd_.push_back(x);
}

void Studentas::setEgz(double x) {
  egzaminas_ = x;
}

void Studentas::sortND() {
  std::sort(nd_.begin(), nd_.end());
}

void Studentas::vidurkis() {
  double sum = 0;
  for (auto &paz: nd_)
    sum += paz;
  vidurkis_ = (sum/nd_.size()) * 0.4 + 0.6 * this->egz();
}

void Studentas::mediana() {
  this->sortND();
  double mediana;
  if (nd_.size() % 2 == 0)
    mediana = (nd_[nd_.size() / 2] + nd_[(nd_.size()  / 2) - 1]) / 2.0;
  else
    mediana = nd_[(nd_.size() / 2)];
  mediana_ = mediana * 0.4 + 0.6 * this->egz();
}

std::ostream& operator<<(std::ostream& out, const Studentas& a) {
    out << std::left << std::setprecision(2) << std::fixed << std::setw(15) << a.pavarde_ << std::setw(15) << a.vardas_ << std::setw(20) << a.vidurkis_ << std::setw(20) << a.mediana_ << std::endl;
    return out;
}

bool operator< (Studentas& a, Studentas& b) { return a.vardas() < b.vardas(); }
bool jeiVargsiukas(Studentas& x) { return x.getVidurkis() < 6; }
