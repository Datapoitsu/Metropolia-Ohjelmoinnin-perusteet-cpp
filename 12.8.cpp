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
    virtual string getContract(){
        return "";
    }
    virtual int getHourlyRate(){
        return 0;
    }
    virtual int getHoursWorked(){
        return 0;
    }
    virtual int getCommission(){
        return 0;
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
    virtual string getContract(){
        return "h";
    }
    virtual int getHourlyRate(){
        return hour_rate;
    }
    virtual int getHoursWorked(){
        return hours_worked;
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
    virtual string getContract(){
        return "s";
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
    virtual string getContract(){
        return "c";
    }
    virtual int getCommission(){
        return commission;
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

class Employeelist
{
private:
    int id = 1;
public:
    PayrollSystem PS;
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
            cout << "(4) Tulosta palkkalaskelma" <<endl;
            cout << "(0) Lopeta" <<endl;
            cout << "Valitse toiminto: ";
            cin >> value;
            cout << endl;
            switch (value) 
            {
                case 1:
                    PalkkaTyyppi();
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
                    PS.CalculatePayroll(employees);
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

    void PalkkaTyyppi()
    {
        int value = 9;
        int quit = 0;
        string valueS = "";
        while(value != quit)
        {
            cout << "Palkkatyyppi" << endl;
            cout << "------------" << endl;
            cout << "(1) Kuukausi" << endl;
            cout << "(2) Tunti" << endl;
            cout << "(3) Komissio" << endl;
            cout << "(0) Lopeta" << endl;
            cout << "Valitse palkkatyyppi: ";
            //getline (cin,valueS);
            //value = stoi(valueS);
            cin >> value;
            cout << "Value " << value << endl;
            switch (value) 
            {
                case 1:
                    cout << 1 << endl;
                    cout << 2 << endl;
                    InsertMontly();
                    cout << 3 << endl;
                    break;
                case 2:
                    InsertHourly();
                    break;
                case 3:
                    InsertCommision();
                    break;
                case 0:
                    return;
                default:
                    cout << "Virheellinen valinta" << endl;
                    cout << endl;
                    break;
            }
        }
    }

    void InsertMontly()
    {
        cout << endl;
        string name;
        string salary;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cin.ignore();
        cin.clear();
        cout << "Anna kuukausipalkka: ";
        getline (cin,salary);
        cin.ignore();
        cin.clear();
        cout << "5 " << name << salary << endl;
        employees.push_back(new SalaryEmployee(id,name,stoi(salary)));
        id++;
    }

    void InsertHourly()
    {
        cout << endl;
        string name = " ";
        string quit = "0";
        string hour_rate,hours_worked;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cout << "Anna tuntipalkka: ";
        getline (cin,hour_rate);
        cout << "Anna tehdyt tunnit: ";
        getline (cin,hours_worked);
        employees.push_back(new HourlyEmployee(id,name,stoi(hour_rate),stoi(hours_worked)));
        id++;
    }

    void InsertCommision()
    {
        cout << endl;
        string name = " ";
        string quit = "0";
        string salary, commission;

        cout << "Anna työntekijän nimi: ";
        getline (cin,name);
        cout << "Anna kuukausipalkka: ";
        getline (cin,salary);
        cout << "Anna komissio: ";
        getline (cin,commission);
        employees.push_back(new CommissionEmployee(id,name,stoi(salary),stoi(commission)));
        id++;
    }

    void WriteToFile(vector<Employee *> employees)
    {
        string filename = "employee.csv";
        ofstream filu(filename);
        
        for(int i = 0; i < employees.size(); i++)
        {
            vector<string> data = {to_string(employees[i]->id),employees[i]->name,employees[i]->getContract()};
            cout << "Contract is " << employees[i]->getContract() << endl;
            if(employees[i]->getContract() == "s"){
                data.push_back(to_string(employees[i]->CalculateSalary()));
            }
            if(employees[i]->getContract() == "h"){
                data.push_back(to_string(employees[i]->getHourlyRate()));
                data.push_back(to_string(employees[i]->getHoursWorked()));
            }
            if(employees[i]->getContract() == "c"){
                data.push_back(to_string(employees[i]->CalculateSalary()));
                data.push_back(to_string(employees[i]->getCommission()));
            }
            string line = myjoin(data,',');
            filu << line << "\n";
        }
        
        filu.close();
        cout << employees.size() << " työntekijä(ä) lisätty tiedostoon " << filename;
    }

    void ReadFromFile()
    {
        string filename = "employee.csv";
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
            char sopimus = data[2][0];
            switch (sopimus)
            {
                case 's':
                {
                    int payment = stoi(data[3]);
                    employees.push_back(new SalaryEmployee(id,nimi,payment));
                }
                break;
                case 'c':
                {
                    int payment2 = stoi(data[3]);
                    int commission = stoi(data[4]);
                    employees.push_back(new CommissionEmployee(id,nimi,payment2,commission));
                }
                break;
                case 'h':
                {
                    int hour_rate = stoi(data[3]);
                    int hours_worked = stoi(data[4]);
                    employees.push_back(new HourlyEmployee(id,nimi,hour_rate,hours_worked));
                }
                break;
                default:
                    break;
            }
        }
        cout << employees.size() << " työntekijä(ä) luettu tiedostosta " << filename;
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
};

int main()
{
    Employeelist myList;
    myList.Menu();
    return 0;
}