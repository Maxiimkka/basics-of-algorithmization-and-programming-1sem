#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Sanatorium {
    string name;
    string location;
    string profile;
    int numTickets;
};

bool compareSanatoriums(const Sanatorium& s1, const Sanatorium& s2) {
    return s1.name < s2.name;
}

void printSanatorium(const Sanatorium& s) {
    cout << s.name << "              " << s.location  << "                   " << s.numTickets << endl;
} 

void printSanatoriums(Sanatorium* sanatoriums, int numSanatoriums) {
    sort(sanatoriums, sanatoriums + numSanatoriums, compareSanatoriums);

    string lastProfile = "";
    for (int i = 0; i < numSanatoriums; i++) {
        if (sanatoriums[i].profile != lastProfile) {
            lastProfile = sanatoriums[i].profile;
            cout << "______________________________________________________________________________________" << endl;
            cout << endl << lastProfile << ":" << endl;
            cout << "��������\t����� ������������\t���������� �������" << endl;
        }
        printSanatorium(sanatoriums[i]);
    }
}

void searchSanatoriums(Sanatorium* sanatoriums, int numSanatoriums, const string& profile) {
   
    // ���� ��������� �� �������� � ������� ���������� � ���
    for (int i = 0; i < numSanatoriums; i++) {
        if (sanatoriums[i].profile == profile) {
            cout << "�������� ���������: " << sanatoriums[i].name << endl;
            cout << "����� ������������: " << sanatoriums[i].location << endl;
            cout << "�������� �������: " << sanatoriums[i].profile << endl;
            cout << "���������� �������: " << sanatoriums[i].numTickets << endl;
            return;
        }
    }
    cout << "��������� � �������� " << profile << " �� ������" << endl;
   
}

int main() {
    setlocale(LC_CTYPE,"ru");
    Sanatorium sanatoriums[6];

    sanatoriums[0].name = "���������";
    sanatoriums[0].location = "����";
    sanatoriums[0].profile = "Nervous";
    sanatoriums[0].numTickets = 10;

    sanatoriums[1].name = "���������";
    sanatoriums[1].location = "�����";
    sanatoriums[1].profile = "Musculoskeletal";
    sanatoriums[1].numTickets = 5;

    sanatoriums[2].name = "��������";
    sanatoriums[2].location = "�������";
    sanatoriums[2].profile = "Respiratory";
    sanatoriums[2].numTickets = 15;

    sanatoriums[3].name = "�������� ���";
    sanatoriums[3].location = "����";
    sanatoriums[3].profile = "Dermal";
    sanatoriums[3].numTickets = 20;

    sanatoriums[4].name = "�����";
    sanatoriums[4].location = "������";
    sanatoriums[4].profile = "Cardio-vascular";
        sanatoriums[4].numTickets = 5;

    sanatoriums[5].name = "��������";
    sanatoriums[5].location = "������";
    sanatoriums[5].profile = "neuro-psychic";
    sanatoriums[5].numTickets = 10;

    int numSanatoriums = 6;

    cout << "��� ���������:" << endl;
    printSanatoriums(sanatoriums, numSanatoriums);

    cout << endl;
    string profile;
    cout << "������� �������� ������� ���������: ";
    cin >> profile;
    searchSanatoriums(sanatoriums, numSanatoriums, profile);

   

    return 0;
}