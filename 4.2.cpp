/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tee ohjelma, joka kysyy käyttäjältä kaksi kokonaislukua
    ja tulostaa lukujen lukujen summan, erotuksen, tulon ja jakojäännöksen.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int eka = 0;
    int toka = 0;
    cout << "Anna ensimmäinen kateetti: " << endl;
    cin >> eka;
    cout << "Anna toinen kateetti: " << endl;
    cin >> toka;
    cout << "Hypotenuusan pituus: " << sqrt(eka*eka + toka*toka) << endl;
}