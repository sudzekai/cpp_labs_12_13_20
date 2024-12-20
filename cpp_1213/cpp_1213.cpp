#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <format>

using namespace std;

//LABA 12

struct Student {
private:
    string _name;
    string _spec;
    string _course;
public:
    void Add(string name, string spec, string course) {
        _name = name;
        _spec = spec;
        _course = course;
    }

    void Print() {
        cout <<"ФИО: "<< _name << "\t|\tСпециальность: " << _spec << "\t|\tКурс: " << _course << endl;
    }

    string Get(string filter) {
        if (filter == "spec") {
            return _spec;
        }
        else if (filter == "course") {
            return _course;
        }
        else if (filter == "name") {
            return _name;
        }
    }
};

// LABA 13

struct Tempest {
protected:
    string _name;
    int _age;
    string _prof;
public:
    void Add(string name, int age, string prof) {
        _name = name;
        _age = age;
        _prof = prof;
    }

    string Get_name() {
        return _name;
    }

    int Get_age() {
        return _age;
    }

    string Get_prof() {
        return _prof;
    }

};

//LABA 13

void Lab13() {
    cout << "13 лабораторная работа" << endl << "1 задание: введите число n: ";
    int n;
    cin >> n;

    std::ofstream out;
    out.open("1.txt");
    if (out.is_open()) {
        for (int i = 0; i < n; i++) {
            out << rand() % 101 << " ";
        }
        out.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
        Lab13();
    }

    cout << endl << "2 задание: введите название файла (.txt): ";
    string filename;
    cin >> filename;
    std::ifstream in;
    in.open(filename+".txt");
    string text, tmp;
    int sum = 0;
    if (in.is_open()) {
        while (getline(in, text)) {
            for (int i = 0; i < text.length(); i++) {
                if (text[i] != ' ') {
                    tmp += text[i];
                }
                else {
                    sum += stoi(tmp);
                    tmp = "";
                }
            }
            
        }
        in.close();
        cout << sum << endl;
    }
    else {
        cout << "Файл не найден или открыть его невозможно" << endl;
        Lab13();
    }

    cout << endl << "3 задание: введите название файла (.txt): ";
    cin >> filename;
    Tempest tempest[3];

    string names[3]{ "Georgy", "Valentine", "Anna" };
    string profs[3]{ "Programmer", "Cassier", "Advicer" };

    for (int i = 0; i <3; i++) {
        tempest[i].Add(names[rand() % 3], rand() % 60, profs[rand() % 3]);\
    }

    out.open(filename + ".txt");
    if (out.is_open()) {
        for (int i = 0; i < 3; i++) {
            out << i+1 << "\n_name = " << tempest[i].Get_name() << "\n_age = " << tempest[i].Get_age() << "\n_prof = " << tempest[i].Get_prof() << endl;
        }
        out.close();
    }

    string line;
    in.open(filename + ".txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }


};

//LABA 12

int Lab12()
{

    Student students[5];
    string names[5] = { "Влад", "Настя", "Артемий", "Юрий", "София" };
    string specs[3] = { "ИСПП", "ИСПВ", "ОИБ" };
    string course[4] = { "1","2","3","4"};

    for (int i = 0; i < 5; i++) {
        students[i].Add(names[rand()%5], specs[rand() %3], course[rand() %4]);
    }

    for (int i = 0; i < 5; i++) {
        students[i].Print();
    }
    cout << endl;

    cout << "Поиск по специальности / специальности, курсу" << endl << endl;
    cout << "Список специальностей: ";
    for (int i = 0; i < 3; i++) {
        cout << specs[i] << " ";
    }
    cout << endl;

    string filter1, filter2;
    cout << "<специальность>: ";
    cin >> filter1;

    cout << "Студенты с указанной специальностью: \n";
    for (int i = 0; i < 5; i++) {
        if (students[i].Get("spec") == filter1) {
            students[i].Print();
        }
    }
    cout << endl;

    cout << "Список специальностей: ";
    for (int i = 0; i < 3; i++) {
        cout << specs[i] << " ";
    }
    cout << endl;

    cout << "Список курсов: ";
    for (int i = 0; i < 4; i++) {
        cout << course[i] << " ";
    }
    cout << endl;
    cout << "<специальность> <курс>: ";
    cin >> filter1 >> filter2;

    cout << "Студенты с указанной специальностью и курсом: \n";
    for (int i = 0; i < 5; i++) {
        if (students[i].Get("spec") == filter1) {
            if (students[i].Get("course") == filter2) {
                students[i].Print();
            }
        }
    }

    string name, spec, course1;
    cout << endl;
    cout << "Заполнение структуры: " << endl << endl;
    Student students1[3];
    for (int i = 0; i < 3; i++) {
        cout << "<имя> <специальность> <курс>: ";
        cin >> name >> spec >> course1;
        students[i].Add(name, spec, course1);
    }
    
    for (int i = 0; i < 3; i++) {
        students[i].Print();
    }
    return 1;
}
// LABA 20

class Time {
private:
    int _hours;
    int _minutes;
    int _seconds;

public:
    Time() {
        _hours = 12;
        _seconds = 00;
        _minutes = 00;
    }

    void Set(int hours = 12, int minutes = 0, int seconds = 0) {
        if (hours < 0) {
            _hours = 12;
            _minutes = minutes;
            _seconds = seconds;
        }
        else if (minutes > 59) {
            _hours = hours;
            _minutes = 0;
            _seconds = seconds;
        }
        else if (seconds > 59) {
            _hours = hours;
            _minutes = minutes;
            _seconds = 0;
        }
        else {
            _hours = hours;
            _minutes = minutes;
            _seconds = seconds;
        }
    }

    void Seconds(int seconds) {
        _hours = seconds / 60 / 60;
        _minutes = (seconds - _hours * 60 * 60) / 60;
        _seconds = seconds - _minutes * 60 - _hours*60*60;

    }

    int GetFullSeconds() {
        return _hours * 3600 + _minutes * 60 + _seconds;
    }
    
    int& operator[](const int index);

    const int& operator[](const int index) const;

    string ToString() {
        return format("{}:{}:{}", (to_string(_hours).length() == 1) ? "0" + to_string(_hours) : to_string(_hours), (to_string(_minutes).length() == 1) ? "0" + to_string(_minutes) : to_string(_minutes), (to_string(_seconds).length() == 1) ? "0" + to_string(_seconds) : to_string(_seconds));
        
    }
};


int& Time::operator[](const int index) {
    int i = -1;
    switch (index)
    {
    case 1:
        return _hours;
        break;
    case 2:
        return _minutes;
        break;
    case 3:
        return _seconds;
        break;
    default:
        return i;
        break;
    }
}

const int& Time::operator[](const int index) const {
    switch (index)
    {
    case 1:
        return _hours;
        break;
    case 2:
        return _minutes;
        break;
    case 3:
        return _seconds;
        break;
    default:
        return -1;
        break;
    }
}



void Lab20() {
    Time time;
    cout << "Basic constructor of Time.\nOutput: " << time.ToString() << endl << endl;
    time.Seconds(12108);
    cout << "ToString() of seconds(12108).\nOutput: " << time.ToString() << endl << endl;
    cout << "GetFullSeconds() of seconds(12108).\nOutput: " <<  time.GetFullSeconds() << endl << endl;
    cout << "Index: 1.\nOutput: " << time[1] << endl << endl;
    cout << "Index: 5.\nOutput: " << time[5] << endl << endl;

    Time time1[3];
    int hours, minutes, seconds;
    for (int i = 0; i < 3; i++) {
        cout << "Введите через пробел часы минуты секунды: ";
        cin >> hours >> minutes >> seconds;
        time1[i].Set(hours, minutes, seconds);
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout <<"time1["<<i<<"].\nOutput: "<< time1[i].ToString() << endl << endl;
    }
    int filter1, filter2;
    cout << "Введите два значения часов: ";
    cin >> filter1 >> filter2;
    cout << format("Choosed Time values where {} < _hours < {}.\nOutput: ", filter1, filter2);
    for (int i = 0; i < 3; i++) {
        if (time1[i][1] < filter2 && time1[i][1] > filter1) {
            cout << time1[i].ToString() << " ";
        }
    }
    cout << endl;

    cout << "Перегрузка оператора индексации:\nС помощью индексов нет возможности изменения константной версии класса Time" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    Lab12();
    Lab13();
    cout << endl;
    Lab20();

    
}
