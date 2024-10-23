/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Määrittele aluksi luokat
        PayrollSystem, jossa metodi CalculatePayroll, joka saa parametrinaan työntekijöiden vektorin. Metodi laskee ja tulostaa työntekijöiden palkat.
        SalaryEmployee, Employee-luokan aliluokka, jolla on oma attribuutti monthlysalary ja metodi CalculateSalary, joka palauttaa työntekijän kuukausipalkan.
        
    Kirjoita seuraavaksi pääohjelma,
        joka kysyy työntekijöiden nimet kuten Employee-tehtävässä sekä lisäksi kysyy SalaryEmployee-luokan kuukausipalkat luoden tietojen perusteella SalaryEmployee-oliot.
        jossa syntyneet SalaryEmployee-oliot viedään vektoriin.
        jossa käyttäjä lopettaa ohjelman suorittamisen antamalla '0' nimen sijasta.
        joka lopuksi PayrollSystem-luokan avulla tulostaa palkkalaskelmat kuten esimerkissä alla.

*/

#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    public:
        string name;
        Employee(string n){
            name = n;
        }
};

class SalaryEmployee : Employee
{
    public:
        float monthlysalary = 0;
        SalaryEmployee(float salary, string employeeName) : Employee(employeeName)
        {
            name = employeeName;
            monthlysalary = salary;
        }
        float CalculateSalary()
        {
            return monthlysalary;
        }
        string getName(){
            return name;
        }
};

class PayrollSystem
{
    public:
        void CalculatePayroll(vector<SalaryEmployee> employees)
        {
            for(int i = 0; i < employees.size(); i++){
                cout << "Palkkalaskelma\n==============\nHenkilölle: " << i + 1 << " - " << employees[i].getName() << "\n- Maksetaan: " << employees[i].CalculateSalary() << "\n\n";
            }
        }
};

int main()
{
    vector<SalaryEmployee> salaryEmploeyees;
    while (true)
    {
        string name;
        string payment;
        cout << "Anna työntekijän nimi (0 lopetus): ";
        getline (cin, name);
        if(name == "0"){
            break;
        }
        
        cout << "Anna kuukausipalkka: ";
        getline (cin, payment);
        
        SalaryEmployee s(stof(payment),name);
        salaryEmploeyees.push_back(s);
    }
    
    PayrollSystem PS;
    PS.CalculatePayroll(salaryEmploeyees);
    return 0;
}