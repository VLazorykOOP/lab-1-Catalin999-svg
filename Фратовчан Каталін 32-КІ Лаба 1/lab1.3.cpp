#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    cout << "Введіть значення n (максимум 200): ";
    cin >> n;

    // Перевірка коректності значення n
    if (n > 200 || n <= 0) {
        cout << "Некоректне значення n." << endl;
        return 1;
    }

    // Створюємо масив A розміру 2 * n
    vector<int> A(2 * n);

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Заповнення масиву випадковими числами від -50 до 50
    for (int i = 0; i < 2 * n; i++) {
        A[i] = rand() % 101 - 50;
    }

    // Виведення початкового масиву
    cout << "Масив A:\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Пошук максимуму серед мінімальних значень пар
    int maxMin = INT_MIN; // Початкове значення для максимуму

    for (int i = 0; i < n; i++) {
        int leftElement = A[i];          // Елемент з початку
        int rightElement = A[2 * n - i - 1]; // Відповідний елемент з кінця
        int currentMin = min(leftElement, rightElement); // Мінімум поточної пари
        maxMin = max(maxMin, currentMin); // Оновлення максимуму
    }

    // Виведення результату
    cout << "Результат (максимум серед мінімальних): " << maxMin << endl;

    return 0;
}
