/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tehtävänäsi on tehdä ohjelma, joka lukee kokonaislukuja (int) tiedostosta ja tulostaa niiden summan näytölle.
    Näytölle tulostuksen tulee olla esimerkkitulostuksen mukainen.
    Tiedostossa jokainen luku on omalla rivillään.
    Lukujen summa kirjoitetaan samaan tiedostoon viimeiseksi luvuksi.
    Tiedoston nimi on luvut.txt. Jos tiedoston luvut.txt avaaminen ei onnistu,
    tulee ohjelman tulostaa näytölle teksti "Tiedoston avaaminen ei onnistunut!".
    Heti tämän jälkeen ohjelman suorituksen on loputtava. 
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string luku;
    int summa = 0;
    ifstream filu("luvut.txt");
    if(!filu){
        cout << "Tiedoston avaaminen ei onnistunut!" << endl;
    }
    else{
        while (getline (filu, luku))
        {
            summa += stoi(luku);
        }
        cout << "Lukujen summa on " << summa << std::endl;
    }
}