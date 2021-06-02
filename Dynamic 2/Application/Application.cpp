#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solve(int N, int W, vector<int> weights, vector<int> purchases)
{
	int** A = new int* [N + 1];
	for (int i = 0; i <= N; i++)
	{
		A[i] = new int[W + 1];
	}

	for (int i = 0; i <= W; i++)
	{
		A[0][i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			A[i][j] = A[i - 1][j];
			if (j >= weights[i - 1])
				if (A[i - 1][j - weights[i - 1]] + purchases[i - 1] > A[i][j])
				{
					A[i][j] = A[i - 1][j - weights[i - 1]] + purchases[i - 1];
				}
		}
	}

	int result = A[N][W];

	for (int i = 0; i <= N; i++)
	{
		delete[] A[i];
	}
	delete[] A;

	return result;
}

int main()
{
	string Str;
	getline(cin, Str);
	vector<int> arr;
	int n;
	istringstream ss1(Str);
	while (ss1 >> n) arr.push_back(n);

	string Str2;
	getline(cin, Str2);
	vector<int> arr2;
	int n2;
	istringstream ss2(Str2);
	while (ss2 >> n2) arr2.push_back(n2);

	string Str3;
	getline(cin, Str3);
	vector<int> arr3;
	int n3;
	istringstream ss3(Str3);
	while (ss3 >> n3) arr3.push_back(n3);

	cout << solve(arr[0], arr[1], arr2, arr3);
}
