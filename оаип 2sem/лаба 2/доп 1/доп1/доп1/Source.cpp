#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int numExams;
    int* grades;
};

bool allPassedWith45(const Student& s) {
    for (int i = 0; i < s.numExams; i++) {
        if (s.grades[i] < 4) {
            return false;
        }
    }
    return true;
}

void processStudent(const Student& s) {
    if (allPassedWith45(s)) {
        cout << s.name << " сдал все экзамены на 4 и 5" << endl;
    }
    else {
        cout << s.name << " не сдал все экзамены на 4 и 5" << endl;
    }
}

float calculateSuccessRate(Student* students, int numStudents) {
    int passed = 0;
    for (int i = 0; i < numStudents; i++) {
        if (allPassedWith45(students[i])) {
            passed++;
        }
    }
    return (float)passed / (float)numStudents * 100.0;
}

int main() {
    setlocale(LC_CTYPE, "ru");
    Student students[3];

    students[0].name = "Кривенчук Максим Игоревич";
    students[0].numExams = 4;
    students[0].grades = new int[4]{ 5, 4, 4, 5 };

    students[1].name = "Навойчик Владислав Витальевич";
    students[1].numExams = 3;
    students[1].grades = new int[3]{ 5, 4, 3 };

    students[2].name = "Соловей Руслан Евгеньевич";
    students[2].numExams = 2;
    students[2].grades = new int[2]{ 4, 3 };

    for (int i = 0; i < 3; i++) {
        processStudent(students[i]);
    }

    float successRate = calculateSuccessRate(students, 3);
    cout << "Процент успеваемости: " << successRate << "%" << endl;

    delete[] students[0].grades;
    delete[] students[1].grades;
    delete[] students[2].grades;

    return 0;
}
