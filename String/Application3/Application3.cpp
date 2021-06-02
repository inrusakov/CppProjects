#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//Необходимо реализовать метод
//о алгоритме можно прочитать в источниках указанных в программе курса, или на странице курса в ЛМС или в презентациях к семинару.
int Wagner_Fischer_for_Damerau_Levenshtein(string& str1, string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    
    int** data_mat = new int* [len1 + 1];
    for (int i = 0; i <= len1; i++)
    {
        data_mat[i] = new int[len2 + 1];
        data_mat[i][0] = i;
    }

    for (int j = 0; j <= len2; j++)
        data_mat[0][j] = j;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (i > 1 && j > 1 && str1[i - 2] == str2[j - 1] && str1[i - 1] == str2[j - 2])
                if (str1[i - 1] == str2[j - 1])
                    data_mat[i][j] = min(min((data_mat[i - 1][j] + 1), (data_mat[i][j - 1] + 1)),
                        min((data_mat[i - 1][j - 1]), (data_mat[i - 2][j - 2] + 1)));
                else
                    data_mat[i][j] = min(min((data_mat[i - 1][j] + 1), (data_mat[i][j - 1] + 1)),
                        min((data_mat[i - 1][j - 1] + 1), (data_mat[i - 2][j - 2] + 1)));
                
            else if (str1[i - 1] == str2[j - 1])
                data_mat[i][j] = min(min((data_mat[i - 1][j] + 1), (data_mat[i][j - 1] + 1)), (data_mat[i - 1][j - 1]));
            else
                data_mat[i][j] = min(min((data_mat[i - 1][j] + 1), (data_mat[i][j - 1] + 1)), (data_mat[i - 1][j - 1] + 1));
        }
    }

    int result = data_mat[len1][len2];

    for (int i = 0; i <= len1; i++)
        delete[] data_mat[i];
    delete[] data_mat;

    return result;
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char* argv[])
{
    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string N;
        getline(fin, N);
        n = atoi(N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin, s);
            getline(fin, t);
            fout << Wagner_Fischer_for_Damerau_Levenshtein(s, t) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}