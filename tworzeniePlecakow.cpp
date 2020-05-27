#include "headers.h"

void utworzLosowo()
{
    cout << "Tworzenie problemu plecakowego losowo." << endl;
    n = zKonsoli(1, 1000, "podaj ilosc elementow: ", "Nie poprawna ilosc. (musi byc od 1 do 1000)");
    b = zKonsoli(1, 32767, "podaj pojemnosc plecaka: ", "Nie poprawna ilosc. (musi byc od 1 do 32767)");
    int maxr = zKonsoli(1, 32767, "podaj maksymalny rozmiar elementu: ", "Nie poprawna ilosc. (musi byc od 1 do 32767)"); //maksymalny rozmiar przy losowaniu
    int maxw = zKonsoli(1, 32767, "podaj maksymalna wartosc elementu: ", "Nie poprawna ilosc. (musi byc od 1 do 32767)"); //maksymalna wartosc plzy losowaniu

    r.resize(n);
    w.resize(n);

    for(int i=0; i<n; i++)
    {
        r[i] = 1 + rand() % maxr;
        w[i] = 1 + rand() % maxw;
    }
}

void utworzZKonsoli()
{
    cout << "Tworzenie problemu plecakowego losowo." << endl;
    n = zKonsoli(1, 1000, "podaj ilosc elementow: ", "Nie poprawna ilosc. (musi byc od 1 do 1000)");
    b = zKonsoli(1, 32767, "podaj pojemnosc plecaka: ", "Nie poprawna ilosc. (musi byc od 1 do 32767)");

    r.resize(n);
    w.resize(n);
    cout << "Wprowadzanie elementow z konsoli." << endl;
    for(int i=0; i<n; i++)
    {
        r[i] = zKonsoli("podaj rozmiar elementu (" + toString(i+1) + "/" + toString(n) + "): ", "Bledny rozmiar.");
        w[i] = zKonsoli("podaj wartosc elementu (" + toString(i+1) + "/" + toString(n) + "): ", "Bledna wartosc.");
    }
}

void utworzZPliku()
{
    string loc;
    fstream plik;
    cout << "Generowanie problemu plecakowego z pliku." << endl;
    cout << "podaj lokalizacje pliku: ";
    cin >> loc;
    plik.open(loc.c_str(), ios::in);
    if(plik.good())
    {
        plik >> n;
        plik >> b;
        r.resize(n);
        w.resize(n);

        int i=0;
        while(i<n && !plik.eof())
        {
            plik >> r[i];
            plik >> w[i];
            i++;
        }
        if(i!=n)
        {
            cout << "Zbyt malo danych elemntow. :C";
            plik.close();
            return;
        }
    }
    else
    {
        cout << "Niepoprawna lokalizacja. :C";
    }
    plik.close();
}
