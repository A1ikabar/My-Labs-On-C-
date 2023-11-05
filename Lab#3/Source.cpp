#include "Header.h"


struct inv_type
{
	char magazine[40]; //��� ������
	double cost, retail; //���������, ��������� ����
	int on_hand, lead_time; //���������� � �������, ����� ���� �� ����������
}
invtry[SIZE];

//������������� ������� ��������
void init_list()
{
	int t;
	//��� ������� ����� ������� ������ ���
	for (t = 0; t < SIZE; t++)
		*invtry[t].magazine = '\0';
}

//��������� ������� ����, ��������� �������������.
int menu()
{
	char ch;
	cout << '\n';
	do
	{
		cout << "(E)nter\n"; //������ ����� �������
		cout << "(D)isplay\n"; //���������� ��� ���������
		//cout << "(sbn)Search by name\n"; //���������� ��������� �� ������
		//cout << "(U)pdate\n"; //�������� �������
		cout << "(Q)uit\n\n"; //����� �� ���������
		cout << "Choose command ";
		cin >> ch;
	} while (!strchr("eduq", tolower(ch)));
	return tolower(ch);
}

//���� ��������� � ����������� ���������
void enter()
{
	int i;
	//������� ������ ��������� ���������
	for (i = 0; i < SIZE; i++)
		if (!*invtry[1].magazine)
			break;
	//���� ������ �����, �������� i ����� ����� SIZE
	if (i == SIZE)
	{
		cout << "List is full\n";
		return;
	}
	input(i);
}

//���� ����������
void input(int i)
{
	cout << "Magazine: "; cin >> invtry[i].magazine;
	cout << "Cost: "; cin >> invtry[i].cost;
	cout << "Retail: "; cin >> invtry[i].retail;
	cout << "On hand: "; cin >> invtry[i].on_hand;
	cout << "Time until replenishment (days): "; cin >> invtry[i].lead_time;

	ofstream file("Statement.txt", ios::app);
	if (file.is_open())
	{
		file << "\nMagazine: " << invtry[i].magazine;
		file << "\nCost: " << invtry[i].cost;
		file << "\nRetail: " << invtry[i].retail;
		file << "\nOn hand: " << invtry[i].on_hand;
		file << "\nTime until replenishment (days): " << invtry[i].lead_time;
		file.close();
	}
	else
		cout << "File cannot be opened";

}

/*//����������� ������������� ��������
void update()
{
	int i;
	char name[80];
	cout << "Enter product name: "; cin >> name;
	for (i = 0; i < SIZE; i++)
		if (!strcmp(name, invtry[i].magazine))
			break;
	if (i == SIZE)
	{
		cout << "Product not found\n";
		return;
	}
	cout << "Enter a new information\n";
	input(i);
}*/

//����������� �� ������ ����������� ���������
void display()
{
	ifstream res("Statement.txt");
	cout << "----- Data from file -----" << endl;
	string line;
	while (getline(res, line))
		cout << line << endl;
	res.close();
	cout << "--------------------------" << endl;
}