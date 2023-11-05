#include "Header.h"


/*void displayBySearch(const string& query)
{
	cout << "function's work began";
	string name;
	ifstream file("Statement.txt");
	if (file.is_open())
	{
		string line;
		bool found = false;
		int sessionLines = 0;
		cout << "Founded result: " << name << endl;
		while (getline(file, line))
		{
			if (sessionLines > 0)
			{
				cout << line << endl;
				sessionLines--;
				continue;
			}
			if (line.find(name) != string::npos)
			{
				cout << line << endl;
				found = true;
				sessionLines = 2;
			}
		}
		if (!found)
			cout << "Result not found." << endl;
		file.close();
	}
	else cout << "No saved results" << endl;
}*/

int main()
{
	string name;
	char choice;
	init_list();
	for (;;)
	{
		choice = menu();
		switch (choice)
		{
		case 'e': enter(); break;
		case 'd': display(); break;
		/*case 'sbn':
			cout << "Enter the name of magazine: ";
			cin >> name;
			displayBySearch(name); 
			break;*/
		//case 'u': update(); break;
		case 'q': return 0;
		}
	}
}




