#include "headers.h"

void APD()
{

}

void AZ()
{

}

void AW() //w teorii działa do n=30
{
    int maxu = pow(2, n);
    int sr[maxu]; //suma rozmiarow ulozenia
    int sw[maxu]; //suma wartosci ulozenia
    bool dop[maxu]; //dopuszczalnosc ulozenia
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
    //for(int j=1; j<maxu; j++)
    //    cout << j << "\t" << sr[j] << "\t" << dop[j] << "\t" << sw[j] << endl;
    int maxsw = 0;
    int maxswu = -1;
    for(int u=1; u<maxu; u++)
    {
        if(dop[u] && sw[u] > maxsw)
        {
            maxsw = sw[u];
            maxswu = u;
        }
    }
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
}
