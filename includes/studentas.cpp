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

double Studentas::vidurkis() {
  double sum = 0;
  for (auto &paz: nd_)
    sum += paz;
  return (sum/nd_.size()) * 0.4 + 0.6 * this->egz();
}

double Studentas::mediana() {
  this->sortND();
  double mediana;
  if (nd_.size() % 2 == 0)
    mediana = (nd_[nd_.size() / 2] + nd_[(nd_.size()  / 2) - 1]) / 2.0;
  else
    mediana = nd_[(nd_.size() / 2)];
  return mediana * 0.4 + 0.6 * this->egz();
}
