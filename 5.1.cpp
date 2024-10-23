/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: Tee ohjelma, joka pyytää käyttäjältä kokonaisluvun ja tarkistaa,
    onko luku parillinen vai pariton. Jos syötetty luku on parillinen,
    tulostetaan näytölle "Luku 178 on parillinen.", jos luku on pariton,
    tulostetaan näytölle "Luku 233 on pariton.".
*/
#include <iostream>
using namespace std;

int main()
{
    int luku = 0;
    cout << "Anna kokonaisluku: " << endl;
    cin >> luku;
    if(luku % 2 == 0)
    {
        cout << "Luku " << luku << " on parillinen." << endl;
    }
    else
    {
        cout << "Luku " << luku << " on pariton." << endl;
    }
}