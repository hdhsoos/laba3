#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void table(int n, int m, float a[], float b[], int x) {
    float** c = new float* [m];
    for (int i = 0; i < m; i++)
        c[i] = new float[n];
    int i{}, j{};
    if (x == 1) {
        cout << "���������:" << endl;
    }
    ofstream fout("3labaout.txt");
    for (i; i < m; i++) {
        for (j = 0; j < n; j++) {
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
        int n{}, m{}; // 10, 20
        fin >> n;
        fin >> m;
        float* a{};
        a = new float[n];
        float* b{};
        b = new float[m];
        for (i=0; i < n; i++) {
            fin >> a[i];
        }
        for (i=0; i < m; i++) {
            fin >> b[i];
        }
        table(n, m, a, b, x);
    }
}

int end_cons() {
    cout << "������ ��������� ���� �������� ������ ? �� � 1, ��� � 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        start();
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
    cout << "������, ������� ������. ��� ������ ������� ����� n � m ����� ������. n - ���������� ����� a, m - ���������� ����� b." << endl;
    int n{}, m{}; // 10, 20
    cin >> n;
    cin >> m;
    float* a{};
    a = new float[n];
    float* b{};
    b = new float[m];
    int i{};
    cout << "������� ����� a." << endl;
    for (i=0; i < n; i++) {
        cin >> a[i];
    }
    cout << "������ ������� ����� b." << endl;
    for (i=0; i < m; i++) {
        cin >> b[i];
    }
    table(n, m, a, b, x);
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

void start() {
    setlocale(LC_ALL, "rus");
    cout << "�� ������ ������ ������ �� ����� ��� �� �������?" << endl;
    cout << "0 - �� �����, 1 - �� �������." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            fail();
        }
        else {
            cout << "������ �����. ���������� �����." << endl;
            start();
        }
    }
}