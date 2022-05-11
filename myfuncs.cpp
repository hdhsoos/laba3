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
        cout << "Результат:" << endl;
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
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("3laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
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
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        start();
    }
    else {
        if (a[0] == '0') {
            cout << "Хорошо, завершаю работу" << endl;
            return 0;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            end_cons();
        }
    }
}

void cons() {
    int x;
    x = vivod();
    cout << "Хорошо, вводите данные. Для начала введите числа n и m через пробел. n - количество чисел a, m - количество чисел b." << endl;
    int n{}, m{}; // 10, 20
    cin >> n;
    cin >> m;
    float* a{};
    a = new float[n];
    float* b{};
    b = new float[m];
    int i{};
    cout << "Введите числа a." << endl;
    for (i=0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Теперь введите числа b." << endl;
    for (i=0; i < m; i++) {
        cin >> b[i];
    }
    table(n, m, a, b, x);
    end_cons();
}

int vivod() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите вывести данные в файл или консоль?" << endl;
    cout << "0 - в файл, 1 - в консоль." << endl;
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
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            vivod();
        }
    }
}

void start() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
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
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            start();
        }
    }
}