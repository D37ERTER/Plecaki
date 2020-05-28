#ifndef GRAFY_H
#define GRAFY_H

    #include <iostream> //konsola
    #include <fstream> //pliki
    #include <math.h> //potęgi
    #include <stdlib.h> //random
    #include <time.h>   //random
    #include <chrono> //czas
	#include <vector> //wektory

    using namespace std;

	typedef void (*tproc)();
	typedef void (*tproc1arg)(int v);
	typedef void (*tproc2arg)(int x, int y);
	typedef bool (*tbool)(int x, int y);

    //plecaki w pamięci
    extern int n; //ilosc elementow
    extern int b; //pojemnosc plecaka
    extern vector<short> r; //rozmiar elementow
    extern vector<short> w; //wartosc elementow

    //funkcje konsola
    int toInt(string s);
    string toString(int i);
    int zKonsoli(int minv, int maxv, string komunikat, string blad);
    int zKonsoli(string komunikat, string blad);

    //testy
	void test();

    //funckcje tworzenia grafow
    void utworzLosowo();
    void utworzZKonsoli();
    void utworzZPliku();

    //funkcje operacji na plecaku
    void wyswietlPlecak();
    void usunPlecak();

    //funkcje rozwiazan problemu plecakowego
    void APD();
    void AZ();
    void AW();

#endif
