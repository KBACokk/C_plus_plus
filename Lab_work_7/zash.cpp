#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <ctime>
#include <algorithm>
using namespace std;

class Letter {
private:
    int symbol;
public:
    Letter(int s)
    {
        symbol = s;
    }
    void outputTo() const
    {
        cout << "Символ: " << symbol << endl;
    }

    int get_symbol() const
    {
        return symbol;
    }

    void set_symbol(int s)
    {
        symbol = s;
    }
};

void printStack(stack<Letter> temp, int comp) {
    if (temp.empty()) {
        cout << "Стек с числами более" << comp << "нету";
        return;
    }

    for (stack<Letter> sym = temp; !sym.empty(); sym.pop())
    {
        sym.top().outputTo();
    }
}

int main()
{
    stack<Letter> bigcase;
    int temp;
    int num;
    cout <<"Введите символ для сравнения -> ";
    cin >> temp;
    do
    {
        cout<<"Число -> ";
        cin>> num;
        if (num > temp) {
            bigcase.push(Letter(num));
        }
    } while (num != 0);
    
    cout << "Все символы, что больше " << temp << endl;
    printStack(bigcase, temp);
    
    return 0;
}
