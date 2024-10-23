/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tee ohjelma, joka kysyy käyttäjältä kaksi kokonaislukua
    ja tulostaa lukujen lukujen summan, erotuksen, tulon ja jakojäännöksen.
*/
#include <iostream>
using namespace std;

int main()
{
    int eka = 0;
    int toka = 0;
    cout << "Syötä ensimmäinen kokonaisluku: " << endl;
    cin >> eka;
    cout << "Syötä toinen kokonaisluku: " << endl;
    cin >> toka;
    cout << eka << "+" << toka << " =" << eka + toka << endl;
    cout << eka << "-" << toka << " =" << eka - toka << endl;
    cout << eka << "*" << toka << " =" << eka * toka << endl;
    cout << "Jakojäännös: " << eka % toka << endl;
}