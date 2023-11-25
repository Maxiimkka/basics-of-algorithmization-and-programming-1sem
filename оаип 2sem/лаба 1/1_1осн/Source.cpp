#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>


using namespace std;

int sch = 0; //кол-во структур в массиве
char er;

struct library
{
    char avtor[30];
    char nazvanie[30];
    int izdatelstvo;
    char razdel[30];
    char proishozdenie[30];
    char nalichie[30];
}l_arr[30]; //структура


void poisk_po_avtory()
{
    if (!sch)
    {
        cout << "Сначала что-нибудь введите!" << endl;
    }
    else {
        cout << "Введите автора:" << endl;
        char w[20];
        cin >> w;
        bool flag = 1;
        for (int i = 0; i < sch; i++)
        {
            if (strcmp(w, l_arr[i].avtor) == 0)   // strcmp = сравнение строк
            {
                cout << "Автор книги:" << l_arr[i].avtor << endl;
                cout << "Название книги: " << l_arr[i].nazvanie << endl;
                cout << "Год издания: " << l_arr[i].izdatelstvo << endl;
                cout << "Раздел: " << l_arr[i].razdel << endl;
                cout << "Происхождение: " << l_arr[i].proishozdenie << endl;
                cout << "Наличие: " << l_arr[i].nalichie << endl;
                flag = 0;
            }
            if (flag)
                cout << "Поиск не дал результатов" << endl;
        }
    }
}
void input_and_otput() {
    string path = "t.txt";
    fstream fs;

    fs.open(path); 

    if (!fs.is_open()) {
        cout << "Ошибка" << endl;
    }
    else {
        int value;
        cout << "Файл открылся" << endl;
        cout << "Введите" << endl;
        cout << "1 - для записи сообщения в файл" << endl;
        cout << "2 - для считывания всех сообщений в файле" << endl;
        cout << "3 - для удаления всех сообщений" << endl;
        cin >> value;

        if (value == 1) {
            for (int i = 0; i < sch; i++) {
                fs << l_arr[i].avtor << "\n";
                fs << l_arr[i].nazvanie << "\n";
                fs << l_arr[i].izdatelstvo << "\n";
                fs << l_arr[i].razdel << "\n";
                fs << l_arr[i].proishozdenie << "\n";
                fs << l_arr[i].nalichie << "\n";
            }
        }

        if (value == 2) {
            cout << "Чтение данных из файла" << endl;
            for (int i = 0; !fs.eof(); i++) {
                fs >> l_arr[i].avtor;
                cout << "Автор книги:" << l_arr[i].avtor << endl;
                fs >> l_arr[i].nazvanie;
                cout << "Название книги: " << l_arr[i].nazvanie << endl;
                fs >> l_arr[i].izdatelstvo;
                cout << "Год издания: " << l_arr[i].izdatelstvo << endl;
                fs >> l_arr[i].razdel;
                cout << "Раздел: " << l_arr[i].razdel << endl;
                fs >> l_arr[i].proishozdenie;
                cout << "Происхождение: " << l_arr[i].proishozdenie << endl;
                fs >> l_arr[i].nalichie;
                cout << "Наличие: " << l_arr[i].nalichie << endl;
            }
        }

        if (value == 3) {
            ofstream file(path);
            file << "";
        }
    }
    fs.close();
}


void del()
{
    cout << "\nВведите номер записи которую надо удалить" << endl;
    int k;
    cin >> k;
    for (int i = k - 1; i < sch; i++)
    {
        l_arr[i] = l_arr[i + 1];
    }
    sch--;
}


