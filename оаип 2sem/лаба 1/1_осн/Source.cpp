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

	cout << "0-������ �������" << endl;

	cout << "1-����� �� �������" << endl;
	cout << "2-�������� ��������" << endl;
	cin >> chouse;

	Worker a[size];
	switch (chouse) {
	case 0:

		for (i = 0; i < size; i++)
		{
			cout << "������� ������� " << i + 1 << "-��� ������ " << endl;
			cin >> a[i].lastName;

			cin >> a[i].o;
			cout << endl << "������������: ";
			cin >> a[i].izd;
			cout << endl << "������ ����������(����������� ����������,�����, �������� ��������� � ��): ";
			cin >> a[i].razdel;
			cout << endl << "�������������(�������, �����, �������): ";
			cin >> a[i].prois;
			cout << endl << " ������� �����: ";
			cin >> a[i].nal;
			cout << endl << "�������� �����: ";
			cin >> a[i].namebuck;





		}

	case 1:
		cout << "������ �������" << endl;
		cin >> name;
	default:
		break;
	}
	ofstream fout("t.txt");   // �������� ������� fout ������ ofstream ��� ������
	for (int i = 0; i < size; i++) {

		fout << a[i].lastName; // ������ ������ � ����

	}
	fout.close();

	ifstream fin("t.txt");    // �������� ������� fin ������ ifstream ��� ������  
	for (i = 0; i < size; i++)
	{
		if (name == a[i].lastName)
		{

			if (!fin.is_open())
				cout << "���� �� ����� ���� ������!\n";
			else
			{
				fin >> buff;           // ���������� ������� ����� �� �����
				cout << buff << endl;  // ������ �����
				fin.getline(buff, 50); // ���������� ������ �� �����

				   // ������ ������
			}
			cout << "�������� �����: ";
			cout << a[i].namebuck << " ";
			cout << " ������������: ";
			cout << a[i].izd << " ";
			cout << " �������: ";
			cout << a[i].nal << " ";
			cout << " �������������: ";
			cout << a[i].prois << " ";
			cout << " ������: ";
			cout << a[i].razdel << " ";
		}
		else
		{
			l++;
		}

		if (l == 3)
			cout << "������ � ������ �������� ����";
		fin.close();
	}

	return 0;
}
