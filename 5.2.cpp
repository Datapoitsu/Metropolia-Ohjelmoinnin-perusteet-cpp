/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tee ohjelma, joka kysyy juoko käyttäjä kahvia vai teetä, ja tämän jälkeen kuinka monella sokeripalalla.
    Ohjelman tulostus riippuu käyttäjän vastauksista:
        Kahvi 0-2 palaa: "Kahvi kyllä piristää!"
        Kahvi 3+ palaa: "Kahvi voi olla aika vahva maku..."
        Tee 0-2 palaa: "Tee usein rauhoittaa!"
        Tee 3+ palaa: "Taidat pitää teestäsi makeana?"
        Muuten "Ohjelmassa tapahtunut virhe!"
    Sokeripalat käsitellään kokonaislukumuuttujana ja juoma merkkimuuttujana ('k'/'t'). Isoja kirjaimia ei tarvitse huomioida.
*/
#include <iostream>
using namespace std;

int main()
{
    char vastaukset[5][64] = {"Ohjelmassa tapahtunut virhe!","Kahvi kyllä piristää!","Kahvi voi olla aika vahva maku...","Tee usein rauhoittaa!","Taidat pitää teestäsi makeana?"};
    char juotava = 'a';
    cout << "Juotko kahvia vai teetä? (k/t) " << endl;
    cin >> juotava;
    int sokeri = 0;
    cout << "Montako palaa sokeria? " << endl;
    cin >> sokeri;
    if(juotava != 'k' && juotava != 't' || sokeri < 0)
    {
        cout << vastaukset[0] << endl;
    }
    else if(sokeri >= 0 && sokeri <= 2)
    {
        sokeri = 1;
    }
    else
    {
        sokeri = 2;
    }
    if(juotava == 't'){
        sokeri += 2;
    }
    cout << vastaukset[sokeri] << endl;
}