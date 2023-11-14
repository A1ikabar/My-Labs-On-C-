#include <iostream>
#include <fstream>
#include "Header.h"
#include <locale.h>
#include <windows.h>

using namespace std;

void saveToFile(const Magazine& magazine, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "NoM: " << magazine.name << endl;
        file << "PoM: " << magazine.price << endl;
        file << "NoP: " << magazine.pages << endl;
        file << "IS: " << magazine.in_stock << endl;
        file.close();
        cout << "Data saved into: " << filename << endl;
    }
    else {
        cout << "Opening ERROR: " << filename << endl;
    }
}

Magazine loadFromFile(const string& filename) {
    ifstream file(filename);
    Magazine magazine;
    if (file.is_open()) {
        file >> magazine.name;
        file >> magazine.price;
        file >> magazine.pages;
        file >> magazine.in_stock;
        file.close();
        cout << "Data upload from: " << filename << endl;
    }
    else {
        cout << "Opening ERROR: " << filename << endl;
    }
    return magazine;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Magazine magazine;
    magazine.input();

    cout << "NoF to save: ";
    string filename;
    cin >> filename;
    saveToFile(magazine, filename);

    cout << "NoF for upload: ";
    cin >> filename;
    Magazine loadedMagazine = loadFromFile(filename);

    loadedMagazine.display();

    return 0;
}
