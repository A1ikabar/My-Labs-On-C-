#include "Header.h"

using namespace std;

string Magazine::Get_name()
{
	return name;
}
int Magazine::Get_pages()
{
	return pages;
}
int Magazine::Get_cost()
{
	return cost;
}
int Magazine::Get_in_stock()
{
	return in_stock;
}

void Magazine::Set_name(string nameS)
{
	name = nameS;
}
void Magazine::Set_pages(int pageS)
{
	pages = pageS;
}
void Magazine::Set_cost(int costS)
{
	cost = costS;
}
void Magazine::Set_in_stock(int in_stockS)
{
	in_stock = in_stockS;
}

Magazine::Magazine()
{
	name = "";
	pages = 0;
	cost = 0;
	in_stock = 0;
}
// Конструктор с параметрами
Magazine::Magazine(string nameP, int pageP, double costP, int in_stockP)//, int numberP, int markP)
{
	name = nameP;
	pages = pageP;
	cost = costP;
	in_stock = in_stockP;
}



void Magazine::ChangeName()
{
	string Name_1;
	std::cout << "Введите название журнала: ";
	cin >> Name_1;
	name = Name_1;
}

void Magazine::ChangePages()
{
	int pages_1;
	std::cout << "Введите количество страниц: ";
	cin >> pages_1;
	pages = pages_1;
}

void Magazine::ChangeCost()
{
	double cost_1;
	std::cout << "Введите цену: ";
	cin >> cost_1;
	cost = cost_1;
}
void Magazine::ChangeIn_stock()
{
	int in_stock_1;
	std::cout << "Введите количество на складе: ";
	cin >> in_stock_1;
	in_stock = in_stock_1;
}

void ReadingFile(Magazine* magazine, string InsuranceMagazine)

{
	magazine = new Magazine();
	bool check = false;
	ifstream ifFile;
	string str;
	bool checkTrainInFile = false;
	ifFile.open("Laboratory4.txt");
	if (ifFile.is_open())
	{
		getline(ifFile, str);
		if (str == "")
		{
			std::cout << "Файл пуст!" << endl;
			return;
		}

		do
		{
			if (str.find(InsuranceMagazine) != -1)
			{
				checkTrainInFile = true;
				std::cout << str << endl;
				magazine->Set_name(InsuranceMagazine);
				getline(ifFile, str);
				std::cout << str << endl;
				magazine->Set_pages(ConvertStringToInt(str));
				getline(ifFile, str);
				std::cout << str << endl;
				magazine->Set_cost(ConvertStringToInt(str));
				getline(ifFile, str);
				std::cout << str << endl;
				magazine->Set_in_stock(ConvertStringToInt(str));
				getline(ifFile, str);
				std::cout << str << endl;
				break;
			}
			getline(ifFile, str);
		} while (!ifFile.eof());

		if (!checkTrainInFile)
		{
			std::cout << "Журнала с таким названием не существует!" << endl << endl;
		}
	}
}

void ClearFile()
{
	ofstream file;
	file.open("laboratory4.txt");
	if (file.is_open())
	{
		std::cout << "Файл отчищен!" << endl << endl;
	}
	file.close();
}

void NewObject(Magazine** magazine)
{
	string nameS;
	int pageS;
	int costS;
	int in_stockS;

	char chOnTrip;

	std::cout << "Введите название журнала: ";
	cin >> nameS;
	std::cout << "Введите количество страниц журнала: ";
	cin >> pageS;
	std::cout << "Введите цену: ";
	cin >> costS;
	std::cout << "Введите количество на складе: ";
	cin >> in_stockS;

	*magazine = new Magazine(nameS, pageS, costS, in_stockS); //, numberS, markS);
}

void OutputObject(Magazine* magazine)
{
	std::cout << "Название журнала: " << magazine->Get_name() << endl;
	std::cout << "Количество страниц: " << magazine->Get_pages() << endl;
	std::cout << "Цена: " << magazine->Get_cost() << endl;
	std::cout << "Количество на складе: " << magazine->Get_in_stock() << endl;
	std::cout << endl;
}

void СhangeObject(Magazine* magazine)
{
	int element;
	std::cout << "Выберите элемент которому хотели бы поменять значение: " << endl;
	std::cout << "Количество страниц - нажмите 1." << endl;
	std::cout << "Название журнала - нажмите 2." << endl;
	std::cout << "Цену - нажмите 3." << endl;
	std::cout << "Количество на складе - нажмите 4." << endl;
	std::cout << "Для отмены нажмите на клавишу с любым другим числом." << endl;
	std::cout << "Ввод: ";
	cin >> element;

	switch (element)//Изменение выбранной части структуры
	{
	case 1:
		magazine->ChangePages();
		std::cout << "Характеристика компании изменена!" << endl;
		break;
	case 2:
		magazine->ChangeName();
		std::cout << "Характеристика компании изменена!" << endl;
		break;
	case 3:
		magazine->ChangeCost();
		std::cout << "Характеристика компании изменена!" << endl;
		break;
	case 4:
		magazine->ChangeIn_stock();
		std::cout << "Характеристика компании изменена!" << endl;
		break;
	default:
		std::cout << "Изменений не произведено!" << endl;
		break;
	}
	std::cout << endl;
}

void WriteFile(Magazine* magazine)
{
	ifstream fileIf;
	string counterStr;
	int quantitystr = 0;
	int i;
	int counter = 0;
	fileIf.open("laboratory4.txt");
	if (fileIf.is_open())
	{
		while (!fileIf.eof())
		{
			getline(fileIf, counterStr);
			quantitystr++;
		}
		quantitystr -= 7;
		fileIf.close();
		fileIf.open("laboratory4.txt");
		if (fileIf.is_open())
		{
			for (i = 0; i < quantitystr; i++)
			{
				getline(fileIf, counterStr);
			}
			if (counterStr == "")
			{
				counter = 1;
			}
			else
			{
				counter = stoi(counterStr);
				counter++;
			}
		}
	}
	fileIf.close();

	ofstream fileOf;
	fileOf.open("laboratory4.txt", ios::app);
	if (fileOf.is_open())
	{
		fileOf << "Название журнала: " << magazine->Get_name() << endl;
		fileOf << "Количество страниц: " << magazine->Get_pages() << endl;
		fileOf << "Цена: " << magazine->Get_cost() << endl;
		fileOf << "Количество на складе: " << magazine->Get_in_stock() << endl;
		fileOf << endl;
	}
	fileOf.close();
	std::cout << "Результат записан в файл!" << endl << endl;
}

int ConvertStringToInt(string str)
{
	int numberInt;
	string numberStr;
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			numberStr += str[i];
		}
	}

	numberInt = stoi(numberStr);

	return numberInt;
}

bool CheckChoice(string str)//Проверка ответа
{
	int i;
	bool check = true;
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			check = false;
		}
	}
	return check;
}

string ConvertFileString(string str)
{
	bool check = false;
	int i;
	string processedrStr;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == ':')
		{
			check = true;
			i = i + 2;
		}
		if (check == true)
		{
			processedrStr += str[i];
		}

	}

	return processedrStr;
}
