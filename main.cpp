#include "headers.h"

//plecaki w pamieci
int n = 0; //ilosc elementow
int b = 0; //pojemnosc plecaka
vector<short> r; //rozmiar elementow
vector<short> w; //wartosc elementow

int main()
{
    srand(time(NULL));
    cout << "Witaj w PRAWIE najlepszym programie do pakowania rzeczy do plecakow. (v 0.1.2)"<< endl;
    int opcjaI;
    bool zamykanie = false;

    while(!zamykanie)
    {
        cout << endl;
        if(n)
        {
            cout << "Problem plecakowy w pamieci." << endl;
            cout << "ilosc elementow: \t"<< n << endl;
            cout << "pojemnosc plecaka: \t"<< b << endl;
        }
        else
            cout << "Brak problemu plecakowego w pamieci." << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1 - Utworz problem plecakowy z liczb losowych" << endl;
        cout << "2 - Utworz problem plecakowy z danych wpisanych w konsoli" << endl;
        cout << "3 - Utworz problem plecakowy z pliku" << endl;
        if(n)
        {
            cout << "4 - Wyswietl elementy mozliwe do spakowania" << endl;
            cout << "5 - Szukaj rozwiazania - APD - algorytm programowania dynamicznego" << endl;
            cout << "6 - Szukaj rozwiazania - AZ - algorytm zachlanny" << endl;
            cout << "7 - Szukaj rozwiazania - AW - algorytm wyczerpujacy" << endl;
            cout << "8 - Zamknij program" << endl;
        }
        else
        {
            cout << "4 - Zamknij program" << endl;
        }

        cout << endl;
        opcjaI = zKonsoli(1, n?8:4, ":","Bledne polecenie.");

        switch(opcjaI)
        {
        case 1:
            utworzLosowo();
            break;
        case 2:
            utworzZKonsoli();
            break;
        case 3:
            utworzZPliku();
            break;
        case 4:
            if(!n)
            {
                usunPlecak();
                cout << "Konczenie pracy programu" << endl;
                zamykanie = true;
            }
            else
                wyswietlPlecak();
            break;
        case 5:
            APD();
            break;
        case 6:
            AZ();
            break;
        case 7:
            AW();
            break;
        case 8:
        	usunPlecak();
            cout << "Konczenie pracy programu" << endl;
            zamykanie = true;
            break;
        }
    }
    return 0;
}
