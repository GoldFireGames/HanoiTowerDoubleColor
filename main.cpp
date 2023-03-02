#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void biColourHanoi(int n, char a, char b, char c);
void pomoc(int n);
static int liczbaRuchow = 0;

int main()
{

    int n;

    cout<<"Podaj ilosc krazkow: (parzysta)"<<endl;
    do
    {
        cin>>n;
        if(n%2!=0 || n<=0)
        {
            cout<<"Podano bledna wartosc! sproboj jeszcze raz: "<<endl;
        }
    }
    while(n%2!=0 || n<=0);   /// warunek
    cout<<"3"<<endl; // liczba slupków
    pomoc(n);


    return 0;
}


void biColourHanoi(int n, char a, char b, char c) /// funkcja do przenoszenia n krazków z s³upka-a na s³upek-b, palka c jest palka pomocnicza
{
    if (n>0)
    {
        biColourHanoi(n-2, a, c, b);
        cout<<a<<" "<<b<<endl;
        cout<<a<<" "<<b<<endl;
        biColourHanoi(n-2, c, b, a);
        liczbaRuchow=liczbaRuchow+2;
    }

}


void pomoc(int n) /// to co robie pokolei
{
    char a='1', b='2', c='3';
    n=n-2;                  /// nie przenoszê dwóch najwiêkszych
    biColourHanoi(n,a,b,c); ///1krok 51 przeniesie mi np dla 6: przeniesie 4 krazki
    cout<<a<<" "<<c<<endl;  ///2krok 53 przeniesie jedna najwieksza na pomocnicz¹, rozdzielam podstawy
    liczbaRuchow++;

    while(n>2)
    {
        n=n-2;
        biColourHanoi(n, b, c, a);  ///3krok zmniejszamy n o 2 i znowu przenosimy z drugiej na trzecia
        cout<<b<<" "<<a<<endl;  ///4 krok manualnie przenosze z b na a. w tym kroku s¹ ju¿ dobrze ulozone dwa p6
        liczbaRuchow++;
        biColourHanoi(n, c, a, b);  /// 5 krok przenosze z trzeciego na pierwsz¹ (tyle ile przenioslem w kroku 3)
        cout<<b<<" "<<c<<endl;  /// krok 6 z drugiej na trzecia i mam juz dobrze ulozone 4 krazki,
        liczbaRuchow++;
        n=n-2;
        biColourHanoi(n, a, b, c);  /// to jest to samo co linia 51
        cout<<a<<" "<<c<<endl;
        liczbaRuchow++;
    }
    ///w przypadku gdy n>2 to wywoluje sie petla, gdy n=2 wywola sie if, a gdy n = 0 program zakonczy dzialanie
    if (n>0) /// uruchomi siê gdy liczba kr¹¿ków bedzie podzielna przez 4 poniewaz w whilu zostanie na koncu wartoœæ n =2, funkcja while sie nie wywola dla n = 2
    {
        cout<<b<<" "<<a<<endl;
        liczbaRuchow++;
        cout<<b<<" "<<c<<endl;
        liczbaRuchow++;
    }

    cout<<"Liczba ruchow: "<<liczbaRuchow<<endl;
}

