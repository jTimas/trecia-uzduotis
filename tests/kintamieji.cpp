#include "../lib/catch.hpp"
#include "../includes/studentas.h"


TEST_CASE( "Vardas & Pavardė" ) {
    Studentas stud("Timas", "Jackus");
    SECTION("Testas - Constructor") {
        SECTION("Testas 1") {
            REQUIRE((stud == Studentas("Timas", "Jackus")) == true);
        }
        SECTION("Testas 2") {
            stud = Studentas("Vardas2", "Jackus");
            REQUIRE((stud == Studentas("Vardas2", "Jackus")) == true);
        }
    }
    SECTION("Testas - seters: fName, lName") {
        SECTION("Testas 1") {
            stud.setfName("Vardas");
            stud.setlName("Pavardė");
            REQUIRE((stud == Studentas("Vardas", "Pavardė")) == true);
        }
        SECTION("Testas 2") {
            stud.setlName("Pavardė");
            REQUIRE((stud == Studentas("Timas", "Pavardė")) == true);
        }
    }
}