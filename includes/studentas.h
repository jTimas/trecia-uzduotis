#include <iostream>
#include <vector>
#include <string>

class Studentas {
  private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    double vidurkis_;
    double mediana_;
    std::vector<double> nd_;
  public:
      Studentas() : egzaminas_(0) { }
      void setfName(std::string);
      void setlName(std::string);
      void setEgz(double);
      void addND(double);
      void sortND();
      void vidurkis();
      void mediana();
      inline std::vector<double> nd() const { return nd_; }
      inline double egz() const { return egzaminas_; }
      inline double getVidurkis() const { return vidurkis_; }
      inline std::string vardas() const { return vardas_; }
      inline std::string pavarde() const { return pavarde_; }
      friend std::ostream& operator<<(std::ostream&, const Studentas&);
};
