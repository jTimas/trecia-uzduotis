#include <iostream>
#include <vector>
#include <string>

class Studentas {
  private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> nd_;
  public:
      Studentas() : egzaminas_(0) { }
      void readFile(std::string file);
      void setfName(std::string);
      void setlName(std::string);
      void setEgz(double);
      void addND(double);
      void sortND();
      double vidurkis();
      double mediana();
      inline std::vector<double> nd() const { return nd_; }
      inline double egz() const { return egzaminas_; }
      inline std::string vardas() const { return vardas_; }
      inline std::string pavarde() const { return pavarde_; }
};

bool pagalVarda(const Studentas& x, const Studentas& y) { return x.vardas() < y.vardas(); }
bool jeiVargsiukas(Studentas& x) { return x.vidurkis() < 6; }
