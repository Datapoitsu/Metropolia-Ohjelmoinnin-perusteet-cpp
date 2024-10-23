/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tee funktio bubblesort,
    joka käyttää kuplalajittelualgoritmia lajitellakseen käyttäjän antamat numerot pienimmästä suurimpaan.
    Funktion kutsu- ja paluulause on annettu valmiiksi. Funktio saa parametrinaan lajiteltavan taulukon ja alkioiden määrän.
    Kuplalajittelu on yksinkertainen lajittelualgoritmi,
    joka toistuvasti vaihtaa peräkkäiset alkiot keskenään mikäli ne ovat väärässä järjestyksessä.
    Kts. https://en.wikipedia.org/wiki/Bubble_sort
*/

#include <iostream>

using namespace std;

int* bubblesort(int a[], int n){
    for(int i = n - 1; i > 0 ; i--)
    {
        for(int k = 0; k < i; k++){
            if(a[k] > a[k+1]){
                swap(a[k],a[k+1]);
            }
        }
    }
    return a;
}

int main()
{
    int number;
    cout << "Anna lajiteltavien numeroiden lukumäärä: ";
    cin >> number;
    int list[number];
    for (int i=0;i<number;i++)
    {
        int value;
        cout << "Anna taulukon " << i+1 << " numero: ";
        cin >> value;
        list[i] = value;
    }
    int *sorted = bubblesort(list,number);
    cout << "Lajiteltu taulukko nousevassa järjestyksessä: [";
    for(int i = 0; i<number-1; i++) {
       cout << sorted[i] << ", ";
    }
    cout << sorted[number-1] << "]" << endl;
    return 0;
}