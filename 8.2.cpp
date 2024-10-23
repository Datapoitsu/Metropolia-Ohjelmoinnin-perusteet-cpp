/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Alla oleva C++ -ohjelma lukee tiedostosta matriisi.txt
    kokonaislukutaulukon sijoittaen sen 5x5 taulukkoon (matriisi[5][5]).
    Ohjelma tulostaa matriisin näytölle, laskee alkioiden summan ja tulostaa summan näytölle
    hyödyntäen funktioita tulosta_matriisi() ja laske_summa().
    Sinun tehtävänä on laatia em. funktiot. Rivillä sijaitsevat arvot erotellaan välilyönnein.
    Huomaa, että tiedostojen käsittely ei kuulu varsinaisesti kurssin aihealueeseen.
*/
#include <iostream>
#include <fstream>
using namespace std;

void tulosta_matriisi(int matriisi[5][5]);
int laske_summa(int matriisi[5][5]);

int main(void)
{
  int matriisi[5][5];
  int summa;
  ifstream luku("matriisi.txt");
  if (!luku){
        cout << "Tiedoston avaaminen epäonnistui...";
  }
  else {
    for (int y=0; y<5;y++){
          for (int x=0;x<5;x++){
            luku >> matriisi[y][x];
          }
    }
    luku.close();
    cout << "Matriisi:" << endl;
    tulosta_matriisi(matriisi);
    summa = laske_summa(matriisi);
    cout << "Alkioiden summa: " << summa << endl;
  }
}

void tulosta_matriisi(int matriisi[5][5]){
    for(int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 5; k++)
        {
            cout << matriisi[i][k] << " ";
        }
        cout <<"\n";
    }
}

int laske_summa(int matriisi[5][5])
{
    int summa = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 5; k++)
        {
            summa += matriisi[i][k];
        }

    }
    return summa;
}