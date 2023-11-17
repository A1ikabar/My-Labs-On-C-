#include <iostream>
#include <windows.h>  
#include <string>
#include <fstream>

using namespace std;

class Magazine
{
	string name;
	int pages;
	double cost;
	int in_stock;
public:
	string Get_name()
	{
		return name;
	}
	int Get_pages()
	{
		return pages;
	}
	int Get_cost()
	{
		return cost;
	}
	int Get_in_stock()
	{
		return in_stock;
	}

	void Set_name(string nameS)
	{
		name = nameS;
	}

	void Set_pages(int pageS)
	{
		pages = pageS;
	}

	void Set_cost(int costS)
	{
		cost = costS;
	}
	void Set_in_stock(int in_stockS)
	{
		in_stock = in_stockS;
	}
public:
	// Конструктор по умолчанию
	Magazine()
	{
		name = "";
		pages = 0;
		cost = 0;
		in_stock = 0;
	}
	// Конструктор с параметрами
	Magazine(string nameP, int pageP, double costP, int in_stockP)//, int numberP, int markP)
	{
		name = nameP;
		pages = pageP;
		cost = costP;
		in_stock = in_stockP;
	}

	// Деструктор
	~Magazine()
	{

	}
	void ChangeName()
	{
		string Name_1;
		std::cout << "Введите название журнала: ";
		cin >> Name_1;
		name = Name_1;
	}

	void ChangePages()
	{
		int pages_1;
		std::cout << "Введите количество страниц: ";
		cin >> pages_1;
		pages = pages_1;
	}

	void ChangeCost()
	{
		double cost_1;
		std::cout << "Введите цену: ";
		cin >> cost_1;
		cost = cost_1;
	}
	void ChangeIn_stock()
	{
		int in_stock_1;
		std::cout << "Введите количество на складе: ";
		cin >> in_stock_1;
		in_stock = in_stock_1;
	}
};

void ClearFile();

void WriteFile(Magazine* magazine);

bool CheckChoice(string str);

void OutputObject(Magazine* magazine);

void ReadingFile(Magazine* magazine, string InsuranceMagazin);

void СhangeObject(Magazine* magazine);

int ConvertStringToInt(string str);

string ConvertFileString(string str);

void NewObject(Magazine * *magazine); 
#pragma once
