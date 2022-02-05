#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void table(float a[], float b[]) {
    float c[20][10];
    int i, j;
    cout << "Результат:" << endl;
    ofstream fout("3labaout.txt");
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            c[i][j] = a[j] / (1 + abs(b[i]));
            cout << c[i][j] << " ";
            fout << c[i][j] << " ";
        }
        cout << endl;
        fout << endl;
    }
}

void fail() {
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("3laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        int i;
        float a[10], b[20];
        for (i = 0; i < 10; i++) {
            fin >> a[i];
        }
        for (i = 0; i < 20; i++) {
            fin >> b[i];
        }
        table(a, b);
    }
}

void cons() {
    cout << "Хорошо, вводите данные. Для начала введите числа a." << endl;
    int i;
    float a[10], b[20];
    for (i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << "Теперь введите числа b." << endl;
    for (i = 0; i < 20; i++) {
        cin >> b[i];
    }
    table(a, b);
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    int x;
    cin >> x;
    if (x == 1) {
        cons();
    }
    else {
        cout << "Хорошо, завершаю работу." << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        fail();
    }
}