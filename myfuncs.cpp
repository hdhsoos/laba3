#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void table(float a[], float b[], int x) {
    float c[20][10];
    int i{}, j{};
    if (x == 1) {
        cout << "���������:" << endl;
    }
    ofstream fout("3labaout.txt");
    for (i; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            c[i][j] = a[j] / (1 + abs(b[i]));
            if (x == 1) {
                cout << c[i][j] << " ";
            }
            else {
                fout << c[i][j] << " ";
            }
        }
        if (x == 1) {
            cout << endl;
        }
        else {
            fout << endl;
        }
    }
}

void fail() {
    int x;
    x = vivod();
    cout << "������, ����� ����." << endl;
    ifstream fin("3laba.txt");
    if (!fin.is_open())
        cout << "���� ���������� �������. �������� ������." << endl;
    else {
        int i{};
        float a[10], b[20];
        for (i=0; i < 10; i++) {
            fin >> a[i];
        }
        for (i=0; i < 20; i++) {
            fin >> b[i];
        }
        table(a, b, x);
    }
}

int end_cons() {
    cout << "������ ��������� ���� �������� ������ ? �� � 1, ��� � 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            cout << "������, �������� ������" << endl;
            return 0;
        }
        else {
            cout << "������ �����. ���������� �����." << endl;
            end_cons();
        }
    }
}

void cons() {
    int x;
    x = vivod();
    cout << "������, ������� ������. ��� ������ ������� ����� a." << endl;
    int i{};
    float a[10], b[20];
    for (i=0; i < 10; i++) {
        cin >> a[i];
    }
    cout << "������ ������� ����� b." << endl;
    for (i=0; i < 20; i++) {
        cin >> b[i];
    }
    table(a, b,x);
    end_cons();
}

int vivod() {
    setlocale(LC_ALL, "rus");
    cout << "�� ������ ������� ������ � ���� ��� �������?" << endl;
    cout << "0 - � ����, 1 - � �������." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        return 1;
    }
    else {
        if (a[0] == '0') {
            return 0;
        }
        else {
            cout << "������ �����. ���������� �����." << endl;
            vivod();
        }
    }
}
