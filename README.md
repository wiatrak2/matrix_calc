Kalkulator macierzy
=======================

Wojciech Pratkowiecki II UWr
Programowanie Obiektowe - semestr letni 2015/16

----------

Opis
-------------

Program jest kalkulatorem macierzy dowolnego typu (klasy są `template`) i rozmiaru. Dodatkowo zaiplementowale klasy **rational** oraz **imaginary** pozwalają na korzystanie z ułamków zwykłych i liczb zespolonych. Klasa **vector** jest implementacją wektora matematycznego wraz z najważniejszymi jego funkcjami. Dodatkowo klasa **equation_matrix** umożliwia rozwiązywanie układów równań za pomocą macierzy. Każda klasa posiada przeładowane w naturalnym znaczeniu operatory. Program został napisany w ramach projetku końcowego na przemiot Programowanie Obiektowe, semestr letni 2015/16, II UWr. Całość napisana jest w C++ standard C++ 11.

Sposób korzystania
----------------------------------

Program działa za pomocą terminala. W pliku `main.cpp` znajdują się przykłady deklaracji obiektów wszystkich klas. Najbardziej zalecane jest tworzenie macierzy typu `rational` lub `imaginary`. W katalogu znajduje się rówież plik `Makefile` który kompiluje cały program. Katalog można następnie oczyścić komendą `make clean` 

Problemy do implementacji
------------

- jednoznaczna implementacja ułamków zwykłych
- właściwe przeładowanie operatorów 
- poprawna Eliminacja Gaussa dla macierzy rozmiaru n x m
- poprawne zaimplementowanie rozwiązywania układu Cramera

Diagram Klas
------------

![class_diagram](https://github.com/wiatrak2/matrix_calc/blob/master/class_diagram.jpg?raw=true)

Diagram znajudje się także wśród plików programu.

Dokumentacja
-------
Dokumentacja projektu znajduje się w sekcji **wiki** repozytorium `[link](https://github.com/wiatrak2/matrix_calc/wiki)`.

--------
Wojciech Pratkowiecki
II UWr
