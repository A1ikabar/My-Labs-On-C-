#include "Header.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool check;
    string strReplay;
    string strMenu;
    Magazine* magazine = nullptr;
    string nameMagazine;

    cout << "Здравствуйте!" << endl << endl;
    cout << "Для начала работы программы нажмите 1." << endl;
    cout << "Для выхода из программы нажмите любую другую клавишу." << endl;
    cout << "Ввод: ";
    cin >> strReplay;
    cout << endl;
    check = CheckChoice(strReplay);

    if (check == false)
    {
        cout << "\nДо свидания!";
        return 0;
    }

    while (stoi(strReplay) == 1)
    {
        cout << "Для создания объекта нажмите 1." << endl;
        cout << "Для изменения уже созданного объекта нажмите 2." << endl;
        cout << "Для сохранения объекта в файл нажмите 3." << endl;
        cout << "Для загрузки объекта из файла нажмите 4. При этом текущий объект будет удалён!"
            << endl;
        cout << "Для очистки файла нажмите 5." << endl;
        cout << "Для закрытия программы нажмите любую другую клавишу." << endl;
        cout << "Ввод: ";
        cin >> strMenu;
        cout << endl;
        check = CheckChoice(strMenu);

        if (check == false)
        {
            cout << "\nДо свидания!";
            return 0;
        }

        switch (stoi(strMenu))
        {
        case 1:
            if (magazine != nullptr)
            {
                delete magazine;
                magazine = nullptr;
            }
            NewObject(&magazine);
            cout << endl;
            cout << "У вас получился следующий объект:" << endl;
            OutputObject(magazine);
            break;
        case 2:
            if (magazine == nullptr)
            {
                cout << "Объект не существует!" << endl;
                cout << endl;
                continue;
            }
            СhangeObject(magazine);
            cout << "У вас получилась следующий объект:" << endl;
            cout << endl;
            OutputObject(magazine);
            break;
        case 3:
            if (magazine == nullptr)
            {
                cout << "Объект не существует!" << endl;
                cout << endl;
                continue;
            }
            WriteFile(magazine);
            break;
        case 4:
            if (&magazine != nullptr)
            {
                delete magazine;
                magazine = nullptr;
            }
            cout << "Введите название журнала: ";
            cin >> nameMagazine;
            ReadingFile(magazine, nameMagazine);
            break;
        case 5:
            ClearFile();
            break;
        default:
            cout << "\nДо свидания!";
            return 0;
            break;
        }
    }
    cout << "\nДо свидания!";
}
