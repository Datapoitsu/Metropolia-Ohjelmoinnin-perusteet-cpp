/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Alla oleva ohjelma luo luokkaan Tulostusluokka pohjautuvan olion nimeltään tulostaja
    ja käyttää sen jälkeen tuota oliota tekstin tulostamiseen.
    Sinun tehtävänäsi on kirjoittaa luokka Tulostusluokka ja
    siihen metodi tulostusta varten (alla olevaa koodia ei siis tarvitse kopioida palautuskenttään).
*/
#include <iostream>
#include <string>
using namespace std;

class KysyJaTulosta{
    public:
        void TeeHommasi(string a){
            cout << a;
            string b;
            getline(cin,b);
            cout << b;
        }
};

int main (void)
{
  char merkkijono[] = "Anna merkkijono, jonka tulostan: ";
  KysyJaTulosta olio;
  olio.TeeHommasi(merkkijono);
}