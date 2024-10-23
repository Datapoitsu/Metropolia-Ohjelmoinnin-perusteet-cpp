/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Viope C++:n viimeisessä tehtävässä harjoitellaan periytyvän luokan laatimista.
    Alla näet ohjelman, jossa on määritelty luokka Ajoneuvo.
    Pääohjelmassa käytetään Ajoneuvo-luokasta periytyvän Auto-luokan oliota.
    Sinun tehtävänäsi on Auto-luokan ja sen metodien tekeminen.
*/
#include <iostream> 
#include <string> 
using namespace std; 

// Luokka Ajoneuvo sisältää saantimetodit  
// AnnaPaino(), AnnaHuippunopeus(), AnnaAjetutKilometrit(), joiden avulla 
// luokan Ajoneuvo muuttujien arvot voidaan lukea periytetyssä luokassa. 
// Lisäksi Ajoneuvo sisältää metodin Aja(matka kilometreinä),  
// joka kasvattaa ajoneuvolla ajettuja kilometrejä. 

class Ajoneuvo 
{ 
public: 
  int paino; 
  int huippu_nopeus; 
  long ajetut_kilometrit; 
  Ajoneuvo(int paino, int huippu_nopeus, long ajetut_kilometrit); 
  void Aja(int ajettava_matka); 
  int AnnaPaino(); 
  int AnnaHuippunopeus(); 
  long AnnaAjetutKilometrit(); 
}; 

// Luokassa on vain yksi alustusmetodi, jossa Ajoneuvon ominaisuudet 
// viedään parametrina heti olion muodostamisen yhteydessä. 

Ajoneuvo::Ajoneuvo(int Ap, int Ahn, long Akm) 
{ 
  paino = Ap; 
  huippu_nopeus = Ahn; 
  ajetut_kilometrit = Akm; 
} 

void Ajoneuvo::Aja(int ajettava_matka) 
{ 
  ajetut_kilometrit += ajettava_matka; 
} 

int Ajoneuvo::AnnaPaino() 
{ 
  return paino; 
} 

int Ajoneuvo::AnnaHuippunopeus() 
{ 
  return huippu_nopeus; 
} 

long Ajoneuvo::AnnaAjetutKilometrit() 
{ 
  return ajetut_kilometrit; 
} 

// Auto-luokka ja sen metodit (sinun ratkaisusi)  
// 
// 
// Luokan ominaisuudet: (suluissa tietotyyppi) 
// - merkki (string) 
// - malli (string) 
// - rekisteri_nro (string) 
// - kaynnissa (bool) 
// Luokan metodit 
// - kaynnista(), muuttaa kaynnissa-muuttujan arvoksi 1 
// - sammuta(), muuttaa kaynnissa-muuttujan arvoksi 0 
// - katsasta(), tulostaa auton tiedot esimerkkitulosteen mukaisesti 
// Muita huomioita 
// - Muuttujien arvoihin pääset käsiksi käyttämällä Ajoneuvo-luokan saantimetodeja 
// - Mikäli auto on käynnissä, kun se katsastetaan tulostetaan: "Auto käynnissä" 
// - Vastaavasti auton ollessa sammutettuna, tulostetaan: "Auto ei ole käynnissä" 


// pääohjelma  
//////////////////////////////////////// 

class Auto : public Ajoneuvo
{
  public:
    string merkki;
    string malli;
    string rekisteri_nro;
    bool kaynnissa;

    Auto(int a,int b, int c, string d,string e,string f, int g) : Ajoneuvo(a,b,c)
    {
      merkki = d;
      malli = e;
      rekisteri_nro = f;
      kaynnissa = g;
    }

    //autoX(paino, nopeus, km, merkki, malli, rekkari, 0); 
    void kaynnista(){
      kaynnissa = true;
    }
    void sammuta(){
      kaynnissa = false;
    }
    void katsasta(){
      cout << "Auton tiedot: " << endl;
      cout << "Merkki: " << merkki << endl;
      cout << "Malli: " << malli << endl;
      cout << "Ajokilometrit: " << ajetut_kilometrit << endl;
      cout << "Paino: " << paino << endl;
      cout << "Huippunopeus: " << huippu_nopeus << endl;
      cout << "Rekisterinumero: " << rekisteri_nro << endl;
      if(kaynnissa){
        cout << "Auto on käynnissä." << endl;
      }
      else{
        cout << "Auto ei ole käynnissä." << endl;
      }
    }
};

int main() 
{ 
  int paino, nopeus; 
  long km; 
  string merkki, malli, rekkari; 

  // kysellään tietoja autosta 
  cout << "Anna auton merkki: "; 
  cin >> merkki; 

  cout << "Anna auton malli: "; 
  cin >> malli;  

  cout << "Anna auton rekisterinumero: "; 
  cin >> rekkari; 
   
  cout << "Anna auton paino: "; 
  cin >> paino;  

  cout << "Anna auton huippunopeus: "; 
  cin >> nopeus;  
   
  cout << "Anna autolla ajetut kilometrit: "; 
  cin >> km;  
  cout << endl; 
  Auto autoX(paino, nopeus, km, merkki, malli, rekkari, 0); 

  autoX.katsasta(); 
  autoX.kaynnista(); 
  autoX.Aja(95); 
  cout << endl; 
  autoX.katsasta(); 
} 