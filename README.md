# Tetris

## Klasy

* Playfield
* Tetromimoe
* Game
* Wyświetlanie

### Playfield
* macierz 10 x 20 + marginesy po bokach i na górze
* sprawdzanie, czy cały rząd jest zapełniony [rowFull()]
* sprawdzanie, czy nowy klocek jest we właściwym położeniu po wykonaniu ruchu, czyli nie koliduje ze ścianą lub z innymi klockami poprzez funkcję [correctPos()], która zwraca true lub false
    * mając koordynaty lewego górnego elementu macierzy nowego klocka, porównujemy wszystkie elementy nowego klocka z odpowiadającymi polami w grze, czy gdzieś jedynki się nie pokrywają

### Tetromimoe (blok)
* macierz 4 x 4
* tworzenie kształtów
* obracanie
    * transponowanie a potem obrócenie macierzy wzdłuż osi poziomej (obrót w lewo), albo pionowej (w prawo)
* zawiera koordynaty lewego górnego rogu względem planszy, żeby można było sprawdzać kolizje

### Wyświetlanie
* SFML

### Gra
* umieszczamy nowy element na marginesie
* patrzymy czy może spaść na planszę, jak nie to przegrana
* opuszczamy klocek na planszę
* uruchamiamy zegar
* gracz może obracać klocek albo go przesuwać na boki (wykonujemy działanie i wywołujemy funkcję correctPos())
    * jeżeli correctPos() zwróci false, to nie zatwierdzamy działania
* po upłynięciu czasu na zegarze opuszczamy klocek 1 poziom niżej i powtarzamy cały proces
    * opuszczenie klocka też musi zostać zweryfikowane przez funkcję correctPos(), natomiast teraz jeżeli correctPos() zwróci false, to znaczy że klocek spadł na inny lub na podłoże
* w przypadku wciśnięcia klawisza w dół, klocek zostaje opuszczony, a zegar resetowany
    * opuszczenie klocka weryfikowane jest tak samo jak poprzednio
* po umieszczeniu nowego klocka wywołujemy funkcję rowFull()