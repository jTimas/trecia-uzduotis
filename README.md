# Trečia užduotis (Duomenų apdorojimas OOP)

Palyginimas naudojas 2 užduoties `struct`'uras ir 3 užduoties `class`'es.

| Failo dydis (eilutėm) | Struct | Class  | Strategija   |
|-----------------------|--------|--------|--------------|
|10                     |0.00224s|0.00441s| 1 strategija |
|100                    |0.00452s|0.00833s| 1 strategija |
|1000                   |0.03539s|0.04545s| 1 strategija |
|10000                  |0.25717s|0.41783s| 1 strategija |
|100000                 |2.76347s|4.71138s| 1 strategija |
|10                     |0.00528s|0.00465s| 2 strategija |
|100                    |0.00743s|0.00769s| 2 strategija |
|1000                   |0.02960s|0.03613s| 2 strategija |
|10000                  |0.22618s|0.29985s| 2 strategija |
|100000                 |2.29404s|3.18264s| 2 strategija |

Išvada: 2 užduoties realizacija spartesnė naudojant `struct`'uras

# Duomenų apdorojimas (2 užduotis)

## Vertinimas

Trukumu nera.

Privalumai:

- Makefile
- Ir siaip kodo stilius unikalus bet geras.


## Naudojimosi instrukcija (Linux)

Atsidaryti terminale:
```
$ make
g++ -c -w duomenu-apdorojimas.cpp -o duomenu-apdorojimas.o
g++ duomenu-apdorojimas.o -o run
./run
Ivesti duomenis - 0, skaityti is failo - 1:
```

### Windows

Instaliuoti `make` Windows operacinėje sistemoje: http://gnuwin32.sourceforge.net/packages/make.htm

``` 
C:\...\>make
C:\...\>run.exe
Ivesti duomenis - 0, skaityti is failo - 1:
```

## Programos tikslas

**Programa skaičiuoja galutinį studento balą ir atspausdinami visi duomenys:**
- Vardas, Pavardė.
- Namų darbų ir egzamino rezultatai.
- Galutinis balas.
- Galimas pasirinkimas skaičiuojant galutinį balą pagal namų darbų pažymių vidurkį arba medianą.
- Galima įvesti namų darbų ir egzaminų rezultatus arba generuoti atsitiktinai.

## Versijų istorija

###  [v1.0](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v1.0.1) - 2018-03-26

**Pridėta:**
- 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) panaudojant du naujus konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: studentai ir (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu, tačiau kaip dėl spartos priklausomai nuo konteinerio tipo?

- 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerią: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į "vargšiukų" konteinerį ir ištrinti ir bendro studentai konteinerio. Tokiu būdu, studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.

Išmatuoti laikai

**Rezultatai:**

| Strategijos     | Vector | List  | Deque |
|:---------------:|:------:|:-----:|:-----:|
| Mano strategija | 2.34s  | 2.52s | 2.47s |
| 1 Strategija    | 3.02s  | 2.71s | 3.25s |
| 2 Strategija    | 2.43s  | 2.50s | 2.47s |

**Išvada:**
Greičiausiai programa veikia mano strategija naudojant `vector` konteinerį.

---

###  [v0.5](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.5) - 2018-03-13

**Pridėta:**
- Pridėti konteineriai: `list` ir `deque`.
- Programos veikimo laiko matavimas priklausomai nuo naudojamo konteinerio.

**Rezultatai:**

| Vector | List  | Deque |
|:------:|:-----:|:-----:|
| 2.42s  | 2.21s | 2.67s |

**Išvada:**
Greičiausiai programa veikia naudojant `list` konteinerį.

---

###  [v0.4](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.4) - 2018-03-13

**Pridėta:**
- Pridėtas failų generavimas su `10, 100, 1000, 10000, 100000` įrašais.
- Studentų rūšiavimas į dvi kategorijas (Vargšiukai < 5.0 galutinis balas, Kietiakai >= 5.0 galutinis balas).
- Laiko matavimas su visais keturiais failais.

---

###  [v0.3](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.3.1) - 2018-03-01

**Pridėta:**
- Pradėtos naudoti struktūros.
- Funkcijos perkeltos į `.cpp`.
- Struktūros ir duomenų tipai perkelti į headerius `.h`.
- Pradėtas naudotis išimčių valdymas (angl. *Exception Handling*)

---

### [v0.2](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.2) - 2018-02-27

**Pridėta:**
- Skaitymas iš failo.
- Outputas įrašomas į failą.
- Rūšiavimas pagal vardus ir pavardes.

**Kursiokai:**

| Pavarde    | Vardas     | ND1 | ND2 | ND3 | ND4 | ND5 | Egzaminas |
| ---------- | ---------- | --- | --- | --- | --- | --- | --------- |
| Makevicius | Augustinas | 8   | 9   | 10  | 6   | 10  | 9         |
| Pocius     | Paulius    | 7   | 10  | 8   | 5   | 4   | 6         |

**Rezultatai:**

| Pavarde    | Vardas     | Galutinis-vidurkis | Galutinis-mediana |
| ---------- | ---------- | ------------------ | ----------------- |
| Makevicius | Augustinas | 4                  | 8                 |
| Pocius     | Paulius    | 8                  | 10                |

---

### [v0.1](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.1) - 2018-02-22

**Pridėta:**
- Pirminė versija.
- Išvedami studento duomenys (Vardas, Pavardė, pažymiai, egzamino rezultatas, galutinis rezultatas).
- Atsitiktinis generavimas.
- Medianos arba vidurkio skaičiavimas.
- Dvi realizacijos naudojant `C` masyvus ir `vector` konteinerį.

```
Iveskite varda: Timas
Iveskite pavarde: Jackus
Pasirinkite pazymiu rezultatu ivedima (Ivesti pazymius - 0, Generuoti atsitiktinai - 1): 1
Iveskite pazymiu skaiciu n: 5
Pasirinkite skaiciavimo buda (Mediana - 0, Vidurkis - 1): 0
```

```
Studento Vardas Pavarde: Timas Jackus
Studento namu darbu pazymiai: 2 3 6 9 9
Egzamino rezultatai: 4
Galutinis balas: 4.80
```
