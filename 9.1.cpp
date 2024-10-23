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

class Tulostusluokka{
    public:
        void Tulosta(string a)
        {
            cout << a;
        }
};

int main()
{
  char merkkijono[50];
  cout << "Anna merkkijono, jonka tulostan: ";
  cin.get(merkkijono, 50);
  Tulostusluokka tulostaja;
  tulostaja.Tulosta(merkkijono);
}