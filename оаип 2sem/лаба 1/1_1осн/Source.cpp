#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>


using namespace std;

int sch = 0; //���-�� �������� � �������
char er;

struct library
{
    char avtor[30];
    char nazvanie[30];
    int izdatelstvo;
    char razdel[30];
    char proishozdenie[30];
    char nalichie[30];
}l_arr[30]; //���������


void poisk_po_avtory()
{
    if (!sch)
    {
        cout << "������� ���-������ �������!" << endl;
    }
    else {
        cout << "������� ������:" << endl;
        char w[20];
        cin >> w;
        bool flag = 1;
        for (int i = 0; i < sch; i++)
        {
            if (strcmp(w, l_arr[i].avtor) == 0)   // strcmp = ��������� �����
            {
                cout << "����� �����:" << l_arr[i].avtor << endl;
                cout << "�������� �����: " << l_arr[i].nazvanie << endl;
                cout << "��� �������: " << l_arr[i].izdatelstvo << endl;
                cout << "������: " << l_arr[i].razdel << endl;
                cout << "�������������: " << l_arr[i].proishozdenie << endl;
                cout << "�������: " << l_arr[i].nalichie << endl;
                flag = 0;
            }
            if (flag)
                cout << "����� �� ��� �����������" << endl;
        }
    }
}
void input_and_otput() {
    string path = "t.txt";
    fstream fs;

    fs.open(path); 

    if (!fs.is_open()) {
        cout << "������" << endl;
    }
    else {
        int value;
        cout << "���� ��������" << endl;
        cout << "�������" << endl;
        cout << "1 - ��� ������ ��������� � ����" << endl;
        cout << "2 - ��� ���������� ���� ��������� � �����" << endl;
        cout << "3 - ��� �������� ���� ���������" << endl;
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
            cout << "������ ������ �� �����" << endl;
            for (int i = 0; !fs.eof(); i++) {
                fs >> l_arr[i].avtor;
                cout << "����� �����:" << l_arr[i].avtor << endl;
                fs >> l_arr[i].nazvanie;
                cout << "�������� �����: " << l_arr[i].nazvanie << endl;
                fs >> l_arr[i].izdatelstvo;
                cout << "��� �������: " << l_arr[i].izdatelstvo << endl;
                fs >> l_arr[i].razdel;
                cout << "������: " << l_arr[i].razdel << endl;
                fs >> l_arr[i].proishozdenie;
                cout << "�������������: " << l_arr[i].proishozdenie << endl;
                fs >> l_arr[i].nalichie;
                cout << "�������: " << l_arr[i].nalichie << endl;
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
    cout << "\n������� ����� ������ ������� ���� �������" << endl;
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
    int c, per;                                        //����� ������, ������� ����� ��������
    cout << "\n������� ����� ������" << endl;
    cin >> c;
    do
    {
        cout << "�������: " << endl;
        cout << "1-��� ��������� ������" << endl;
        cout << "2-��� ��������� ��������" << endl;
        cout << "3-��� ��������� ���� �������" << endl;
        cout << "4-��� ��������� �������" << endl;
        cout << "5-��� ��������� �������������" << endl;
        cout << "6-��� ��������� �������" << endl;
        cout << "7-��� ������ �� ������ �������������� " << endl;
        cin >> per;
        switch (per)
        {

        case 1: cout << "�����: " << endl;
            cin >> l_arr[c - 1].avtor;
            break;
        case 2: cout << "�������� �����: ";
            cin >> l_arr[c - 1].nazvanie;
            break;
        case 3: cout << "��� �������:: ";
            cin >> l_arr[c - 1].izdatelstvo;
        case 4: cout << "������: ";
            cin >> l_arr[c - 1].razdel;
        case 5: cout << "�������������: ";
            cin >> l_arr[c - 1].proishozdenie;
        case 6: cout << "�������: ";
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

        cout << "����� �����"; cout << sch + 1;

        cout << endl << "�����:" << endl;

        cin >> l_arr[sch].avtor;

        cout << "�������� �����:" << endl;

        cin >> l_arr[sch].nazvanie;

        cout << "��� �������: " << endl;

        cin >> l_arr[sch].izdatelstvo;

        cout << "������: " << endl;

        cin >> l_arr[sch].razdel;

        cout << "�������������: " << endl;

        cin >> l_arr[sch].proishozdenie;

        cout << "�������: " << endl;

        cin >> l_arr[sch].nalichie;

        sch++;

    }

    else cout << "������� ������������ ���-�� �������";
    cout << "��� ������ ������?" << endl;

    cin >> er;

}


void out()                   //�-��� ������ �������
{
    setlocale(LC_CTYPE, "Russian");
    int sw;                            // �������������
    int o;                             //����� ������, ���. ���� �������
    cout << endl << "�������: " << endl;
    cout << "1-���� ������ ������� �����-���� ������" << endl;
    cout << "2-���� ������ ������� ��� ������" << endl;
    cin >> sw;

    if (sw == 1)
    {
        cout << "������� ����� ������, ������� ����� �������" << endl;
        cin >> o;
        o--;

        cout << "����� �����: " << l_arr[o].avtor << endl;
        cout << "�������� �����: " << l_arr[o].nazvanie << endl;
        cout << "��� �������: " << l_arr[o].izdatelstvo << endl;
        cout << "������: " << l_arr[o].razdel << endl;
        cout << "�������������: " << l_arr[o].proishozdenie << endl;
        cout << "�������: " << l_arr[o].nalichie << endl;
    }
    if (sw == 2)
    {
        for (int i = 0; i < sch; i++)
        {

            cout << "����� �����: " << l_arr[o].avtor << endl;
            cout << "�������� �����: " << l_arr[o].nazvanie << endl;
            cout << "��� �������: " << l_arr[o].izdatelstvo << endl;
            cout << "������: " << l_arr[o].razdel << endl;
            cout << "�������������: " << l_arr[o].proishozdenie << endl;
            cout << "�������: " << l_arr[o].nalichie << endl;

        }
    }

    cout << endl;
}

int main()
{
    int SIZE = 10;
    setlocale(LC_CTYPE, "Russian");
    cout << "������� ���� ���" << endl;
    do {
        cout << "�������:" << endl;
        cout << "1-��� ����� ����� ������" << endl;
        cout << "2-��� ������ ������(��) " << endl;
        cout << "3-��� ��������� ������" << endl;
        cout << "4-��� �������� ������" << endl;
        cout << "5-��� ������ �� ������ " << endl;
        cout << "6- ��� ������ (��� ������) ���������� � (��) ����(-�)" << endl;
        cout << "7-��� ������ " << endl;
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