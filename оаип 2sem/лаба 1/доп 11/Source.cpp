#include <iostream>
#include <fstream>
#include <string>


using namespace std;



//Клиенты банка. Ф.И.О., тип счета (срочный, льготный и т. д.), номер счета, сумма на счете, дата последнего изменения. Выбор по номеру счета.
struct BankClients
{
	string name;
	string accType;
	string accNumber;
	string sum;
	string date;
};

const short N = 20;

void input(BankClients clients[])
{
	int num;
	do {
		cout << "Введите количество клиентов банка (не более " << N << "): ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	for (int i = 0; i < num; i++)
	{
		cout << "\tКлиент №" << i + 1 << endl;
		cout << "Введите ФИО клиента:\n";
		cin >> clients[i].name;
		cout << "Введите тип счёта:\n";
		cin >> clients[i].accType;
		cout << "Введите номер счёта:\n";
		cin >> clients[i].accNumber;
		cout << "Введите сумму на счёте:\n";
		cin >> clients[i].sum;
		cout << "Введите дату последнего изменения:\n";
		cin >> clients[i].date;
		cout << "\n\n";
	}
}

void output(BankClients clients[])
{
	int ClientNum;
	cout << "Введите номер клиента, которого вы хотите вывести:\n";
	cin >> ClientNum;
	int i = ClientNum - 1;
	cout << "\tКлиент №" << ClientNum << '\n';
	cout << "ФИО клиента: " << clients[i].name << '\n';
	cout << "Тип счёта: " << clients[i].accType << '\n';
	cout << "Номер счёта: " << clients[i].accNumber << '\n';
	cout << "Сумма на счёте: " << clients[i].sum << '\n';
	cout << "Дата последнего изменения: " << clients[i].date << "\n\n\n";
}

void deleteClient(BankClients clients[])
{
	int numCin;
	cout << "Введите порядковый номер клиента, информацию о котором Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin - 1;
	clients[i].name = ' ';
	clients[i].accType = ' ';
	clients[i].accNumber = ' ';
	clients[i].sum = ' ';
	clients[i].date = ' ';
	cout << '\n';
}

void search(BankClients clients[])
{
	string numSearch;
	cout << "Введите номер счёта искомого клиента:\n";
	cin >> numSearch;
	for (int i = 0; i < N; i++)
	{
		if (numSearch == clients[i].accNumber)
		{
			cout << "Клиент №" << i + 1 << ": счёт №" << clients[i].accNumber << '\n';
		}
	}
	cout << "\n\n";
}

void ofile(BankClients clients[])
{
	string buf;
	int num;
	do {
		cout << "Введите количество клиентов банка (не более " << N << "): ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tКлиент №" << i + 1 << '\n';
		file1 << "\tКлиент №" << i + 1 << '\n';
		cout << "Введите ФИО клиента:\n";
		file1 << "ФИО клиента: ";
		cin >> clients[i].name;
		file1 << clients[i].name;
		cout << "Введите тип счёта:\n";
		file1 << "\nТип счёта: ";
		cin >> clients[i].accType;
		file1 << clients[i].accType;
		cout << "Введите номер счёта:\n";
		file1 << "\nНомер счёта: ";
		cin >> clients[i].accNumber;
		file1 << clients[i].accNumber;
		cout << "Введите сумму на счёте:\n";
		file1 << "\nСумма на счёте: ";
		cin >> clients[i].sum;
		file1 << clients[i].sum;
		cout << "Введите дату последнего изменения:\n";
		file1 << "\nДата последнего изменения: ";
		cin >> clients[i].date;
		file1 << clients[i].date << "\n\n";
	}
	cout << "\n\n";
}

void ifile(BankClients clients[])
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
    int choose;
	BankClients clients[N];
	do {
		cout << "Выберите, что сделать:\n1 — ввод элементов структуры с клавиатуры;\n2 — вывод элементов стуктуры в консольное окно;"
			"\n3 — удаление заданной структурированной переменной; \n4 — поиск информации; \n5 — запись информации в файл; \n6 — чтение данных из файла.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: input(clients); break;
		case 2: output(clients); break;
		case 3: deleteClient(clients); break;
		case 4: search(clients); break;
		case 5: ofile(clients); break;
		case 6: ifile(clients); break;
		
		}
		
	
	} while (choose != 6);

}



