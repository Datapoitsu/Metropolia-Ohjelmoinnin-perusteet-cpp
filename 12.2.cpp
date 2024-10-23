/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Määrittele aluksi luokka Employee ja sen alustus-metodi. Employee -luokalla on kaksi attribuuttia: id ja name.
    Tee ohjelma,
    joka lisää vektoriin (vector<Employee>) Employee-luokan olioita.
    Id on laskennallinen järjestysnumero alkaen luvusta 1 ja name (nimi) kysytään käyttäjältä
    ja annetaan muodossa "Etunimi Sukunimi". Käytä getline (cin,name) lukeaksesi nimen.
    jonka suoritus lopetetaan käyttäjän antaessa nimen sijasta '0'.
    joka lopussa tulostaa vektorin sisällön alla olevan esimerkin mukaisesti.
.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
    public:
        int id;
        string name;
    Employee(int a, string b){
        id = a;
        name = b;
    }    
};



int main() {
    vector<Employee> employees;
    int idCounter = 1;
    while (true)
    {
        string name;
        cout << "Anna työntekijän nimi (0 lopetus): ";
        getline(cin,name);
        if(name == "0"){
            break;
        }
        employees.push_back(Employee(idCounter,name));
        idCounter++;
    }

    for(int i = 0; i < idCounter - 1; i++){
        cout << "Id: " << employees[i].id << " Nimi: " << employees[i].name << endl;
    }
}