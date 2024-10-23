/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tehtävänäsi on tehdä ohjelma,
    joka lukee merkkejä (char) ja merkkijonoja (string) tiedostosta opiskelijat.txt ja
    tulostaa tiedot näytölle. Näytölle tulostuksen tulee olla esimerkkitulostuksen mukainen.
    Tiedostossa jokaisen opiskelijan tiedot ovat omalla rivillään.
    Jos tiedoston opiskelijat.txt avaaminen ei onnistu,
    tulee ohjelman tulostaa näytölle teksti "Tiedoston avaaminen ei onnistunut!".
    Heti tämän jälkeen ohjelman suorituksen on loputtava.
    Jos esimerkiksi tiedoston (opiskelijat.txt) sisältö on seuraava:
    Z Kakke Kahvinen
    Y Yrjänä Yksinäinen
    , tulostuvat tiedot näytölle seuraavasti:
    Kalle Kahvinen: luokka Z
    Yrjänä Yksinäinen: luokka Y
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string teksti;
    ifstream filu("opiskelijat.txt");
    if(!filu){
        cout << "Tiedoston avaaminen ei onnistunut!" << endl;
    }
    else{
        char luokka;
        string nimi;
        int counter = 0;
        while (filu >> teksti)
        {
            luokka = teksti[0];
            getline(filu,nimi);
            cout << nimi << ": luokka " << luokka << endl;
        }
    }
}