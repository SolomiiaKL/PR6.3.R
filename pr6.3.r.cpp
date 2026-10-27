#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 1. Звичайна рекурсивна функція для обчислення кількості від'ємних елементів (цілі числа)
int CountNegative(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return 1 + CountNegative(a, size, i + 1);
        else
            return CountNegative(a, size, i + 1);
    }
    else
        return 0;
}

// 2. Шаблон рекурсивної функції для універсального алгоритму (для будь-якого типу даних T)
template <typename T>
int CountNegative(T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return 1 + CountNegative<T>(a, size, i + 1);
        else
            return CountNegative<T>(a, size, i + 1);
    }
    else
        return 0;
}

int main()
{
    // Тестування звичайної функції для int
    const int n1 = 6;
    int a[n1] = { 5, -2, 3, -8, 0, -1 };

    cout << "Array a (int): ";
    for (int i = 0; i < n1; i++)
        cout << setw(4) << a[i];
    cout << endl;

    int count1 = CountNegative(a, n1, 0);
    cout << "CountNegative(a, n1) = " << count1 << endl << endl;

    // Тестування шаблону функції для int
    int count2 = CountNegative<int>(a, n1, 0);
    cout << "CountNegative<int>(a, n1) = " << count2 << endl << endl;

    // Тестування шаблону функції для double
    const int n2 = 5;
    double b[n2] = { 1.5, -3.2, 4.0, -0.5, 2.1 };

    cout << "Array b (double): ";
    for (int i = 0; i < n2; i++)
        cout << setw(6) << b[i];
    cout << endl;

    int count3 = CountNegative<double>(b, n2, 0);
    cout << "CountNegative<double>(b, n2) = " << count3 << endl;

    return 0;
}