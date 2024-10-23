/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: Tee ohjelma, joka kysyy käyttäjältä ympyrän säteen ja laskee annetun säteen
    perusteella ympyrän pinta-alan. Lopuksi pinta-ala tulostetaan näytölle.
    Piin (\pi) arvona käytetään likiarvoa 3.142.
    Käyttäjän oletetaan syöttävän säteen arvoksi kokonaislukuja.
*/
#include <iostream>
using namespace std;

int main()
{
    double sade = 0;
    cout << "Anna ympyrän säde: " << endl;
    cin >> sade;
    cout << "Ympyrän ala annetulla säteellä: " << 3.142 * sade * sade << endl;
}