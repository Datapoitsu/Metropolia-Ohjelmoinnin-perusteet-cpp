/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tässä harjoituksessa tehdään kaksi funktiota

    mysplit: joka jakaa ensimmäisenä parametrina annetun lauseen (string) toisena parametrina annetun erotinmerkin (char) erottelemiin alkioihin, funktio palauttaa tuloksena vektorin (vector<string>) .
    myjoin: joka liittää ensimmäisenä parametrina annetun vektorin (vector<string>) alkiot merkkijonoksi, jossa alkioiden väliin on lisätty toisena parametrina annettava merkki, funktio palauttaa merkkijonon (string).


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> mysplit(string sentence, char sep);
string myjoin(vector<string> lst, char sep);

int main()
{
    string sentence;
    cout << "Kirjoita lause: ";
    getline (cin,sentence);
    cout << myjoin(mysplit(sentence, ' '), ',') <<endl;
    cout << myjoin(mysplit(sentence, ' '), '\n') <<endl;
    return 0;
}

vector<string> mysplit(string sentence, char sep)
{
    vector<string> parts;
    int start = 0;
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == sep)
        {
            parts.push_back(sentence.substr(start, i - 1 - start));
            start = i + 1;
        }
    }
    parts.push_back(sentence.substr(start, sentence.size() - start));
    return parts;
}

string myjoin(vector<string> lst, char sep){
    string result = lst[0];
    for(int i = 1; i < lst.size(); i++){
        result = result + sep + lst[i];
    }
    return result;
}