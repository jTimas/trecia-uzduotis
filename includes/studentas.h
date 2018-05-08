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
      /// Inicializuojamas studentas
      Studentas() : egzaminas_(0) { }
      /// Nustatomas studento vardas.
      void setfName(std::string);
      /// Nustatoma studento pavardė.
      void setlName(std::string);
      /// Priskiriamas egzamino pažymis
      void setEgz(double);
      /// Priskiriamas namų darbo pažymis
      void addND(double);
      /// Išrūšiuojami nuo žemiausio iki didžiausio namų darbų pažymio
      void sortND();
      /**
       Išskaičiuojamas ND galutinis balas pagal vidurkį.
       @returns galutinis = 0.4 * vidurkis + 0.6 * egzaminas
       */
      void vidurkis();
      /**
       Išskaičiuojamas ND galutinis balas pagal medianą.
       @returns galutinis = 0.4 * mediana + 0.6 * egzaminas
       */
      void mediana();
      /**
        Gražinami studento pažymiai
        @returns vector<double> nd_
        */
      inline std::vector<double> nd() const { return nd_; }
      /**
        Gražinamas egzamino pažymis
        @returns double egzaminas_
        */
      inline double egz() const { return egzaminas_; }
      /**
        Gražinamas jau išskaičiuotas vidurkis (naudojama bool jeiVargsiukas())
        @returns double vidurkis_
        */
      inline double getVidurkis() const { return vidurkis_; }
      /**
        Grąžina studento vardą
        @returns std::string vardas_
       */
      inline std::string vardas() const { return vardas_; }
      /**
        Grąžina studento pavardę
        @returns std::string pavarde_
       */
      inline std::string pavarde() const { return pavarde_; }
      /**
        Operatorius <<, naudojamas išspausdinti visą Studentas klasę.
       */
      friend std::ostream& operator<<(std::ostream&, const Studentas&);
      /**
        Tikrina ar studento vardas abėcėliškai žemiau kito
        @returns std::string pavarde_
       */
      bool operator< (const Studentas& b);
      /**
        Tikrina ar studento vardas abėcėliškai aukščiau kito
        @returns std::string pavarde_
       */
      bool operator> (const Studentas& b);
      /**
        Tikrina ar studento vardas ir pavardė sutampa
        @returns std::string pavarde_
       */
      bool operator== (const Studentas& b);
      /**
        Tikrina ar studento vardas ir pavardė nesutampa
        @returns std::string pavarde_
       */
      bool operator!= (const Studentas& b);
};
