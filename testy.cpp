#include "headers.h"

auto start = chrono::steady_clock::now();
auto endx = chrono::steady_clock::now();

string pliki[9][2][2]=
{
	{{"wyniki/hamilton10ns.txt","wyniki/euler10ns.txt"},{"wyniki/hamilton10s.txt","wyniki/euler10s.txt"}},
	{{"wyniki/hamilton20ns.txt","wyniki/euler20ns.txt"},{"wyniki/hamilton20s.txt","wyniki/euler20s.txt"}},
	{{"wyniki/hamilton30ns.txt","wyniki/euler30ns.txt"},{"wyniki/hamilton30s.txt","wyniki/euler30s.txt"}},
	{{"wyniki/hamilton40ns.txt","wyniki/euler40ns.txt"},{"wyniki/hamilton40s.txt","wyniki/euler40s.txt"}},
	{{"wyniki/hamilton50ns.txt","wyniki/euler50ns.txt"},{"wyniki/hamilton50s.txt","wyniki/euler50s.txt"}},
	{{"wyniki/hamilton60ns.txt","wyniki/euler60ns.txt"},{"wyniki/hamilton60s.txt","wyniki/euler60s.txt"}},
	{{"wyniki/hamilton70ns.txt","wyniki/euler70ns.txt"},{"wyniki/hamilton70s.txt","wyniki/euler70s.txt"}},
	{{"wyniki/hamilton80ns.txt","wyniki/euler80ns.txt"},{"wyniki/hamilton80s.txt","wyniki/euler80s.txt"}},
	{{"wyniki/hamilton90ns.txt","wyniki/euler90ns.txt"},{"wyniki/hamilton90s.txt","wyniki/euler90s.txt"}}
};

void zapisz(long long pomiary[], int naglowek, string nazwa, int iloscPomiarow)
{
	ofstream zapis;
	zapis.open(nazwa, ios_base::app);
	zapis << naglowek << '\t';
	for (int i=0;i<iloscPomiarow;i++)
		zapis<<pomiary[i]<<'\t';
	zapis << '\n';
	zapis.close();
}

void test()
{
    long long pomiary[100];
    /*
        test nr 2 -
            max n=17 dla int,
            max=18 dla short (wtedy maxRozmiar i maxWartosc muszą być mniejsze niż 1500)
            b - dla dużych wartosci ( >2500) zwieksza czas
            maxRozmiar, maxWartosc : nie ma wsplywu na czas

    */
    int wartoscN = 17;
    int maxRozmiar = 5000;
    int testNumer = 1;

    for(int maxWartosc=10; maxWartosc<=25000; maxWartosc*=2)
    {
        int indexPom=0;
        for(int wartoscB=10; wartoscB<=25000; wartoscB*=2)
        {
            cout << maxWartosc << " " << wartoscB << ": ";
            utworzLosowoTest(wartoscN, wartoscB, maxRozmiar, maxWartosc);
            start = chrono::steady_clock::now();
            rozwTest[testNumer]();
            endx = chrono::steady_clock::now();
            pomiary[indexPom++] = chrono::duration_cast<chrono::nanoseconds>(endx - start).count();
            cout << "czas : " << pomiary[indexPom-1] << "ns";
            usunPlecak();
            cout << endl;
        }
        zapisz(pomiary, maxWartosc, "test2B.txt", indexPom);
    }
    cout << "koniec testu" << endl;
}
