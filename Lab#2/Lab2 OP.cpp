#include "Lab1 v5.h"
using namespace std;

void saveToFile(int sessionNumber, const string& login, double a, double b, double stepen)
{
    ofstream file("results.txt", ios::app); // открываем файл для записи (app - добавление в конец файла)
    if (file.is_open())
    {
        file << "Session #" << sessionNumber++ << " " << login << endl;
        file << "a=" << a << ", b=" << b << ", stepen=" << stepen << endl;
        file << "------------------------" << endl;
        file.close();
        cout << "Результат сохранён в файл." << endl;
    }
    else
        cout << "Невозможно открыть файлы." << endl;
}

void loadAndPrintFile()
{
    ifstream file("results.txt");
    if (file.is_open())
    {
        cout << "----- Ранее сохраненные сессии -----" << endl;
        string line;
        while (getline(file, line))
            cout << line << endl;
        file.close();
        cout << "------------------------------------" << endl;
    }
    else
        cout << "Не найдено сохранённых сессий." << endl;
}

void clearFile()
{
    ofstream file("results.txt");
    file.close();
    cout << "Результат файла отчищен." << endl;
}

void searchByLogin(const string& query) // метод поиска по логину
{
    ifstream file("results.txt");
    if (file.is_open())
    {
        string line;
        bool found = false;
        int sessionLines = 0;
        cout << "Поисковой результат: " << query << endl;
        while (getline(file, line))
        {
            if (sessionLines > 0)
            {
                cout << line << endl;
                sessionLines--;
                continue;
            }
            if (line.find(query) != string::npos)
            {
                cout << line << endl;
                found = true;
                sessionLines = 2;
            }
        }
        if (!found)
            cout << "Результат не найден." << endl;
        file.close();
    }
    else cout << "Не найдено сохранённых сессий." << endl;
}

int main()
{
    int sessionNumber = 0, choice;
    string login, searchLogin;
    double stepen, a, b;
    setlocale(LC_ALL, "RUS");

    cout << "Введи логин без пробела: ";
    cin >> login;
    do
    {
        cout << "Ваш выбор:\n";
        cout << "1. Начать возведение числа 'a' в степень 'b'\n";
        cout << "2. Показать результат сохраненных сессий\n";
        cout << "3. Почистить файл\n";
        cout << "4. Поиск по логину\n";
        cout << "0. Выход\n";
        cin >> choice;

        char* str = new char[1024]; int i = -1;
        ifstream res("results.txt");
        while (!res.eof())
        {
            res.getline(str, 1024, '\n');
            ++i;
        }

        switch (choice)
        {
        case 1:
            cout << "Введите число: "; cin >> a;
            cout << "Введите степень: "; cin >> b;
            stepen = Header1(a, b);
            cout << "a ^ b = " << Header1(a, b) << endl;            
            sessionNumber = i/3+1;
            saveToFile(sessionNumber, login, a, b, stepen);
            break;
        case 2:
            loadAndPrintFile();
            break;
        case 3:
            clearFile();
            break;
        case 4:
            cout << "Введи логин для поиска: ";
            cin >> searchLogin;
            searchByLogin(searchLogin);
            break;
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуй ещё раз." << endl;
        }
    } while (choice != 0);
    return 0;
}