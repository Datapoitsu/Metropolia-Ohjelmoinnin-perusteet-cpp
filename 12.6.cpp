/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tässä harjoituksessa SalaryEmployee -luokan oliot kirjoitetaan tiedostoon salary_employee.csv ja luetaan tiedostosta pilkuilla eroteltuina eli csv-muodossa.

    Ohjelmassa käytetään aikaisemmin rakennettuja omia myjoin ja mysplit -funktiota. 

    Ohjelman valikko kuten alla:

    Palkanlaskenta
    ==============
    (1) Lisää työntekijöitä
    (2) Kirjoita työntekijät tiedostoon
    (3) Lue työntekijät tiedostosta
    (4) Tulosta työntekijät
    (0) Lopeta

    Valikon valinnalla 1 luetaan työntekijöiden nimet ja palkat olioiden muuttujiin.

    Valikon valinnalla 2 kirjoitetaan kaikki oliot csv-tiedostoon.

    Valikon valinnalla 3 luetaan csv-tiedostosta oliot.

    Valikon valinnalla 4 tulostetaan oliot ja niiden arvot muodossa: Id: 1 Nimi: Maija Mainio Palkka: 5555.

    Valikon valinnalla 0 lopetetaan ohjelman suoritus.

    Sinun tehtävänä on kirjoittaa valikon valinnat 2 ja 3.

    

    Kirjoita työntekijät tiedostoon:

        varmista, että tiedosto salary_employee.csv on tyhjä 
        käy läpi työntekijät ja jokaiselle oliolle luo vektori, jonne olet lisännyt olion attribuutit merkkijonoina, tämä lista välitetään myjoin-funktiolle
        myjoin-funktion avulla vektorista muodostetaan yhtenäinen merkkijono (pilkulla eroteltuna), lisää rivinvaihto ja kirjoita merkkijono tiedostoon
        lisää loppuun koodi: cout << employees.size() << " työntekijä(ä) lisätty tiedostoon " << filename <<endl;

    Lue työntekijät tiedostosta:

        avaa tiedosto luettavaksi
        niin kauan kuin tiedostossa rivejä lue rivi kerrallaan
        muodosta mysplit -funktiolla tiedostosta luetusta merkkijonosta työntekijän attribuutit sisältävä merkkijonovektori
        luo SalaryEmployee -olio ja lisää se employees -vektoriin (huomioi että osa attribuuteista pitää muuttaa merkkijonosta numeroksi)
        lisää loppuun vielä koodi: cout << employees.size() << " työntekijä(ä) luettu tiedostosta " << filename <<endl;

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Employee
{
public:
    int id;
    string name;
    Employee(int id, string name) : id(id), name(name)
    {
    }
    virtual void Print()
    {
        cout << "Id: " << id << " Nimi: " << name <<endl;
    }
    virtual int CalculateSalary()
    {
        return 0;
    }
};

class SalaryEmployee : public Employee
{
    public:
    int monthly_salary;
    SalaryEmployee(int id, string name, int monthly_salary) : Employee(id, name), monthly_salary(monthly_salary)
    {
    }
    virtual void Print()
    {
        cout << "Id: " << id << " Nimi: " << name << " Palkka: " << monthly_salary <<endl;
    }
    virtual int CalculateSalary()
    {
        return monthly_salary;
    }
};


class Employeelist
{
public:
    vector<Employee*> employees;
    void Menu()
    {
        int value = 9;
        int quit = 0;

        while (value != quit)
        {
            cout << "Palkanlaskenta" <<endl;
            cout << "==============" <<endl;
            cout << "(1) Lisää työntekijöitä" <<endl;
            cout << "(2) Kirjoita työntekijät tiedostoon" <<endl;
            cout << "(3) Lue työntekijät tiedostosta" <<endl;
            cout << "(4) Tulosta työntekijät" <<endl;
            cout << "(0) Lopeta" <<endl;
            cout << "Valitse toiminto: ";
            cin >> value;
            cout << endl;
            switch (value) 
            {
                case 1:
                    cin.ignore();
                    Insert();
                    cout << endl;
                    break;
                case 2:
                    WriteToFile(employees);
                    cout << endl;
                    break;
                case 3:
                    ReadFromFile();
                    cout << endl;
                    break;
                case 4:
                    Print(employees);
                    cout << endl;
                    break;
                case 0:
                    break;
                default:
                    cout << "Virheellinen valinta" << endl;
                    cout << endl;
                    break;
            }
        }
    }

    void Insert()
    {
        string name = " ";
        string quit = "0";
        int id = 1, salary;

        while (name != quit)
        {
            cout << "Anna työntekijän nimi (0 lopetus): ";
            getline (cin,name);
            if (name != quit)
            {
                cout << "Anna kuukausipalkka: ";
                cin >> salary;
                employees.push_back(new SalaryEmployee(id,name,salary));
                id++;
                cin.ignore();
            }
        }
    }

    // Put your code here
    void WriteToFile(vector<Employee *> employees)
    {
        string filename = "salary_employee.csv";
        ofstream filu(filename);
        
        for(int i = 0; i < employees.size(); i++)
        {
            vector<string> data = {to_string(employees[i]->id),employees[i]->name,to_string(employees[i]->CalculateSalary())};
            string line = myjoin(data,',');
            filu << line << "\n";
        }
        
        filu.close();
        cout << employees.size() << " työntekijä(ä) lisätty tiedostoon " << filename <<endl;
    }

    void ReadFromFile()
    {
        string filename = "salary_employee.csv";
        ifstream filu(filename);

        string line;
        while(getline(filu,line))
        {
            vector<string> data = mysplit(line,',');
            int id = stoi(data[0]);
            bool match = false;
            for(int i = 0; i < employees.size(); i++){
                if(employees[i]->id == id){
                    match = true;
                    break;
                }
            }
            if(match){
                continue;
            }
            string nimi = data[1];            
            int payment = stoi(data[2]);
            employees.push_back(new SalaryEmployee(id,nimi,payment));
        }

        cout << employees.size() << " työntekijä(ä) luettu tiedostosta " << filename <<endl;
    }

    vector<string> mysplit(string sentence, char sep)
    {
        vector<string> parts;
        int start = 0;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == sep)
            {
                parts.push_back(sentence.substr(start, i - start));
                start = i + 1;
            }
        }
        parts.push_back(sentence.substr(start, sentence.size() - start));
        return parts;
    }

    string myjoin(vector<string> lst, char sep)
    {
        string result = lst[0];
        for(int i = 1; i < lst.size(); i++){
            result = result + sep + lst[i];
        }
        return result;
    }

    void Print(vector<Employee*> employees)
    {
        for(int i=0;i<employees.size();i++)
        {
            employees[i]->Print();
        }
    }
};

int main()
{
    Employeelist myList = *new Employeelist();
    myList.Menu();
    return 0;
}