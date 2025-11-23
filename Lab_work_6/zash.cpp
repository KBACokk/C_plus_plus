#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <random>
#include <time.h>
#include <vector>
using namespace std;

class Magazine
{
private:
    int cost;
    string name;
    int buy_count;
public:
    Magazine(int c, string n, int cnt)
    {
        cost = c;
        name = n;
        buy_count = cnt;
    }

    int getCost () {
        return cost;
    }
    string getName () {
        return name;
    }
    int getBuy_count () {
        return buy_count;
    }
    void setCost (int c) {
        cost = c;
    }
    void setName (string n) {
        name = n;
    }
    void setBuy_count (int bc) {
        buy_count = bc;
    }
    int getRevenue () {
        return cost * buy_count;
    }

    void OutInfo(){
        cout <<  "-------------------------" << endl;
        cout<<"Название товара: "<<name<<endl;
        cout<<"Цена товара: "<<cost<<endl;
        cout<<"Число покупок: "<<buy_count<<endl;
        cout<<"Итоговая выручка: "<< cost * buy_count <<endl;

    }
};

void view_deque(deque<Magazine> Questionnaires){
    for (auto iter = Questionnaires.begin(); iter != Questionnaires.end(); iter++)
        (*iter).OutInfo();
    cout << endl;
}

bool compareMagazines(Magazine a, Magazine b) {
    return a.getRevenue() < b.getRevenue();
}


int main()
{
    vector<string> productNames = {
        "Смартфон Samsung Galaxy",
        "Ноутбук ASUS ZenBook",
        "Кофеварка автоматическая",
        "Беспроводные наушники",
        "Электрический чайник",
        "Микроволновая печь",
        "Фитнес-браслет Xiaomi",
        "Игровая консоль PlayStation",
        "Цифровой фотоаппарат",
        "Умные часы Apple Watch",
        "Пылесос робот",
        "Электронная книга",
        "Монитор 27 дюймов",
        "Компьютерная мышь",
        "Механическая клавиатура",
        "Внешний жесткий диск",
        "Электрическая зубная щетка",
        "Увлажнитель воздуха",
        "Блендер стационарный",
        "Мультиварка REDMOND",
        "Электросамокат",
        "Пауэрбанк 20000 mAh",
        "Умная колонка Яндекс",
        "Электрическая бритва",
        "Проектор домашний"
    };
    srand(time(NULL));
    deque<Magazine> Magazines;
    char addMore;
    
    do
    {
        char aut;
        cout << "ввести данные автоматически? (y/n)" << endl;
        cin >> aut;
        cout << "Сколько записей вы хотите внести? " << endl;
        int count = 0;
        cin>>count;
        if (aut == 'y' || aut == 'Y') {
            for (int i = 0; i < count; i++)
            {
                Magazines.push_back(Magazine(rand()%100, productNames[rand()%sizeof(productNames)], rand()%500));
            }
            
        }
        else {
        cout << "Введите данные новой анкеты:" << endl;
        int temp_cost, temp_buy_count;
        string temp_name;
        
        cout << "Введите название товара: ";
        cin >> temp_name;
        cout << "Введите цену товара: ";
        cin >> temp_cost;
        cout << "Введите число покупок: ";
        cin >> temp_buy_count;
        
        Magazines.push_back(Magazine(temp_cost, temp_name, temp_buy_count));
        cout<<"Добавить ещё анкету? (y/n)";
        cin >> addMore;
        }
    } while (addMore == 'y' || addMore == 'Y');
    
    sort(Magazines.begin(), Magazines.end(), compareMagazines);
    
    view_deque(Magazines);
    
    return 0;
}