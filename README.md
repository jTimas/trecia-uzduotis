# Duomenų apdorojimas

## Programos tikslas

**Programa skaičiuoja galutinį studento balą ir atspausdinami visi duomenys:**
- Vardas, Pavardė.
- Namų darbų ir egzamino rezultatai.
- Galutinis balas.
- Galimas pasirinkimas skaičiuojant galutinį balą pagal namų darbų pažymių vidurkį arba medianą.
- Galima įvesti namų darbų ir egzaminų rezultatus arba generuoti atsitiktinai.

## Versijų istorija

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

### [v0.1](https://github.com/jTimas/duomenu-apdorojimas/releases/tag/v0.1) - 2018-02-22

**Pridėta:**
- Pirminė versija.
- Išvedami studento duomenys (Vardas, Pavardė, pažymiai, egzamino rezultatas, galutinis rezultatas).
- Atsitiktinis generavimas.
- Medianos arba vidurkio skaičiavimas.

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
