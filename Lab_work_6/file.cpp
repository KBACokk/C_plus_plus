#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

class Questionnaire
{
private:
    int Age;
    string Gender;
    string Education;
    string Answer;

public:
    Questionnaire()
    {
        Age = 0;
        Gender = "Мужской";
        Education = "Среднее";
        Answer = "ДА";
    };

    Questionnaire(int A, string G, string E, string Ans)
    {
        Age = A;
        Gender = G;
        Education = E;
        Answer = Ans;
    }

    int get_Age()
    {
        return Age;
    }
    string get_Gender()
    {
        return Gender;
    }
    string get_Education()
    {
        return Education;
    }
    string get_Answer()
    {
        return Answer;
    }
    void set_Age(int A)
    {
        Age = A;
    }
    void set_Gender(string G)
    {
        Gender = G;
    }
    void set_Education(string E)
    {
        Education = E;
    }
    void set_Answer(string Ans)
    {
        Answer = Ans;
    }
    void OutInfo(){
        cout<<"Возраст: "<<Age<<endl;
        cout<<"Пол: "<<Gender<<endl;
        cout<<"Образование: "<<Education<<endl;
        cout<<"Ответ: "<<Answer<<endl<<endl;
    }
};

void view_deque(deque<Questionnaire> Questionnaires){
    for (auto iter = Questionnaires.begin(); iter != Questionnaires.end(); iter++)
        (*iter).OutInfo();
    cout << endl;
}

bool compareQuestionnaires(Questionnaire a, Questionnaire b) {
    return a.get_Gender() < b.get_Gender();
}

void analyze_questionnaires(deque<Questionnaire> Questionnaires){
    int count1 = 0, count2 = 0, count3 = 0;
    
    for (auto iter = Questionnaires.begin(); iter != Questionnaires.end(); iter++){
        string gender = (*iter).get_Gender();
        string education = (*iter).get_Education();
        string answer = (*iter).get_Answer();
        int age = (*iter).get_Age();
    
        if ((gender == "Мужской" || gender == "мужской" || gender == "муж") && 
            age > 40 && 
            (education == "Высшее" || education == "высшее") && 
            (answer == "ДА" || answer == "Да" || answer == "да")){
            count1++;
        }
        
        if ((gender == "Женский" || gender == "женский" || gender == "жен") && 
            age < 30 && 
            (education == "Среднее" || education == "среднее") && 
            (answer == "НЕТ" || answer == "Нет" || answer == "нет")){
            count2++;
        }
        
        if ((gender == "Мужской" || gender == "мужской" || gender == "муж") && 
            age < 25 && 
            (education == "Начальное" || education == "начальное") && 
            (answer == "ДА" || answer == "Да" || answer == "да")){
            count3++;
        }
    }
    
    cout << "Результаты анализа анкет:" << endl;
    cout << "а) Мужчин старше 40 лет с высшим образованием, ответивших ДА: " << count1 << endl;
    cout << "б) Женщин моложе 30 лет со средним образованием, ответивших НЕТ: " << count2 << endl;
    cout << "в) Мужчин моложе 25 лет с начальным образованием, ответивших ДА: " << count3 << endl << endl;
}



int main()
{
    deque<Questionnaire> Questionnaires;
    char addMore;
    
    do
    {
        cout << "Введите данные новой анкеты:" << endl;
        int A;
        string G, E, Ans;
        
        cout << "Возраст: ";
        cin >> A;
        cout << "Пол (Мужской/Женский): ";
        cin >> G;
        cout << "Образование (Начальное/Среднее/Высшее): ";
        cin >> E;
        cout << "Ответ (да/нет): ";
        cin >> Ans;
        
        Questionnaires.push_back(Questionnaire(A,G,E,Ans));
        cout<<"Добавить ещё анкету? (y/n)";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
    
    sort(Questionnaires.begin(), Questionnaires.end(), compareQuestionnaires);
    
    view_deque(Questionnaires);
    
    analyze_questionnaires(Questionnaires);
    
    return 0;
}