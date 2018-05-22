#define CATCH_CONFIG_MAIN

#include "../lib/catch.hpp"
#include "../includes/studentas.h"


TEST_CASE( "Galutinio balo testai" ) {
    Studentas stud({10, 10, 9, 8, 8});
    stud.setEgz(10);

    SECTION("Vidurkio galutinio balo testas") {
        SECTION("Testas 1") {
            stud.vidurkis();
            REQUIRE(stud.getVidurkis() == 9.6);
        }
        SECTION("Testas 2") {
            stud.addND(3);
            stud.setEgz(5);
            stud.vidurkis();
            REQUIRE(stud.getVidurkis() == 6.2);
        }
    }

    SECTION("Medianos galutinio balo testas") {
        SECTION("Testas 1") {
            stud.mediana();
            REQUIRE(stud.getMediana() == 9.6);
        }
        SECTION("Testas 2") {
            stud.addND(3);
            stud.setEgz(5);
            stud.mediana();
            REQUIRE(stud.getMediana() == 6.4);
        }
    }
}