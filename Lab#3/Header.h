#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <string>

struct Magazine {
    std::string name;
    double price;
    int pages;
    int in_stock;

    void input();  // input method
    void display();  // output method
};

#endif
