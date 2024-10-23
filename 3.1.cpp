/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: Tee ohjelma, joka pyytää käyttäjältä markkamäärän ja muuntaa syötetyn markkamäärän euroiksi.
    Lopuksi ohjelma tulostaa markkamäärän euroina näytölle. Euron kerroin on 5.94573.
    Ohjelmassa käytetään double-tyypin muuttujia.
*/
#include <iostream>
using namespace std;

int main()
{
    double markat = 0;
    cout << "Syötä jokin markkamäärä: " << endl;
    cin >> markat;
    cout << "Markat euroina: " << markat / 5.94573 << endl;
}