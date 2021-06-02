#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//���������� ����������� ����� ��������� ����������� ������
int LevenshteinDistance(string& str1, int len1, string& str2, int len2)
{
    if (min(len1, len2) == 0)
        return max(len1, len2);
    else
        return min((LevenshteinDistance(str1, len1, str2, len2 - 1) + 1),
            min((LevenshteinDistance(str1, len1 - 1, str2, len2) + 1),
                (LevenshteinDistance(str1, len1 - 1, str2, len2 - 1) + (str1[len1 - 1] == str2[len2 - 1] ? 0 : 1))));
}

//�� �������� ����� main ��� ������� �������������
//����������� �������� � ������������ ��������� ��������� � ������� ���������� ��� �������� ��� ����� ������.
int main()
{
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string N;
        getline(fin, N);
        // ��� �������� int � ��������� ������ ��� ��� ��� ���� �� ��������.
        int n = atoi(N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin, s);
            getline(fin, t);
            fout << LevenshteinDistance(s, s.length(), t, t.length()) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}
