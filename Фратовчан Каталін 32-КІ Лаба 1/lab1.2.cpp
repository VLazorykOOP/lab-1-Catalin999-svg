#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    int N;

    // Ввід розміру масиву з перевіркою
    cout << "Введіть розмір масиву N: ";
    while (!(cin >> N) || N <= 0) {
        cout << "Розмір масиву має бути додатнім числом! Спробуйте ще раз: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> A(N);

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // Заповнення масиву випадковими числами в діапазоні від -50 до 50
    for (int& x : A) {
        x = rand() % 101 - 50;
    }

    // Виведення масиву
    cout << "Початковий масив:\n";
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;

    // Пошук першого парного елемента
    auto firstEvenIt = find_if(A.begin(), A.end(), [](int x) { return x % 2 == 0; });

    if (firstEvenIt == A.end()) {
        cout << "У масиві немає парних елементів.\n";
        return 0;
    }

    // Пошук мінімального додатного елемента праворуч від першого парного
    int minPositive = INT_MAX;
    bool found = false;

    for (auto it = firstEvenIt + 1; it != A.end(); ++it) {
        if (*it > 0 && *it < minPositive) {
            minPositive = *it;
            found = true;
        }
    }

    // Виведення результату
    if (found) {
        cout << "Мінімальне додатне значення праворуч від першого парного елемента: " << minPositive << endl;
    }
    else {
        cout << "Додатніх елементів праворуч від першого парного елемента не знайдено.\n";
    }

    return 0;
}
