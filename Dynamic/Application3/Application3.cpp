#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string getLCS(string a, string b)
{
	int len1 = a.length();
	int len2 = b.length();
	string result;

	vector<vector<int>> lcs(len1 + 1, vector<int>(len2 + 1));

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			if (a[i] == b[j])
			{
				lcs[i][j] = lcs[i + 1][j + 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
			}
		}
	}

	int i = 0, j = 0;
	while (i < len1 && j < len2)
	{
		if (a[i] == b[j])
		{
			result.push_back(a[i]);
			i++;
			j++;
		}
		else if (lcs[i+1][j] == lcs[i][j]) 
		{
			i++;
		}
		else 
		{
			j++;
		}
	}
	return result;
}

int main()
{
	string x;
	string y;
	string res;

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