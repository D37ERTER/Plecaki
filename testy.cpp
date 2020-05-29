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
        test nr 0 -

        test nr 1 -
            n wplywa na czas i (pewnie na pamiec tez ale komu chce sie czekac) O(n*logn)
            b, maxRozmar, maxWartosc nie wpywaja na czas i pamiec
        test nr 2 -
            pamiec : max n=17 dla int,
            pamiec : max=18 dla short (wtedy maxRozmiar i maxWartosc muszą być mniejsze niż 1500)
            czas : wzrasta wykladniczo z n (n wieksze o 1 to czas wiekszy razy 2) O(2^n) najlepiej wzrost widać dla n = [12..17] i b >= 65536
            czas : b - dla dużych wartosci (>=65536) skokowo zwieksza czas; prawdopodobnie optymalizacja przez system dla b <= 65536
            czas : maxRozmiar, maxWartosc : nie ma wsplywu na czas

    */
    //parametry poczatkowe
    int maxRozmiar = 16384;
    int maxWartosc = 16384;
    //int wartoscB = 67108864;
    int testNumer = 2;

    //test
    for(int wartoscB = 128; wartoscB<=268435456; wartoscB*=2)
    {
        int poprzedniCzas = 0;
        int indexPom=0;
        for(int wartoscN = 11; wartoscN<=17; wartoscN++)
        {
            cout << wartoscB << " " << wartoscN << ": ";
            utworzLosowoTest(wartoscN, wartoscB, maxRozmiar, maxWartosc);
            start = chrono::steady_clock::now();
            rozwTest[testNumer]();
            endx = chrono::steady_clock::now();
            pomiary[indexPom++] = chrono::duration_cast<chrono::nanoseconds>(endx - start).count();
            cout << "czas : " << pomiary[indexPom-1] << "ns " ;
            cout << "stosunek: " << (poprzedniCzas? ((pomiary[indexPom-1]/100000)/((double)(poprzedniCzas))) :0);
            poprzedniCzas = pomiary[indexPom-1]/100000;
            usunPlecak();
            cout << endl;
        }
        zapisz(pomiary, 0, "test2v2.txt", indexPom);
    }
    cout << "koniec testu" << endl;
}
