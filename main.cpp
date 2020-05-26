#include "headers.h"

//plecaki w pamieci
int n; //ilosc elementow
int b; //pojemnosc plecaka
vector<short> r; //rozmiar elementow
vector<short> w; //wartosc elementow

int main()
{
    srand(time(NULL));
    cout << "Witaj w PRAWIE najlepszym programie do pakowania rzeczy do plecakow. (v 0.0.1)"<< endl;
    int opcjaI;
    bool zamykanie = false;

    while(!zamykanie)
    {
        cout << endl;
        if(n)
            cout << "Problem plecakowy w pamieci." << endl;
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
            cout << "6 - Szukaj rozwiazania - AZ - algorytm zachłanny" << endl;
            cout << "7 - Szukaj rozwiazania - AW - algorytm wyczerpujący" << endl;
            cout << "8 - Zamknij program" << endl;
        }
        else
        {
            cout << "4 - Zamknij program" << endl;
        }

        cout << endl;
        opcjaI = zKonsoli(1, n?8:4, "","Bledne polecenie.");

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
                // TODO usuwanie
                cout << "Konczenie pracy programu" << endl;
                zamykanie = true;
            }
            else
                ; // TODO wyswietlanie
            break;
        case 5:
            // TODO APD
            break;
        case 6:
            // TODO AZ
            break;
        case 7:
            // TODO AW
            break;
        case 8:
        	// TODO usuwanie
            cout << "Konczenie pracy programu" << endl;
            zamykanie = true;
            break;
        }
    }
    return 0;
}
