// Magazine.cpp
#include "Header.h"
#include <iostream>
#include <fstream> // Для работы с файлами
#include <string>


using namespace std;

void Magazine::setNumber(int newNumber) {
    number = newNumber;
}

// Метод для изменения имени преподавателя
void Magazine::setName(string newName) {
    name = newName;
}

// Метод для изменения отчества преподавателя
void Magazine::setPages(int newPages) {
    pages = newPages;
}

// Метод для изменения предмета
void Magazine::setCost(double newCost) {
    cost = newCost;
}

// Метод для изменения возраста преподавателя
void Magazine::setStock(int newIn_stock) {
    in_stock = newIn_stock;
}

// Метод для вывода преподавателей из файла
void Magazine::displayInfo() {
    if (number == 0) {
        return;
    }
    cout << "\nПорядковый номер: " << number << endl;
    cout << "Название: " << name << endl;
    cout << "Страницы: " << pages << endl;
    cout << "Цена: " << cost << endl;
    cout << "В наличии: " << in_stock << endl;
}

// Метод для сохранения информации о преподавателях в файл
void saveMagazinesToFile(Magazine magazines[], int numMagazines) {
    ofstream file("magazines.txt");
    if (file.is_open()) {
        for (int i = 0; i < numMagazines; i++) {
            file << magazines[i].number << endl;
            file << magazines[i].name << endl;
            file << magazines[i].pages << endl;
            file << magazines[i].cost << endl;
            file << magazines[i].in_stock << endl;
        }
        file.close();
        cout << "Информация о журнале сохранена в файл." << endl;
    }
    else {
        cout << "Не удается открыть файл." << endl;
    }
}

// Метод для загрузки информации о преподавателях из файла
void loadMagazinesFromFile(Magazine magazines[], int& numMagazines) {
    ifstream file("magazines.txt");
    if (file.is_open()) {
        numMagazines = 0;
        string line;
        while (getline(file, line)) {
            magazines[numMagazines].number = stoi(line);
            getline(file, line);
            magazines[numMagazines].name = line;
            getline(file, line);
            magazines[numMagazines].pages = stoi(line);
            getline(file, line);
            magazines[numMagazines].cost = stoi(line);
            getline(file, line);
            magazines[numMagazines].in_stock = stoi(line);
            getline(file, line);
            numMagazines++;
        }
        file.close();
        cout << "Информация загружена из файла.\n" << endl;
    }
    else {
        cout << "Не удается открыть файл." << endl;
    }
}

// очистка файла
bool clearFile() {
    std::ofstream ofs; //переменная для очистки файла
    ofs.open("magazines.txt", std::ofstream::out | std::ofstream::trunc); // открытие файла для записи и очистки
    if (!ofs.is_open()) { //если не удалось открыть файл (файла нет или нет доступа)
        return false;
    }
    ofs.close();
    return true;
}
