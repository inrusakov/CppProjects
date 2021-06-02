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

void merge(int* arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}


void mergeSort(int* arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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
                mergeSort(brr, 0, n - 1);
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
                mergeSort(brr, 0, n - 1);
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
