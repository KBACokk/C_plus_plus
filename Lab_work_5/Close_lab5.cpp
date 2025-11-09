#include <iostream>
#include <fstream>
#include <list>


using namespace std;

class HR {
    string Name;
    int WorkerCount;
    int HourPerMon;
    int PayPerHour;
    float TaxPay;
public:
    HR (string n, int wc, int hpm, int pph) {
        Name = n;
        WorkerCount = wc;
        HourPerMon = hpm;
        PayPerHour = pph;
        TaxPay = pph * hpm * wc * 0.13;
    }
    string getName () {
        return Name;
    }
    int getWorkCount () {
        return WorkerCount;
    }
    int getHourPerMon () {
        return HourPerMon;
    }
    int getPayPerHour () {
        return PayPerHour;
    }
    float getTaxPay () {
        return TaxPay;
    }

    void setName (string n) {
        Name = n;
    }
    void setWorkerCount (int wc) {
        WorkerCount = wc;
    }
    void setHourPerMon (int Hrm) {
        HourPerMon = Hrm;
    }
    void setPayPerHour (int ph) {
        PayPerHour = ph;
    }
    void setTaxPay (float tp) {
        TaxPay = tp;
    } 
    void information() {
        cout << " =============== Информация об объекте ============== " << endl;
        cout << " \x1b[32mНазвание предприятия: \x1b[0m" << Name << endl;
        cout << " \x1b[32mКоличество работкников:  \x1b[0m" <<  WorkerCount << endl;
        cout << " \x1b[32mНорма выработки часов в месяц: \x1b[0m" << HourPerMon << endl;
        cout << " \x1b[32mОплата за час: \x1b[0m" << PayPerHour << endl;
        cout << " \x1b[32mПодоходный налог: \x1b[0m" << TaxPay << endl;
        cout << " =====================================================" << endl;
    }
};

bool compareByCount( HR &a,  HR &b) {
    return a.getWorkCount() < b.getWorkCount();
}

int main () {
    cout << "Введите количество отделов -> ";
    int cnt;
    cin >> cnt;
    ifstream f("OK.txt");
    if (!f.is_open()) {
        cout << "Ошибка откытия файла" << endl;
        return 1;
    }
    list<HR> Offices;
    for (int i = 0; i < cnt; i++) {
        string name;
        int wc, hpm, pph;
        f >> name;
        f >> wc;
        f >> hpm;
        f >> pph;
        Offices.push_back(HR(name, wc, hpm, pph));
    }

    Offices.sort(compareByCount);

    for (HR Office : Offices) {
        Office.information();
    }
}
