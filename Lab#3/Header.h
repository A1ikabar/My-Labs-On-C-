#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <fstream> // Для работы с файлами
using namespace std;

struct Magazine {
    int number;
    string name;
    int pages;
    int cost;
    int in_stock;

    // Метод для присвоения порядкового номера
    void setNumber(int newNumber);

    // Метод для изменения названия журнала
    void setName(string newName);

    // Метод для изменения количества страниц
    void setPages(int newPages);

    // Метод для изменения цены журнала
    void setCost(double newCost);

    // Метод для изменения kol-va na sklade
    void setStock(int newIn_stock);

    // Метод для вывода журналов из файла
    void displayInfo();
};

void loadMagazinesFromFile(Magazine magazines[], int& numMagazines);
void saveMagazinesToFile(Magazine magazines[], int numMagazines);
bool clearFile();
#endif
