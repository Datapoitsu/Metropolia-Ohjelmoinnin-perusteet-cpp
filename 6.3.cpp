/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tee ohjelma,
    joka kysyy oppilaiden koearvosanoja (kokonaisluvut 4-10 käytössä) ja laskee syötettyjen arvosanojen keskiarvon.
    Ohjelman tulee ottaa vastaan arvosanoja, kunnes arvosanojen syöttö lopetetaan negatiivisella kokonaisluvulla.
    Lopuksi ohjelma tulostaa arvosanojen lukumäärän sekä lasketun keskiarvon.
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "Ohjelma laskee koearvosanojen keskiarvon." << endl;
    cout << "Lukujen syöttämisen lopetus negatiivisella luvulla." << endl;
    float summa = 0;
    int maara = 0;
    while (true)
    {
        int holder = 0;
        cout << "Anna arvosana (4-10): ";
        cin >> holder;
        if(holder < 0){
            break;
        }
        summa += holder;
        maara++;
    }
    
    cout << "Ohjelmaan syötetty " << maara << " arvosanaa." << endl;
    cout << "Arvosanojen keskiarvo: " << summa / maara << endl;
}