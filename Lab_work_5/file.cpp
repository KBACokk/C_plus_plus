#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

class file {
    int rooms_count;
    int area;
    string address;
    int start;
    int finish;
public:
    file (int r, int a, string ad, int st, int fin) {
        rooms_count = r;
        area = a;
        address = ad;
        start = st;
        finish = fin;
    }

    int getRooms_count () { 
        return rooms_count; 
    }
    int getArea () {
        return area;
    }
    string getAddress () {
        return address;
    }

    int getStart () {
        return start;
    }
    int getFinish () {
        return finish;
    }

    void setRooms_count (int r) {
        rooms_count = r;
    }

    void setArea ( int a) {
        area = a;
    } 

    void setAddress (string ad) {
        address = ad;
    }

    void setStart ( int st) {
        start = st;
    }

    void setFinish (int f) {
        finish = f;
    }
    

    void information() {
        list<string> mounths = {
        " Январь", " Февраль", " Март", " Апрель", " Май", " Июнь", " Июль", " Август", " Сентябрь", " Октябрь", " Ноябрь", " Декабрь"
        };
        cout << " =============== Информация об объекте ============== " << endl;
        cout << " \x1b[32mКоличество комнат: \x1b[0m" << rooms_count << endl;
        cout << " \x1b[32mПлощадь помещения: \x1b[0m" <<  area << endl;
        cout << " \x1b[32mАдрес объекта:     \x1b[0m" << address << endl;
        cout << " \x1b[32mДата начала работ: \x1b[0m" << start << endl;
        cout << " \x1b[32mПредположительная дата окончания работ: \x1b[0m" << finish << endl;
        cout << " =====================================================" << endl;
    }
};

bool compareByFinish(file& a, file& b) {
    return a.getFinish() < b.getFinish();
}

void printInfo (list<file> objects, string title) {
    cout << title << endl;
    if (objects.empty()) {
        cout << "Спискок пуст" << endl;
        return;
    }
    for (file obj : objects) {
        obj.information();
    }
}

void newWrite (list<file> &obj, int N, int aut) {
    list<string> addresses = {
        "ул. Ленина, д. 15", "пр. Мира, д. 28", "ул. Советская, д. 7", 
        "ул. Пушкина, д. 42", "пр. Гагарина, д. 13", "ул. Садовая, д. 21",
        "ул. Центральная, д. 5", "пр. Ленинградский, д. 34", "ул. Школьная, д. 18",
        "ул. Лесная, д. 9", "пр. Победы, д. 27", "ул. Новая, д. 12",
        "ул. Заречная, д. 33", "пр. Строителей, д. 16", "ул. Молодежная, д. 24",
        "ул. Набережная, д. 11", "пр. Комсомольский, д. 39", "ул. Парковая, д. 6",
        "ул. Строительная, д. 19", "пр. Кирова, д. 45"
    };

    for (int i = 0; i < N; i++) {
        int rooms, area, start, finish;
        string address;

        if (aut == 'y' || aut == 'Y') {
            rooms = rand() % 5 + 1;
            area = rooms * 6 + rand() % 10;
            auto addresses_list = addresses;
            auto it = addresses_list.begin();
            advance(it, rand() % addresses_list.size());
            address = *it;
            start = rand() % 15 + 1;
            finish = start + rand() % 12;

            obj.push_back(file(rooms, area, address, start, finish));
        }
        else {
            cout << "введите количество комнат -> ";
            cin >> rooms;
            cout << "Введите площадь помещения -> ";
            cin >> area;
            cout << "Введите адрес здания -> ";
            cin.ignore();
            getline(cin, address);
            cout << "Введите дату подачи заявления -> ";
            cin >> start;
            cout << "Введите предполагаемую дату окончания заявки -> ";
            cin >> finish;

            obj.push_back(file(rooms, area, address, start, finish));
        }
    }
}

void transferToClosed(list<file>& Office, list<file>& Closed) {
    auto it = Office.begin();
    while (it != Office.end()) {
        if (it->getFinish() > 15) {
            Closed.push_back(*it);
            it = Office.erase(it);
        } else {
            ++it;
        }
    }
    
    Office.sort(compareByFinish);
    Closed.sort(compareByFinish);
}

void transferSelect(list<file>& Office, list<file>& Closed) {
    if (Office.empty()) {
        cout << "Список пуст, нечего переносить " << endl;
        return;
    }
    
    cout << "Введите номер записи для переноса в Closed (1-" << Office.size() << ") ->  ";
    int selected;
    cin >> selected;

    if (selected < 1 || selected > Office.size()) {
        cout << "Неверный номер записи!" << endl;
        return;
    }
    
    auto it = Office.begin();
    advance(it, selected - 1);
    
    cout << "Вы выбрали запись:" << endl;
    it->information();
    cout << "\x1b[1;31mОбъект закрыт \x1b[0m" << endl;
    
    Closed.push_back(*it);
    Office.erase(it);
    
    Office.sort(compareByFinish);
    Closed.sort(compareByFinish);
} 

int main() {
    srand(time(NULL));
    list<file> Office;
    list<file> Closed;

    char autolist = 'y';
    char add = 'y';
    cout << "Вы хотите внести автоматически записи? (y/n) ";
    cin >> autolist;
    do {
        cout <<  "Сколько новых записей вы хотите внести? ";
        int cnt;
        cin >> cnt;
        newWrite (Office, cnt, autolist);
        cout << "Вы хотите внести ещё записей? (y/n)" << endl;
        cin >> add;
        if (add == 'y' || add == 'Y') {
            cout << "Вы хотите внести автоматически записи? (y/n) ";
            cin >> autolist;
        }
    } while (add == 'y' || add == 'Y');

    Office.sort(compareByFinish);

    printInfo (Office, "====================== Начальный список записей =======================");

    char del = 'y';
    while (del == 'y' || del == 'Y') {
        transferSelect(Office, Closed);
        cout << "Вы хотите перенести ещё запись? (y/n)" << endl;
        cin >> del;
    }

    printInfo (Office, "\x1b[1;33m====================== Список оставшихся объектов =======================\x1b[0m\n");
    printInfo (Closed, "\x1b[1;33m====================== Список завёршенных объектов =======================\x1b[0m\n");

    return 0;
}
