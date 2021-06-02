#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solve(int N, int a, int b, int c)
{
	int* floors = new int[N];
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		floors[i] = 0;
	}
	floors[0] = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (floors[i] == 1)
		{
			if (i + a < N)
				floors[i + a] = 1;
			if (i + b < N)
				floors[i + b] = 1;
			if (i + c < N)
				floors[i + c] = 1;
		}	
	}
	
	for (int i = 0; i < N; i++)
	{
		result += floors[i];
	}
	delete[] floors;
	return result;
}

int main()
{
	int size;
	string Str;
	getline(cin, Str);
	size = stoi(Str);
	getline(cin, Str);
	vector<int> arr;
	int n;
	istringstream ss1(Str);
	while (ss1 >> n) arr.push_back(n);

	cout << solve(size, arr[0], arr[1], arr[2]);
}