void change()
{
    int c, per;                                        //номер записи, которую нужно изменить
    cout << "\nВведите номер записи" << endl;
    cin >> c;
    do
    {
        cout << "Введите: " << endl;
        cout << "1-для изменения автора" << endl;
        cout << "2-для изменения названия" << endl;
        cout << "3-для изменения года издания" << endl;
        cout << "4-для изменения раздела" << endl;
        cout << "5-для изменения происхождения" << endl;
        cout << "6-для изменения наличия" << endl;
        cout << "7-для выхода из режима редактирования " << endl;
        cin >> per;
        switch (per)
        {

        case 1: cout << "Автор: " << endl;
            cin >> l_arr[c - 1].avtor;
            break;
        case 2: cout << "Название книги: ";
            cin >> l_arr[c - 1].nazvanie;
            break;
        case 3: cout << "Год издания:: ";
            cin >> l_arr[c - 1].izdatelstvo;
        case 4: cout << "Раздел: ";
            cin >> l_arr[c - 1].razdel;
        case 5: cout << "Происхождение: ";
            cin >> l_arr[c - 1].proishozdenie;
        case 6: cout << "Наличие: ";
            cin >> l_arr[c - 1].nalichie;
            break;

            cin >> per;
        }
    } while (per != 7);

}


void dobavl()
{


    if (sch < 20)

    {

        cout << "Книга номер"; cout << sch + 1;

        cout << endl << "Автор:" << endl;

        cin >> l_arr[sch].avtor;

        cout << "Название книги:" << endl;

        cin >> l_arr[sch].nazvanie;

        cout << "Год издания: " << endl;

        cin >> l_arr[sch].izdatelstvo;

        cout << "Раздел: " << endl;

        cin >> l_arr[sch].razdel;

        cout << "Происхождение: " << endl;

        cin >> l_arr[sch].proishozdenie;

        cout << "Наличие: " << endl;

        cin >> l_arr[sch].nalichie;

        sch++;

    }

    else cout << "Введено максимальное кол-во записей";
    cout << "Что делать дальше?" << endl;

    cin >> er;

}


void out()                   //ф-ция вывода записей
{
    setlocale(LC_CTYPE, "Russian");
    int sw;                            // переключатель
    int o;                             //номер структ, кот. надо вывести
    cout << endl << "Введите: " << endl;
    cout << "1-если хотите вывести какую-либо запись" << endl;
    cout << "2-если хотите вывести все записи" << endl;
    cin >> sw;

    if (sw == 1)
    {
        cout << "Введите номер записи, которую нужно вывести" << endl;
        cin >> o;
        o--;

        cout << "Автор книги: " << l_arr[o].avtor << endl;
        cout << "Название книги: " << l_arr[o].nazvanie << endl;
        cout << "Год издания: " << l_arr[o].izdatelstvo << endl;
        cout << "Раздел: " << l_arr[o].razdel << endl;
        cout << "Происхождение: " << l_arr[o].proishozdenie << endl;
        cout << "Наличие: " << l_arr[o].nalichie << endl;
    }
    if (sw == 2)
    {
        for (int i = 0; i < sch; i++)
        {

            cout << "Автор книги: " << l_arr[o].avtor << endl;
            cout << "Название книги: " << l_arr[o].nazvanie << endl;
            cout << "Год издания: " << l_arr[o].izdatelstvo << endl;
            cout << "Раздел: " << l_arr[o].razdel << endl;
            cout << "Происхождение: " << l_arr[o].proishozdenie << endl;
            cout << "Наличие: " << l_arr[o].nalichie << endl;

        }
    }

    cout << endl;
}

int main()
{
    int SIZE = 10;
    setlocale(LC_CTYPE, "Russian");
    cout << "Записей пока нет" << endl;
    do {
        cout << "Введите:" << endl;
        cout << "1-для ввода новой записи" << endl;
        cout << "2-для вывода записи(ей) " << endl;
        cout << "3-для изменения записи" << endl;
        cout << "4-для удаления записи" << endl;
        cout << "5-для поиска по автору " << endl;
        cout << "6- для записи (или вывода) информации в (из) файл(-а)" << endl;
        cout << "7-для выхода " << endl;
        cin >> er;

        switch (er)
        {
        case '1':dobavl(); break;
        case '2':out(); break;
        case '3':change(); break;
        case '4':del(); break;
        case '5':poisk_po_avtory(); break;
        case '6':input_and_otput(); break;
        }
    } while (er != '7');

}