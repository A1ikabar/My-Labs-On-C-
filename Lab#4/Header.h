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
	string Get_name();

	int Get_pages();

	int Get_cost();

	int Get_in_stock();

	void Set_name(string nameS);

	void Set_pages(int pageS);

	void Set_cost(int costS);

	void Set_in_stock(int in_stockS);

	// Конструктор по умолчанию
	Magazine();

	// Конструктор с параметрами
	Magazine(string nameP, int pageP, double costP, int in_stockP);



	void ChangeName();

	void ChangePages();

	void ChangeCost();

	void ChangeIn_stock();
};

void ClearFile();

void WriteFile(Magazine* magazine);

bool CheckChoice(string str);

void OutputObject(Magazine* magazine);

void ReadingFile(Magazine* magazine, string InsuranceMagazin);

void СhangeObject(Magazine* magazine);

int ConvertStringToInt(string str);

string ConvertFileString(string str);

void NewObject(Magazine** magazine);
#pragma once
