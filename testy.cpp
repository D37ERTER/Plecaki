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

void zapisz(long long pomiary[], int ile, string nazwa, int iloscPomiarow)
{
	ofstream zapis;
	zapis.open(nazwa, ios_base::app);
	zapis << ile << '\t';
	for (int i=0;i<iloscPomiarow;i++)
		zapis<<pomiary[i]<<'\t';
	zapis << '\n';
	zapis.close();
}

void test()
{

}
