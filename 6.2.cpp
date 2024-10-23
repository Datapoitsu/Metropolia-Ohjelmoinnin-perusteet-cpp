/*  
    Kirjoittanut Aarni Junkkala
    Tehtävänanto: 
    Tee ohjelma, joka kysyy käyttäjältä kokonaisluvun n (n>0) ja tulostaa luvun kertoma näytölle.
    Esimerkiksi n:n kertomaa merkitään merkillä n!, joka tarkoittaa lukua, joka saadaan seuraavasti 1*2*3...*n.
*/
#include <iostream>
using namespace std;

int main()
{
    int luku = 0;
    cout << "Anna kokonaisluku: ";
    cin >> luku;
    int tulos = 1;
    for(int i = 1; i < luku + 1; i++)
    {
        tulos *= i;
    }
    cout << "Luvun " << luku << " kertoma on " << tulos << endl;
}