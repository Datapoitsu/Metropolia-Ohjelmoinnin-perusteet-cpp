/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tee ohjelma,
    joka kysyy käyttäjältä kokonaisluvun n (n>0) ja tulostaa monitorille luvut 1,2,3..n allekkain.
    Tee ohjelma käyttäen for-lausetta.
*/
#include <iostream>
using namespace std;

int main()
{
    int luku = 0;
    cout << "Anna kokonaisluku: ";
    cin >> luku;

    for(int i = 1; i < luku + 1; i++)
    {
        cout << i << endl;
    }
}