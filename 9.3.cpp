/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tehtävässä on kirjoitettu valmiiksi pääohjelma, sekä luokka "Laskin".
    Sinun tehtäväsi on laatia luokka "Tulostaja", joka kysyy käyttäjältä kaksi kokonaislukua,
    kutsuu luokan "Laskin" metodia "Summa()" välittäen metodille syötteenä saadut kokonaisluvut.
    Metodi "Summa()" laskee lukujen summan ja palauttaa tuloksen.
    Lopuksi metodi "Tulosta()" tulostaa saadun summan näytölle.
    Alla olevaa koodia ei siis tarvitse kopioida palautuskenttään. 
*/
#include <iostream>
using namespace std;

class Laskin
{
  public:

  int Summa(int eka, int toka);
};

int Laskin::Summa(int eka, int toka)
{
  int summa = eka + toka;
  return summa;
}

class Tulostaja{
    public:
        Laskin laskuri;
        void Tulosta(){
            int eka = 0;
            cout << "Syötä ensimmäinen kokonaisluku: " << endl;
            cin >> eka;
            int toka = 0;
            cout << "Syötä toinen  kokonaisluku: " << endl;
            cin >> toka;
            cout << "Lukujen summa: " << laskuri.Summa(eka,toka) << endl;
        }
};

int main()
{  
  Tulostaja olio;
  olio.Tulosta();
}