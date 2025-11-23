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
    char symbol;
public:
    Letter(char s)
    {
        symbol = s;
    }
    void outputTo() const
    {
        cout << "Символ: " << symbol << endl;
    }

    char get_symbol() const
    {
        return symbol;
    }

    void set_symbol(char s)
    {
        symbol = s;
    }
};

void printStack(stack<Letter> temp) {
    if (temp.empty()) {
        cout << "Стек пуст" << endl;
        return;
    }

    for (stack<Letter> sym = temp; !sym.empty(); sym.pop())
    {
        sym.top().outputTo();
    }
}

int main()
{
    string inputString;
    cout << "Введите строку: ";
    getline(cin, inputString);
    
    stack<Letter> allLetters;
    stack<Letter> lowcase;
    stack<Letter> bigcase;
    
    for (char symbol : inputString)
    {
        if (symbol == ' ') {continue;}
        allLetters.push(Letter(symbol));
        
        if (symbol >= 'a' && symbol <= 'z' ){
            lowcase.push(Letter(symbol));
        }
        else if (symbol >= 'A' && symbol <= 'Z') {
            bigcase.push(Letter(symbol));
        }
    }
    
    cout << "Все символы:" << endl;
    printStack(allLetters);
    cout << "Маленькие символы:" << endl;
    printStack(lowcase);
    cout << "Большие символы:" << endl;
    printStack(bigcase);
    
    return 0;
}