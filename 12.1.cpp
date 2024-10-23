/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tee yksinkertainen Supermarket-ohjelma,
    jossa kymmenen tuotteen hinnat ovat taulukossa seuraavasti:
    int prodprices[] = { 10, 14, 22, 33, 44, 13, 22, 55, 66, 77 };.
    joka kysyy cin >> prodnbr tuotteen numeroa väliltä 1 - 10 ja
    laskee taulukosta haettavan tuotteen hinnan mukaan ostosten kokonaissummaan,
    samalla tulostaen haetun tuotteen numeron ja hinnan.
    joka kysyy tuotteita kunnes käyttäjä antaa '0' lopettaakseen ohjelman (do while-silmukka).
    joka lopuksi tulostaa 'Yhteensä:' ostosten kokonaissumma
    ja pyytää käyttäjältä summan 'Maksu:' ja tulostaa lopuksi palautettavat vaihtorahat
    'Vaihto:' (maksu - summa) käyttäjälle.
    Ohjelmassa on käytettävä: [], while, cin, cout, endl.
*/

#include <iostream>
using namespace std;

int main() {
    int prodprices[] = { 10, 14, 22, 33, 44, 13, 22, 55, 66, 77 };
    int prodnbr = 0;
    int total = 0;
    cout << "Supermarket" << endl;
    cout << "===========" << endl;
    while (true)
    {
        cout << "Valitse tuote (1-10) 0 lopetus: ";
        cin >> prodnbr;
        if (prodnbr == 0)
        {
            break;
        }
        if(prodnbr > 10){
            cout << "Anna tuote oikein väliltä (1-10)" << endl;
            continue;
        }
        cout << "Tuote: " << prodnbr << " Hinta: " << prodprices[prodnbr - 1] << endl;
        total += prodprices[prodnbr - 1];
    }
    cout << "Yhteensä: " << 144 << endl;
    cout << "Maksu: ";
    int maksu = 0;
    cin >> maksu;
    cout << "Vaihto: " << maksu - total << endl;
}