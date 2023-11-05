
#include <iostream>
#include "Header1.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    double a, b;
    int Cn = 1;
    do {
        cout << "Введите число: "; cin >> a;
        cout << "Введите степень: "; cin >> b;
        cout << Header1(a, b);
        cout << "\nДля продолжения введите 1.\nДля выхода введите любое другое число." << endl;
        cin >> Cn;
    } while (Cn == 1);
    return 0;
}