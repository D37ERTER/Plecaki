#include "headers.h"

void wyswietlPlecak() //dziala dla liczb mniejszych niz 10 milionow
{
    cout << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|ilosc elementow|"<< n <<"\t|" << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|pojemn. plecaka|"<< b <<"\t|" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "|num.el.|rozmiar|wartosc|" << endl;
    cout << "+-------+-------+-------+" << endl;
    for(int i=0; i<n; i++)
        cout << "|" << i+1 << "\t|" << r[i] << "\t|" << w[i] << "\t|" << endl;
    cout << "+-------+-------+-------+" << endl;
}

void usunPlecak()
{
    n = 0;
    b = 0;
    r.clear();
    w.clear();
}
