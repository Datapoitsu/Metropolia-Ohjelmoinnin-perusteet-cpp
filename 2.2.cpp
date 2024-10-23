//Kirjoittanut Aarni Junkkala
//Tehtävänanto: Kirjoita ohjelma, joka kysyy käyttäjältä kahta lukua ja tulostaa niiden summan.

#include <iostream>
using namespace std;

int main()
{
    int eka = 0;
    int toka = 0;
    cout << "Anna ensimmäinen luku: " << endl;
    cin >> eka;
    cout << "Anna toinen luku: " << endl;
    cin >> toka;
    cout << "Antamiesi lukujen summa on " << eka + toka << endl;
}