/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Täydennä aikaisemmin laatimaasi laskinohjelmaa niin,
    että käyttäjä voi valita, mikä laskutoimitus suoritetaan.
    Ohjelma kysyy ensin mikä laskutoimitus suoritetaan.
    Tämän jälkeen ohjelma kysyy kokonaisluvut, suorittaa laskutoimituksen ja tulostaa saadun tuloksen.
    Ohjelman valinta on tehtävä käyttämällä switch()-lausetta.
*/
#include <iostream>
using namespace std;

int main()
{
    int toimitus = 0;
    cout << "Käytössäsi on seuraavat laskutoimitukset:\n1: vähennyslasku\n2: yhteenlasku\n3: kertolasku\n4: osamäärä\n5: jakojäännös\nValitse laskutoimitus: " << endl;
    cin >> toimitus;

    int eka = 0;
    cout << "Anna eka luku: " << endl;
    cin >> eka;
    int toka = 0;
    cout << "Anna toinen luku: " << endl;
    cin >> toka;

    switch (toimitus)
    {
    case 1:
        cout << eka << "-" << toka << " = " << eka-toka << endl;
        break;
    case 2:
        cout << eka << "+" << toka << " = " << eka+toka << endl;
        break;
    case 3:
        cout << eka << "*" << toka << " = " << eka*toka << endl;
        break;
    case 4:
        cout << eka << "/" << toka << " = " << eka/toka << endl;
        break;
    case 5:
        cout << eka << "%" << toka << " = " << eka%toka << endl;
        break;
    default:
        break;
    }
}