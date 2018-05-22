# Trečia užduotis (Duomenų apdorojimas OOP)

###  [v1.0](https://github.com/jTimas/trecia-uzduotis/releases/tag/v1.0) - 2018-05-22

- Realizuoti **Unit Testai** naudojant `Catch` framework'ą

###  [v0.2](https://github.com/jTimas/trecia-uzduotis/releases/tag/v0.2) - 2018-05-08

- Pridėta dokumentacija
- Pradėta naudoti `stable_partition`
- Sukurti operatoriai

###  [v0.1](https://github.com/jTimas/trecia-uzduotis/releases/tag/v0.1) - 2018-04-19

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

Išvada: 2 užduoties realizacija spartesnė naudojant `struct`'uras.

Programos optimizavimas naudojant `compiler`'io flagus `O1, O2, O3`.

Nenaudojant flagų:
```
Duomenu kiekis:     10 [Vector 1 strategija] Time taken: 0.00454728 s
Duomenu kiekis:     10 [Vector 2 strategija] Time taken: 0.00437825 s
Duomenu kiekis:    100 [Vector 1 strategija] Time taken: 0.00926563 s
Duomenu kiekis:    100 [Vector 2 strategija] Time taken: 0.00914091 s
Duomenu kiekis:   1000 [Vector 1 strategija] Time taken: 0.0564237 s
Duomenu kiekis:   1000 [Vector 2 strategija] Time taken: 0.04338 s
Duomenu kiekis:  10000 [Vector 1 strategija] Time taken: 0.435484 s
Duomenu kiekis:  10000 [Vector 2 strategija] Time taken: 0.319743 s
Duomenu kiekis: 100000 [Vector 1 strategija] Time taken: 4.46007 s
Duomenu kiekis: 100000 [Vector 2 strategija] Time taken: 3.04483 s
```

Naudojant **O1** flagą:
```
Duomenu kiekis:     10 [Vector 1 strategija] Time taken: 0.0043364 s
Duomenu kiekis:     10 [Vector 2 strategija] Time taken: 0.00426584 s
Duomenu kiekis:    100 [Vector 1 strategija] Time taken: 0.00610543 s
Duomenu kiekis:    100 [Vector 2 strategija] Time taken: 0.00580676 s
Duomenu kiekis:   1000 [Vector 1 strategija] Time taken: 0.0226937 s
Duomenu kiekis:   1000 [Vector 2 strategija] Time taken: 0.0194662 s
Duomenu kiekis:  10000 [Vector 1 strategija] Time taken: 0.14449 s
Duomenu kiekis:  10000 [Vector 2 strategija] Time taken: 0.106678 s
Duomenu kiekis: 100000 [Vector 1 strategija] Time taken: 1.44838 s
Duomenu kiekis: 100000 [Vector 2 strategija] Time taken: 1.0626 s
```

Naudojant **O2** flagą:
```
Duomenu kiekis:     10 [Vector 1 strategija] Time taken: 0.0047762 s
Duomenu kiekis:     10 [Vector 2 strategija] Time taken: 0.00435856 s
Duomenu kiekis:    100 [Vector 1 strategija] Time taken: 0.00694933 s
Duomenu kiekis:    100 [Vector 2 strategija] Time taken: 0.00635897 s
Duomenu kiekis:   1000 [Vector 1 strategija] Time taken: 0.0217883 s
Duomenu kiekis:   1000 [Vector 2 strategija] Time taken: 0.0184504 s
Duomenu kiekis:  10000 [Vector 1 strategija] Time taken: 0.14415 s
Duomenu kiekis:  10000 [Vector 2 strategija] Time taken: 0.104735 s
Duomenu kiekis: 100000 [Vector 1 strategija] Time taken: 1.32419 s
Duomenu kiekis: 100000 [Vector 2 strategija] Time taken: 0.967827 s
```

Naudojant **Os** flagą:
```
Duomenu kiekis:     10 [Vector 1 strategija] Time taken: 0.00502851 s
Duomenu kiekis:     10 [Vector 2 strategija] Time taken: 0.00433558 s
Duomenu kiekis:    100 [Vector 1 strategija] Time taken: 0.00773948 s
Duomenu kiekis:    100 [Vector 2 strategija] Time taken: 0.00614522 s
Duomenu kiekis:   1000 [Vector 1 strategija] Time taken: 0.0265719 s
Duomenu kiekis:   1000 [Vector 2 strategija] Time taken: 0.024272 s
Duomenu kiekis:  10000 [Vector 1 strategija] Time taken: 0.146088 s
Duomenu kiekis:  10000 [Vector 2 strategija] Time taken: 0.109121 s
Duomenu kiekis: 100000 [Vector 1 strategija] Time taken: 1.45664 s
Duomenu kiekis: 100000 [Vector 2 strategija] Time taken: 1.05429 s
```

Naudojant **Ofast** flagą:
```
Duomenu kiekis:     10 [Vector 1 strategija] Time taken: 0.00457681 s
Duomenu kiekis:     10 [Vector 2 strategija] Time taken: 0.0043602 s
Duomenu kiekis:    100 [Vector 1 strategija] Time taken: 0.00666215 s
Duomenu kiekis:    100 [Vector 2 strategija] Time taken: 0.00575466 s
Duomenu kiekis:   1000 [Vector 1 strategija] Time taken: 0.0182588 s
Duomenu kiekis:   1000 [Vector 2 strategija] Time taken: 0.0162482 s
Duomenu kiekis:  10000 [Vector 1 strategija] Time taken: 0.131812 s
Duomenu kiekis:  10000 [Vector 2 strategija] Time taken: 0.09975 s
Duomenu kiekis: 100000 [Vector 1 strategija] Time taken: 1.29809 s
Duomenu kiekis: 100000 [Vector 2 strategija] Time taken: 0.986262 s
```

# Duomenų apdorojimas (2 užduotis)

[Antros užduoties repozitorija](https://github.com/jTimas/duomenu-apdorojimas)