/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Alla oleva ohjelma kysyy käyttäjältä kolme kokonaislukua
    ja tulostaa syötetyistä luvuista suurimman ja pienimmän näytölle.
    Tehtävänäsi on kirjoittaa ohjelmasta puuttuvat funktiot (suurin() ja pienin()),
    jotka saavat parametreina käyttäjän syöttämät kokonaisluvut ja palauttavat nimensä mukaiset kokonaisluvut.
*/
#include <iostream>
using namespace std;

int suurin(int eka, int toka, int kolmas);
int pienin(int eka, int toka, int kolmas);

int main()
{
    int luku1, luku2, luku3, suurinLuku, pieninLuku;
    cout << "Syötä ensimmäinen kokonaisluku:";
    cin >> luku1;
    cout << "Syötä toinen kokonaisluku:";
    cin >> luku2;
    cout << "Syötä kolmas kokonaisluku:";
    cin >> luku3;
    suurinLuku = suurin(luku1, luku2, luku3);
    pieninLuku = pienin(luku1, luku2, luku3);
    cout << "Syöttämistäsi luvuista suurin oli " << suurinLuku;
    cout << " ja pienin " << pieninLuku << "." << endl;
}

int suurin(int eka, int toka, int kolmas){
    if(eka > toka && eka > kolmas){return eka;}
    if(toka > eka && toka > kolmas){return toka;}
    if(kolmas > eka && kolmas > toka){return kolmas;}
}

int pienin(int eka, int toka, int kolmas){
    if(eka < toka && eka < kolmas){return eka;}
    if(toka < eka && toka < kolmas){return toka;}
    if(kolmas < eka && kolmas < toka){return kolmas;}
}