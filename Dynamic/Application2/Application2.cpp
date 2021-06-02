#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int getLCS(string a, string b) 
{
	int len1 = a.length();
	int len2 = b.length();

	vector<vector<int>> lcs(len1+1, vector<int>(len2+1));
	int res = 0, temp = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			if (a[i] == b[j])
			{
				temp = lcs[i + 1][j + 1] + 1;
				lcs[i][j] = temp;
				res = temp;
			}
			else
			{
				temp = max(lcs[i + 1][j], lcs[i][j + 1]);
				lcs[i][j] = temp;
				res = temp;
			}
		}
	}

	return res;
}

int main()
{
	string x;
	string y;
	int res;

	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		getline(fin, x);
		getline(fin, y);
		fin.close();
	}

	res = getLCS(x, y);

	fstream fout;
	fout.open("output.txt", ios::out);
	fout << res;
	fout.close();

	return 0;
}