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

void bubble(int* arr, int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    for (size_t i = 1; i <= 4; i++)
    {
        for (size_t k = 1; k <= 6; k++)
        {
            for (size_t j = 0; j < 1; j++)
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
                bubble(brr, n);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;
                long long milliseconds =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

                //Запись в файл
                //rw.writeInt(milliseconds);
                cout << check(brr, n);
                //освобождаем память
                delete[] brr;
            }
        }
        for (size_t k = 1; k <= 5; k++)
        {
            for (size_t j = 0; j < 1; j++)
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
                bubble(brr, n);
                auto elapsed = std::chrono::high_resolution_clock::now() - start;
                long long milliseconds =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

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

