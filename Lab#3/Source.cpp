#include "Header.h"
#include <iostream>

using namespace std;

void Magazine::input() {
    cout << "Name of Magazine: "; cin >> name;    
    cout << "Price of Magazine: "; cin >> price;   
    cout << "Number of pages: "; cin >> pages;
    cout << "In stock: "; cin >> in_stock;   
}

void Magazine::display() {
    cout << name << endl;
    cout  << price << endl;
    cout  << pages << endl;
    cout  << in_stock << endl;
}
