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

void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (int curr = i + 1; curr < size; ++curr)
        {
            if (arr[curr] < arr[min])
                min = curr;
        }
        if (arr[i] != arr[min])
        {
            swap(arr[i], arr[min]);
        }
    }
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
                selectionSort(brr, n);
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
                selectionSort(brr, n);
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
