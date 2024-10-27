/*
    Kirjoittanut Aarni Junkkala
    Tehtävänanto:
    Tässä harjoituksessa laajennetaan Employee-luokkaa kahdella aliluokalla HourlyEmployee ja CommissionEmployee.

    Määrittele Employee-luokan aliluokka: HourlyEmployee (Tuntityöntekijä) 

        Kirjoita metodi AskSalary, jonka avulla kysytään työntekijän tuntipalkka (hour_rate) sekä tehdyt tunnit (hours_worked).
        Kirjoita metodi CalculateSalary, joka palauttaa palkan: tuntipalkka (hour_rate) * tehdyt tunnit (hours_worked).

    Määrittele SalaryEmployee-luokan aliluokka: CommissionEmployee (Komissiotyöntekijä).

        Kirjoita metodi AskSalary, jonka avulla kysytään komissio (commission)
        Kirjoita metodi CalculateSalary, joka palauttaa palkan: kuukausipalkka (monthly_salary) + komissio (commission)

    Palkkalaskelma tulostetaan tuttuun tapaan käyttämällä luokkaa PayrollSystem.
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
    string getName()
    {
        return name;
    }
};

class HourlyEmployee : public Employee
{
    public:
    int hour_rate,hours_worked;
    HourlyEmployee(int id, string name, int hour_rate, int hours_worked) : Employee(id,name), hour_rate(hour_rate), hours_worked(hours_worked)
    {
    }
    void AskSalary(){
        cout << "Anna työntekijän nimi: ";
        cin >> name;
        cout << "Anna tuntipalkka: ";
        cin >> hour_rate;
        cout << "Anna tehdyt tunnit: ";
        cin >> hours_worked;
    }
    virtual int CalculateSalary(){
        return hour_rate * hours_worked;
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

class CommissionEmployee : public SalaryEmployee
{
    public:
    int commission;
    CommissionEmployee(int id, string name, int monthly_salary, int commission) : SalaryEmployee(id,name,monthly_salary),commission(commission)
    {
    }
    void AskSalary(){
        cout << "Anna työntekijän nimi: ";
        cin >> name;
        cout << "Anna kuukausipalkka: ";
        cin >> monthly_salary;
        cout << "Anna komissio: ";
        cin >> commission;
    }
    virtual int CalculateSalary(){
        return monthly_salary + commission;
    }
};

class Employeelist
{
private:
    int id = 1;
public:
    
    vector<Employee*> employees;

    void PalkkaTyyppi()
    {
        int value = 9;
        int quit = 0;
        while(value != quit)
        {
            cout << "Palkkatyyppi" << endl;
            cout << "------------" << endl;
            cout << "(1) Kuukausi" << endl;
            cout << "(2) Tunti" << endl;
            cout << "(3) Komissio" << endl;
            cout << "(0) Lopeta" << endl;
            cout << "Valitse palkkatyyppi: ";
            cin >> value;
            cout << endl;
            switch (value) 
            {
                case 1:
                    cin.ignore();
                    InsertMontly();
                    break;
                case 2:
                    cin.ignore();
                    InsertHourly();
                    break;
                case 3:
                    cin.ignore();
                    InsertCommision();
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

    void InsertMontly()
    {
        string name = " ";
        string quit = "0";
        int salary,commission;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cout << "Anna kuukausipalkka: ";
        cin >> salary;
        employees.push_back(new SalaryEmployee(id,name,salary));
        id++;
        cin.ignore();
    }

    void InsertHourly()
    {
        string name = " ";
        string quit = "0";
        int hour_rate,hours_worked;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cout << "Anna tuntipalkka: ";
        cin >> hour_rate;
        cout << "Anna tehdyt tunnit: ";
        cin >> hours_worked;
        employees.push_back(new HourlyEmployee(id,name,hour_rate,hours_worked));
        id++;
        cin.ignore();
    }

    void InsertCommision()
    {
        string name = " ";
        string quit = "0";
        int salary, commission;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cout << "Anna kuukausipalkka: ";
        cin >> salary;
        cout << "Anna komissio: ";
        cin >> commission;
        employees.push_back(new CommissionEmployee(id,name,salary,commission));
        id++;
        cin.ignore();
    }
};

class PayrollSystem
{
    public:
        void CalculatePayroll(vector<Employee*> employees)
        {
            for(int i = 0; i < employees.size(); i++){
                cout << "Palkkalaskelma\n==============\nHenkilölle: " << i + 1 << " - " << employees[i]->getName() << "\n- Maksetaan: " << employees[i]->CalculateSalary() << "\n\n";
            }
        }
};

int main()
{
    Employeelist myList;
    myList.PalkkaTyyppi();
    PayrollSystem PS;
    PS.CalculatePayroll(myList.employees);
    return 0;
}