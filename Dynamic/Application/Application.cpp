#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Основная задача - реализовать данный метод
int countMaxCross(string& riverMap)
{
	int result = 0;
	string road;
	for (size_t i = 0; i < riverMap.length(); i++)
	{
		if (riverMap[i] == 'B')
		{
			result++;
		}
		else
		{
			road += riverMap[i];
		}
	}
	road.append("XX");
	char pos = 'L';

	for (size_t i = 0; i < road.length() - 1; i++)
	{
		if (pos == 'L')
		{
			if (road[i] == 'L' && road[i + 1] == 'L')
			{
				result++;
				pos = 'R';
				i++;
			}
			else if (road[i] == 'L' && road[i + 1] == 'R')
			{
				result++;
			}
			else if ((road[i] == 'X') || (road[i] == 'L' && road[i + 1] == 'X'))
			{
				result++;
				break;
			}
		}
		if (pos == 'R')
		{
			if (road[i] == 'R' && road[i + 1] == 'R')
			{
				result++;
				pos = 'L';
				i++;
			}
			else if ((road[i] == 'R') || (road[i] == 'R' && road[i + 1] == 'L'))
			{
				result++;
			}
		}
	}
	return result;
}


int main()
{
	string riverMap;
	int res;

	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		getline(fin, riverMap);
		fin.close();
	}

	res = countMaxCross(riverMap);

	fstream fout;
	fout.open("output.txt", ios::out);
	fout << res;
	fout.close();

	return 0;
}
