#include <iostream>
#include <fstream> // Для работы с файлами
#include "Header.h"
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;




int main() {
    //Русский язык
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_MAGAZINES = 10;
    Magazine magazines[MAX_MAGAZINES];
    int numMagazines = 0;
    int confirm; // переменная для подтверждения очистки файла
    loadMagazinesFromFile(magazines, numMagazines);
    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Заполнить информацию о журнале" << endl;
        cout << "2. Вывести информацию о журналах" << endl;
        cout << "3. Сохранить информацию в файл" << endl; // МОЖНО УДАЛИТЬ
        cout << "4. Загрузить информацию из файла" << endl; // МОЖНО УДАЛИТЬ
        cout << "6. Очистить файл" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (numMagazines < MAX_MAGAZINES) {
                Magazine newMagazine;
                string name;
                int pages, cost, in_stock;

                cout << "\nВведите название: ";
                cin.ignore();
                getline(cin, name);
                newMagazine.setName(name);

                cout << "Введите кол-во страниц: ";
                cin >> pages;
                newMagazine.setPages(pages);

                cout << "Введите цену: ";
                cin >> cost;
                newMagazine.setCost(cost);

                cout << "Введите количество на складе: ";
                cin >> in_stock;
                newMagazine.setStock(in_stock);

                if (magazines[numMagazines - 1].number >= 1 && magazines[numMagazines - 1].number <= MAX_MAGAZINES) {
                    newMagazine.setNumber(magazines[numMagazines - 1].number + 1);
                }
                else {
                    newMagazine.setNumber(1);
                }

                magazines[numMagazines] = newMagazine;
                numMagazines++;
                saveMagazinesToFile(magazines, numMagazines);
                cout << "Журнал добавлен.\n" << endl;
            }
            else {
                cout << "Достигнуто максимальное количество журналов." << endl;
            }
            break;
        }

        case 2: {
            for (int i = 0; i < numMagazines; i++) {
                magazines[i].displayInfo();
                cout << endl;
            }
            break;
        }

        case 3: {
            saveMagazinesToFile(magazines, numMagazines);
            break;
        }

        case 4: {
            loadMagazinesFromFile(magazines, numMagazines);
            break;
        }

        case 5: {
            int magazineIndex;
            cout << "\nВведите номер журнала для обновления информации (0-" << numMagazines - 1 << "): ";
            cin >> magazineIndex;

            if (magazineIndex >= 0 && magazineIndex < numMagazines) {
                Magazine& magazine = magazines[magazineIndex];

                int updateChoice;
                cout << "Меню обновления информации:" << endl;
                cout << "1. Изменить название" << endl;
                cout << "2. Изменить кол-во страниц" << endl;
                cout << "3. Изменить цену" << endl;
                cout << "4. Изменить кол-во в наличии" << endl;
                cout << "0. Выход из меню обновления в основное меню" << endl;
                cout << "Выберите действие: ";
                cin >> updateChoice;

                switch (updateChoice) {
                case 1: {
                    string name;
                    cout << "\nВведите новое название: ";
                    cin.ignore();
                    getline(cin, name);
                    magazine.setName(name);
                    break;
                }
                case 2: {
                    int pages;
                    cout << "Введите новое кол-во страниц: ";
                    cin.ignore();
                    cin >> pages;
                    magazine.setPages(pages);
                    break;
                }
                case 3: {
                    double cost;
                    cout << "Введите новую цену: ";
                    cin.ignore();
                    cin >> cost;
                    magazine.setCost(cost);
                    break;
                }

                case 4: {
                    int in_stock;
                    cout << "\nВведите новое кол-во на складе: ";
                    cin.ignore();
                    cin >> in_stock;
                    magazine.setStock(in_stock);
                    break;
                }

                case 0: {
                    cout << "\nВыйти из меню обновления информации." << endl;
                    break;
                }

                default: {
                    cout << "\nНеверное выбрано действие. Пожалуйста, попробуйте снова." << endl;
                    break;
                }
                }

                saveMagazinesToFile(magazines, numMagazines);
            }

            else {
                cout << "Неверный номер журнала." << endl;
            }
            break;
        }
        case 6: {
            cout << "Вы точно хотите очистить файл?\nВведите 1, если подтверждаете, либо 0, если хотите отменить очистку: ";
            cin >> confirm;

            if (confirm == 1) {
                clearFile(); // вызов функции
                cout << "Файл очищен" << endl;
                for (int i = 0; i < MAX_MAGAZINES; i++) {
                    // Очистка каждого элемента массива структур
                    magazines[i] = {}; // Присваивание пустого значения по умолчанию
                }

                Magazine magazines[MAX_MAGAZINES];
            }
            else if (confirm == 0) {
                cout << "Очистка отменена" << endl;
            }
            else {
                cout << "Введите 1 или 0" << endl;
            }
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }

        default: {
            cout << "Неверное выбрано действие. Пожалуйста, попробуйте снова." << endl;
            break;
        }
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
