#include <fstream>
#include <iostream>
using namespace std;

struct Worker
{
	char lastName;
	char nal[30];
	char o[10];
	char izd[30];
	char razdel[20];
	char prois[20];
	char namebuck[30];

};

int main()
{
	int l = 0;
	setlocale(LC_ALL, "Russian");
	const int size = 3;
	char name, buff[50];
	int i, b, counter = 0, chouse;

	cout << "0-запись авторов" << endl;

	cout << "1-выбор по фамилии" << endl;
	cout << "2-удаление елемента" << endl;
	cin >> chouse;

	Worker a[size];
	switch (chouse) {
	case 0:

		for (i = 0; i < size; i++)
		{
			cout << "Введите фамилию " << i + 1 << "-ого автора " << endl;
			cin >> a[i].lastName;

			cin >> a[i].o;
			cout << endl << "издательство: ";
			cin >> a[i].izd;
			cout << endl << "раздел библиотеки(специальная литература,хобби, домашнее хозяйство и тд): ";
			cin >> a[i].razdel;
			cout << endl << "происхождение(покупка, кража, подарок): ";
			cin >> a[i].prois;
			cout << endl << " наличие книги: ";
			cin >> a[i].nal;
			cout << endl << "название книги: ";
			cin >> a[i].namebuck;





		}

	case 1:
		cout << "нужная фамилия" << endl;
		cin >> name;
	default:
		break;
	}
	ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи
	for (int i = 0; i < size; i++) {

		fout << a[i].lastName; // запись строки в файл

	}
	fout.close();

	ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
	for (i = 0; i < size; i++)
	{
		if (name == a[i].lastName)
		{

			if (!fin.is_open())
				cout << "Файл не может быть открыт!\n";
			else
			{
				fin >> buff;           // считывание первого слова из файла
				cout << buff << endl;  // печать слова
				fin.getline(buff, 50); // считывание строки из файла

				   // печать строки
			}
			cout << "Название книги: ";
			cout << a[i].namebuck << " ";
			cout << " Издательство: ";
			cout << a[i].izd << " ";
			cout << " Наличие: ";
			cout << a[i].nal << " ";
			cout << " Происхождение: ";
			cout << a[i].prois << " ";
			cout << " Раздел: ";
			cout << a[i].razdel << " ";
		}
		else
		{
			l++;
		}

		if (l == 3)
			cout << "автора с данной фамилией нету";
		fin.close();
	}

	return 0;
}
