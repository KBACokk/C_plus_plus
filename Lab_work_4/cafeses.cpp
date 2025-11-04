#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class kafe
{
private:
    string name;
    string address;
    string workingTime;
    int profit;

public:
    kafe(string n = "", string a = "", string w = "", int p = 0)
    {
        name = n;
        address = a;
        workingTime = w;
        profit = p;
    }
    
    void information() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "Название: " << name << endl;
        cout << "Адрес: " << address << endl;
        cout << "Время работы: " << workingTime << endl;
        cout << "Среднесуточный доход: " << profit << " руб." << endl;
        cout << "---------------------------------------------" << endl;
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

    string getWorkingTime() const
    {
        return workingTime;
    }

    int getProfit() const
    {
        return profit;
    }

    void setName(string n)
    {
        name = n;
    }

    void setAddress(string a)
    {
        address = a;
    }

    void setWorkingTime(string t)
    {
        workingTime = t;
    }

    void setProfit(int p)
    {
        profit = p;
    }
    
    bool isProfitMore500k() const {
        return profit > 500000;
    }
};

void printInformation(const vector<kafe> &cafes, const string &title)
{
    cout << title << endl;
    if (cafes.empty())
    {
        cout << "Список пуст!" << endl;
        return;
    }
    for (int i = 0; i < (int)cafes.size(); ++i)
    {
        cafes[i].information();
    }
}

bool compareByProfit(const kafe &a, const kafe &b)
{
    return a.getProfit() < b.getProfit();
}

void insertSorted(vector<kafe> &cafes, const kafe &newCafe)
{
    int position = 0;
    while (position < cafes.size() && cafes[position].getProfit() < newCafe.getProfit())
    {
        position++;
    }
    cafes.insert(cafes.begin() + position, newCafe);
}

int main()
{
    int n;
    system("chcp 65001 >> nul");
    cout << "Введите количество кофеен для чтения из файла: ";
    cin >> n;
    cin.ignore();
    
    ifstream f("kofe.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла kofe.txt!" << endl;
        return 1;
    }
    
    vector<kafe> allCafes;
    vector<kafe> highProfitCafes;
    
    for (int i = 0; i < n; i++)
    {
        string name, address, workingTime;
        int profit;
        
        if (!getline(f, name)) break;
        if (!getline(f, address)) break;
        if (!getline(f, workingTime)) break;
        if (!(f >> profit)) break;
        f.ignore();
        
        kafe newCafe(name, address, workingTime, profit);
        allCafes.push_back(newCafe);
        
        if (newCafe.isProfitMore500k())
        {
            highProfitCafes.push_back(newCafe);
        }
    }
    f.close();

    ofstream f_out("kofe.txt", ios::app);
    char addMore;
    do
    {
        string name, address, workingTime;
        int profit;

        cout << "Введите данные новой кофейни:" << endl;
        cout << "Название: ";
        getline(cin, name);
        cout << "Адрес: ";
        getline(cin, address);
        cout << "Время работы: ";
        getline(cin, workingTime);
        cout << "Среднесуточный доход: ";
        cin >> profit;
        cin.ignore();

        kafe newCafe(name, address, workingTime, profit);
        
        if (newCafe.isProfitMore500k())
        {
            insertSorted(highProfitCafes, newCafe);
            cout << "Кофейня добавлена в список высокодоходных!" << endl;
            f_out << endl;
            f_out << name << endl;
            f_out << address << endl;
            f_out << workingTime << endl;
            f_out << profit << endl;
        }
        else
        {
            cout << "Кофейня не попадает в категорию высокодоходных!" << endl;
        }

        cout << "Добавить еще одну кофейню? (y/n): ";
        cin >> addMore;
        cin.ignore();

    } while (addMore == 'y' || addMore == 'Y');
    
    f_out.close();
    
    printInformation(highProfitCafes, "================================Список кофеен с доходом более 500k===============================");
    sort(highProfitCafes.begin(), highProfitCafes.end(), compareByProfit);
    printInformation(highProfitCafes, "================================Упорядоченный список кофеен с доходом более 500k================================");

    return 0;
}