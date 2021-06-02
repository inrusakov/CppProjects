#include "ReadWriter.h"
#include <chrono>

using namespace std;

bool check(int* arr, int n) {
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}

int getMax(int* a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void radix_sort(int* arr, int n)
{
    int exp = 1;
    int max = getMax(arr, n);

    int* temp = new int[n];
    while (max / exp > 0) {
        int counter[256] = { 0 };

        for (int i = 0; i < n; i++)
            counter[arr[i] / exp % 256]++;

        for (int i = 1; i < 256; i++)
            counter[i] += counter[i - 1];

        for (int i = n - 1; i >= 0; i--)
            temp[--counter[arr[i] / exp % 256]] = arr[i];

        for (int i = 0; i < n; i++)
            arr[i] = temp[i];

        exp *= 256;
    }
    delete[] temp;
}

int main()
{
    for (size_t i = 1; i <= 4; i++)
    {
        for (size_t k = 1; k <= 6; k++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                //Объект для работы с файлами
                ReadWriter rw(i, 1, k);

                int* brr = nullptr;
                int n;

                //Ввод из файла
                n = rw.readInt();
                brr = new int[n];
                rw.readArray(brr, n);

                auto start = std::chrono::high_resolution_clock::now();
                radix_sort(brr, n);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;
                long long milliseconds =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                //cout << milliseconds << endl;

                //Запись в файл
                //rw.writeInt(milliseconds);
                cout << check(brr, n);
                //освобождаем память
                delete[] brr;
            }
        }
        for (size_t k = 1; k <= 5; k++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                //Объект для работы с файлами
                ReadWriter rw(i, 2, k);

                int* brr = nullptr;
                int n;

                //Ввод из файла
                n = rw.readInt();
                brr = new int[n];
                rw.readArray(brr, n);

                auto start = std::chrono::high_resolution_clock::now();
                radix_sort(brr, n);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;
                long long milliseconds =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                //cout << milliseconds << endl;

                //Запись в файл
                //rw.writeInt(milliseconds);
                cout << check(brr, n);
                //освобождаем память
                delete[] brr;
            }
        }
    }
    
    return 0;
}
