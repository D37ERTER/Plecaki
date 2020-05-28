#include "headers.h"

void APD()
{
    int macierz[n+1][b+1];
    //zerowanie pierwszego wiersza i kolumny
    for(int i=0;i<=n;i++)
        macierz[i][0] = 0;
    for(int i=0;i<=b;i++)
        macierz[0][i] = 0;
    //wypelnianie macierzy
    for(int i=1;i<=n;i++)
    {
        //przepisywanie z gory do rozmiaru
        for(int j=1; j<r[i-1]; j++)
            macierz[i][j] = macierz[i-1][j];
        //wypelnianie maksami
        for(int j=r[i-1]; j<=b; j++)
        {
            if(macierz[i-1][j-r[i-1]] + w[i-1] > macierz[i-1][j])
                macierz[i][j] = macierz[i-1][j-r[i-1]] + w[i-1];
            else
                macierz[i][j] = macierz[i-1][j];
        }
    }

    //wyswietlanie macierzy
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0; j<=b; j++)
            cout << macierz[i][j] << "\t";
        cout << endl;
    }*/

    //odczytwyanie rozwiazania
    cout << "najlepsze rozwiazanie:" << endl;
    cout << "\tspakowane elementy: ";
    int j = b;
    for(int i=n; i>=1; i--)
    {
        if(macierz[i][j] != macierz[i-1][j])
        {
            cout << i << " ";
            j -= r[i-1];
        }
    }
    cout << endl;
    cout << "\twartosc rozwiazania: " << macierz[n][b] << endl;
    cout << "\tzajete miejsce: " << b-j << endl;
}

void quickSort(vector<short> * r, vector<short> * w, vector<short> * org, int l, int p)
{
    int i=l;
    int j=p;
    double sv = (*w)[(l+p)/2]/ ((double)(*r)[(l+p)/2]);
    int t;
    do
    {
        //wyszukiwanie elementow do zamienienia
        while( ((*w)[i] / ((double)(*r)[i])) > sv && i<p) i++;
        while( ((*w)[j] / ((double)(*r)[j])) < sv && j>l) j--;

        if(i>j) break;
        //zamiana rozmiarow
        t = (*r)[i];
        (*r)[i] = (*r)[j];
        (*r)[j] = t;

        //zamiana wartosci
        t = (*w)[i];
        (*w)[i] = (*w)[j];
        (*w)[j] = t;

        //zamiana orginalnej numeracji
        t = (*org)[i];
        (*org)[i] = (*org)[j];
        (*org)[j] = t;

        i++;
        j--;
    }
    while(i<=j);

    if (l<j) quickSort(r, w, org, l, j);
    if (p>i) quickSort(r, w, org, i, p);
}

void AZ()
{
    vector<short> kr = r; //kopia rozmiaru elementow
    vector<short> kw = w; //kopia wartosci elementow
    vector<short> org; //orginalna numeracja
    org.resize(n);
    for(int i=0; i<n; i++)
        org[i] = i;

    //sortowanie (quick sort)
    quickSort(&kr, &kw, &org, 0, n-1);

    //wyswietlanie elementow przed sortowaniem i po sortowaniu (z wspolczynnikami)
    /*
    cout << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|ilosc elementow|"<< n <<"\t|" << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|pojemn. plecaka|"<< b <<"\t|" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "|num.el.|rozmiar|wartosc|" << endl;
    cout << "+-------+-------+-------+" << endl;
    for(int i=0; i<n; i++)
        cout << "|" << i+1 << "\t|" << r[i] << "\t|" << w[i] << "\t|"<< (double) w[i]/r[i] << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|ilosc elementow|"<< n <<"\t|" << endl;
    cout << "+---------------+-------+" << endl;
    cout << "|pojemn. plecaka|"<< b <<"\t|" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "|num.el.|rozmiar|wartosc|" << endl;
    cout << "+-------+-------+-------+" << endl;
    for(int i=0; i<n; i++)
        cout << "|" << i+1 << "\t|" << kr[i] << "\t|" << kw[i] << "\t|" << (double) kw[i]/kr[i] <<endl;
    cout << "+-------+-------+-------+" << endl;
    */

    //wyswietlanie rozwiazania
    cout << "najlepsze rozwiazanie:" << endl;
    cout << "\tspakowane elementy: ";
    int sr = 0;
    int sw = 0;
    for(int i=0;i<n && sr < b;i++)
    {
        if(sr + r[i] <= b)
        {
            cout << org[i]+1 << " ";
            sr += kr[i];
            sw += kw[i];
        }
    }
    cout << endl;
    cout << "\twartosc rozwiazania: " << sw << endl;
    cout << "\tzajete miejsce: " << sr << endl;
}

void AW() //w teorii działa do n=30
{
    int maxu = pow(2, n); //ilosc ulozen
    bool dop[maxu]; //dopuszczalnosc ulozenia
    int sr[maxu]; //suma rozmiarow ulozenia
    int sw[maxu]; //suma wartosci ulozenia

    //tworzenie tabelki
    int i; //index elementu w problemie plecakowym
    int ku; //kopia u
    for(int u=1; u<maxu; u++) //opcje ulozenia elementow
    {
        sr[u] = 0;
        sw[u] = 0;
        dop[u] = true;
        i = 0;
        ku = u;
        while(ku>0)  //kolejne elementy ulozenia (i++)(u/=2)
        {
            if(ku%2) //jezeli element wedlug danego ulozenia wystepuje w plecaku
            {
                sr[u] += r[i];
                sw[u] += w[i];
                if(sr[u] > b) //szybsze konczenie petli jak przekroczylismy pojemnosc plecaka
                {
                    dop[u] = false;
                    break;
                }
            }
            ku/=2;
            i++;
        }
    }
    //wyswietlanie tabelki z wartosciami
    //for(int j=1; j<maxu; j++)
    //    cout << j << "\t" << sr[j] << "\t" << dop[j] << "\t" << sw[j] << endl;

    //szukanie ulozenia dopuszczalnego z maksymalna wartoscia
    int maxsw = 0;
    int maxswu = -1;
    int maxswsr = -1;
    for(int u=1; u<maxu; u++)
    {
        if(dop[u] && sw[u] > maxsw)
        {
            maxsw = sw[u];
            maxswu = u;
            maxswsr = sr[u];
        }
    }

    //wypisywanie rozwiazania
    cout << "najlepsze rozwiazanie:" << endl;
    cout << "\tnumer rozwiazania: " << maxswu << endl;
    cout << "\tspakowane elementy: ";
    for(int i=0; i<n; i++)
    {
        if(maxswu%2)
            cout << i+1 << " ";
        maxswu/=2;
    }
    cout << endl;
    cout << "\twartosc rozwiazania: " << maxsw << endl;
    cout << "\tzajete miejsce: " << maxswsr << endl;
}
