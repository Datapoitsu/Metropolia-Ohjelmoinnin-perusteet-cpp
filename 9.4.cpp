/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Alla on luokka "Koira", josta puuttuu olioden muodostamiseen tarvittava alustusmetodi,
    sekä metodit TulostaTiedot() ja Hauku(). Täydennä luokkaa niin, että luokasta voidaan muodostaa olioita.
    Ja tee puuttuvat metodit. Olion muodostamisen yhteydessä olio saa arvot: ikä, nimi, rotu ja ääni. 
*/
#include <iostream> 
#include <string> 
using namespace std; 

class Koira 
{ 
  public:
    int ika; 
    string nimi, rotu, aani;
    Koira(int a, string b, string c, string d){
      ika = a;
      nimi = b;
      rotu = c;
      aani = d;
    }
    void TulostaTiedot()
    {
      cout << "Nimi: " << nimi << endl;
      cout << "Ikä: " << ika << endl;
      cout << "Rotu: " << rotu << endl;
    }
    string Hauku()
    {
      return aani;
    }
};

int main() 
{ 
  Koira rekku(2, "Rekku", "Dalmatialainen", "Hau!!!"); 
  cout << "Koiran tiedot:" << endl; 
  rekku.TulostaTiedot(); 
  cout << "Koira sanoo: " << rekku.Hauku(); 
} 