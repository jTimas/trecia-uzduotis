#include <iostream>
#include <vector>
#include <string>

class Zmogus {
    protected:
        std::string vardas_;
        std::string pavarde_;
    public:
        Zmogus() {}

        Zmogus(std::string fName, std::string lName) : vardas_{fName}, pavarde_{lName} {}

        virtual void setfName(std::string) = 0;
        virtual void setlName(std::string) = 0;

        virtual inline std::string vardas() = 0;
        virtual inline std::string pavarde() = 0;
};

class Studentas : public Zmogus {
private:
    double egzaminas_;
    double vidurkis_;
    double mediana_;
    std::vector<double> nd_;
public:
    /// Inicializuojamas studentas
    Studentas() : egzaminas_(0) { }
    Studentas (std::vector<int> namu_darbai) { nd_.assign(namu_darbai.begin(), namu_darbai.end()); }
    Studentas (const std::string &fName, const std::string &lName) : Zmogus{fName, lName} { }

    /// Nustatomas studento vardas.
    void setfName(std::string);
    /// Nustatoma studento pavardė.
    void setlName(std::string);
    /**
      Grąžina studento vardą
      @returns std::string vardas_
     */
    inline std::string vardas() { return vardas_; };
    /**
      Grąžina studento pavardę
      @returns std::string pavarde_
     */
    inline std::string pavarde() { return pavarde_; };
    /// Priskiriamas egzamino pažymis
    void setEgz(double);
    /// Priskiriamas namų darbų pažymiai
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
      Gražinama jau išskaičiuota mediana
      @returns double mediana_
      */
    inline double getMediana() const { return mediana_; }
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

// Funkcijų deklaracijos
bool jeiVargsiukas(Studentas&);
void Generuoti (int n);
void readFromFile(std::vector<Studentas>&, std::string);
void printToFile(std::vector<Studentas>&, std::vector<Studentas> &, std::string);
void printToFile(std::vector<Studentas>&, std::vector<Studentas>::iterator, std::string);
void pirmaStrategija(std::string);
void antraStrategija(std::string);
void stablePartition(std::string);
int randPazymys();