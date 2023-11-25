#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct client_bank //объявляем шаблон структуры
{
    char fio[30]; //Наименование
    int nomer_cheta;
    int summa;
    int date; //Дата последнего завоза
};
struct client_bank mas[30]; //объвляем глобальный массив структур
struct client_bank tmp; //объявляем временую переменную структурного типа

int sch = 0; //Счетчик полных записей
int er; //Переключатель
int menu();
void enter_new();
void out();
void sort();
void search();
void del();
void change();

void find();
int main()
{
    setlocale(LC_ALL, "Russian");
    while (1)
    {
        switch (menu())
        {
        case 1:
            enter_new();
            break;
        case 2:
            out();
            break;

        case 4:
            change();
            break;
        case 5:
            del();
            break;
        default:
            cout << "Не верный выбор/n";
        }
    }
}
void CreateCard();

int menu()
{
    int er;
    cout << "Введите:\n";
    cout << "1. Для ввода новой записи\n";
    cout << "2. Для вывода записи(ей)\n";
    cout << "3. Для сортировки записи(ей)\n";
    cout << "4. Для поиска\n";
    cout << "5. Для удаления записи\n";
    cout << "6. Для выхода\n";
    cin >> er;
    return er;
}
void out() //ф-ция вывода записей
{
    int sw, i = 0;// переключатель для выбора выводить все записи или одну
    int k; //номер структуры, кот. надо вывести
    if (sch == 0) //если счетсик количества структур равен 0, то выводим, что нет записей
        cout << "\n Нет записей: \n";
    else
    {
        cout << "\n Введите: \n";
        cout << "1. Если хотите вывести какую-либо запсь\n";
        cout << "2. Если хотите вывести все записи\n";
        cin >> sw;
        if (sw == 1)
        {
            cout << "Введите номер записи, которую нужно вывести\n";
            cin >> k;
            cout << endl;
            cout << "ФИО клиента:" << mas[k - 1].fio << endl;
            cout << "Номер счёта:" << mas[k - 1].nomer_cheta << endl;
            cout << "Сумма:" << mas[k - 1].summa << endl;
            cout << "Дата последнего изменения:" << mas[k - 1].date << endl;
            cout << "-----------" << endl;
        }
        if (sw == 2)
        {
            for (int i = 0; i < sch; i++) //выводим в цикле все записи
                cout << "ФИО клиента:" << mas[i].fio << endl;
            cout << "Номер счёта:" << mas[i].nomer_cheta << endl;
            cout << "Сумма:" << mas[i].summa << endl;
            cout << "Дата последнего изменения:" << mas[i].date << endl;
            cout << "-----------" << endl;
        }
    }
}
void del() //ф-ция удаления записи
{
    int d; //номер записи, которую нужно удалить
    cout << "\nВведите номер записи, которую необходимо удалить\n";
    cout << "Если необходимо удалить все записи,нажмите '99'\n";
    cin >> d;
    if (d != 99)
    {
        for (int i = (d - 1); i < sch;
            i++) //цикл для удаления заданной записи, начинаемцикл с удаляемой записи
            mas[i] = mas[i + 1]; //замещаем текущую запись следующей за ней
        sch = sch - 1; //уменьшаем счетчик полных записей на 1
    }
    if (d == 99)
    {
        for (int i = 0; i < 30; i++) //цикл по все записям от первой до 30-ой
            mas[i] = tmp; //замещаем каждую структуру в массиве пустой структурой
        sch = 0; //счетчик структур обнуляем, т.к. все записи удалены
    }
}
void change() //функция для изменения записи
{
    int c; //номер записи, которую нужно изменить
    int per;
    cout << "\nВведите номер записи\n";
    cin >> c;
    do
    {
        cout << "Введите: \n";
        cout << "1. Для изменения ФИО\n";
        cout << "2. Для изменения номера счёта\n";
        cout << "3. Для изменения суммы\n";
        cout << "4. Для изменения даты последнего изменения:)\n";
        cin >> per;
        switch (per)
        {
        case 1:
            cout << "\nВведите новое ФИО\n";
            cin >> mas[c - 1].fio;
            break;
        case 2:
            cout << "\nВведите новый номер счёта\n";
            cin >> mas[c - 1].nomer_cheta;
            break;
        case 3:
            cout << "Введите новую сумму \n";
            cin >> mas[c - 1].summa;
            break;
        case 4:
            cout << "Введите новую дату последнего изменения\n";
            cin >> mas[c - 1].date;
            break;
        case 5:
            return;
        }
    } while (1);
}
void find() //ф-ция поиска записей
{
    int i=0; // переключатель
    if (sch == 0)
        cout << "\nНет запичей: \n";
    for (int i = 0; i < sch; i++) //в цикле просматриваем все структуры из массиваструктур
        cout << "ФИО клиента:" << mas[i].fio << endl;
    cout << "Номер счёта:" << mas[i].nomer_cheta << endl;
    cout << "Сумма:" << mas[i].summa << endl;
    cout << "Дата последнего изменения:" << mas[i].date << endl;
    cout << "-----------" << endl;
}