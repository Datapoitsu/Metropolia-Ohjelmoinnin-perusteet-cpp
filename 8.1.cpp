/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tee ohjelma, joka laskee tietyn ajanjakson aikana tehtyjen työtuntien määrän sekä tulostaa tuntien yhteismäärän,
    keskimääräisen työpäivän pituuden ja syötetyt tunnit eriteltynä. Ohjelman tulee aluksi kysyä,
    kuinka monen työpäivän tiedot syötetään (max. 30 päivää). Tämän jälkeen ohjelma kysyy päivittäiset työtunnit.
*/
#include <iostream>
using namespace std;

int main()
{
    int paivat = 0;
    cout << "Ohjelma laskee yhteen haluamasi ajanjakson aikana tehdyt\ntyötunnit sekä keskimääräisen työpäivän pituuden.\nKuinka monta päivää:" << endl;
    cin >> paivat;
    float tunnit[paivat];
    for(int i = 0; i < paivat; i++)
    {
        cout << "Anna " << i + 1 << ". päivän työtunnit: " << endl;
        cin >> tunnit[i];
    }

    float yhteensa = 0;
    for(int i = 0; i < paivat; i++)
    {
        yhteensa += tunnit[i];
    }

    cout << "Tehdyt tunnit yhteensä: " << yhteensa << endl;
    cout << "Keskimääräinen työpäivän pituus: " << yhteensa / paivat << endl;
    cout << "Syötetyt tunnit: ";
    for(int i = 0; i < paivat; i++)
    {
        cout << tunnit[i] << " ";
    }
}