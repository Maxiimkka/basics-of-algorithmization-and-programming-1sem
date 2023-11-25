#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct client_bank //��������� ������ ���������
{
    char fio[30]; //������������
    int nomer_cheta;
    int summa;
    int date; //���� ���������� ������
};
struct client_bank mas[30]; //�������� ���������� ������ ��������
struct client_bank tmp; //��������� �������� ���������� ������������ ����

int sch = 0; //������� ������ �������
int er; //�������������
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
            cout << "�� ������ �����/n";
        }
    }
}
void CreateCard();

int menu()
{
    int er;
    cout << "�������:\n";
    cout << "1. ��� ����� ����� ������\n";
    cout << "2. ��� ������ ������(��)\n";
    cout << "3. ��� ���������� ������(��)\n";
    cout << "4. ��� ������\n";
    cout << "5. ��� �������� ������\n";
    cout << "6. ��� ������\n";
    cin >> er;
    return er;
}
void out() //�-��� ������ �������
{
    int sw, i = 0;// ������������� ��� ������ �������� ��� ������ ��� ����
    int k; //����� ���������, ���. ���� �������
    if (sch == 0) //���� ������� ���������� �������� ����� 0, �� �������, ��� ��� �������
        cout << "\n ��� �������: \n";
    else
    {
        cout << "\n �������: \n";
        cout << "1. ���� ������ ������� �����-���� �����\n";
        cout << "2. ���� ������ ������� ��� ������\n";
        cin >> sw;
        if (sw == 1)
        {
            cout << "������� ����� ������, ������� ����� �������\n";
            cin >> k;
            cout << endl;
            cout << "��� �������:" << mas[k - 1].fio << endl;
            cout << "����� �����:" << mas[k - 1].nomer_cheta << endl;
            cout << "�����:" << mas[k - 1].summa << endl;
            cout << "���� ���������� ���������:" << mas[k - 1].date << endl;
            cout << "-----------" << endl;
        }
        if (sw == 2)
        {
            for (int i = 0; i < sch; i++) //������� � ����� ��� ������
                cout << "��� �������:" << mas[i].fio << endl;
            cout << "����� �����:" << mas[i].nomer_cheta << endl;
            cout << "�����:" << mas[i].summa << endl;
            cout << "���� ���������� ���������:" << mas[i].date << endl;
            cout << "-----------" << endl;
        }
    }
}
void del() //�-��� �������� ������
{
    int d; //����� ������, ������� ����� �������
    cout << "\n������� ����� ������, ������� ���������� �������\n";
    cout << "���� ���������� ������� ��� ������,������� '99'\n";
    cin >> d;
    if (d != 99)
    {
        for (int i = (d - 1); i < sch;
            i++) //���� ��� �������� �������� ������, ������������ � ��������� ������
            mas[i] = mas[i + 1]; //�������� ������� ������ ��������� �� ���
        sch = sch - 1; //��������� ������� ������ ������� �� 1
    }
    if (d == 99)
    {
        for (int i = 0; i < 30; i++) //���� �� ��� ������� �� ������ �� 30-��
            mas[i] = tmp; //�������� ������ ��������� � ������� ������ ����������
        sch = 0; //������� �������� ��������, �.�. ��� ������ �������
    }
}
void change() //������� ��� ��������� ������
{
    int c; //����� ������, ������� ����� ��������
    int per;
    cout << "\n������� ����� ������\n";
    cin >> c;
    do
    {
        cout << "�������: \n";
        cout << "1. ��� ��������� ���\n";
        cout << "2. ��� ��������� ������ �����\n";
        cout << "3. ��� ��������� �����\n";
        cout << "4. ��� ��������� ���� ���������� ���������:)\n";
        cin >> per;
        switch (per)
        {
        case 1:
            cout << "\n������� ����� ���\n";
            cin >> mas[c - 1].fio;
            break;
        case 2:
            cout << "\n������� ����� ����� �����\n";
            cin >> mas[c - 1].nomer_cheta;
            break;
        case 3:
            cout << "������� ����� ����� \n";
            cin >> mas[c - 1].summa;
            break;
        case 4:
            cout << "������� ����� ���� ���������� ���������\n";
            cin >> mas[c - 1].date;
            break;
        case 5:
            return;
        }
    } while (1);
}
void find() //�-��� ������ �������
{
    int i=0; // �������������
    if (sch == 0)
        cout << "\n��� �������: \n";
    for (int i = 0; i < sch; i++) //� ����� ������������� ��� ��������� �� ���������������
        cout << "��� �������:" << mas[i].fio << endl;
    cout << "����� �����:" << mas[i].nomer_cheta << endl;
    cout << "�����:" << mas[i].summa << endl;
    cout << "���� ���������� ���������:" << mas[i].date << endl;
    cout << "-----------" << endl;
}