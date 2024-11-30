#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector> 

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Розмір масиву має бути додатнім числом!" << endl;
        return 1;
    }

    vector<int> A(N); // Створюємо розмір N

    // Ініціалізація генератора випадкових чисел
    srand(time(0));//встановлює як базу поточний час

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 101 - 50; // від -50 до 50
    }

    // Виведення початкового масиву
    cout << "Початковий масив:\n";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Видалення додатніх елементів шляхом зсуву
    int newSize = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] <= 0) {
            A[newSize] = A[i];
            newSize++;
        }
    }

    cout << "Масив після видалення додатніх елементів:\n";
    for (int i = 0; i < newSize; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

