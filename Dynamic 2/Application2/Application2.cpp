#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

using namespace std;

//����� ��������� ����� ��������������� ������ � ������ ��� ������� ������.

void AddResults(int i, int j, int** A, pair<int, int>* items, vector<pair<int, int>>& res)
{
	if (i != 0 && j != 0)
	{
		if (A[i][j] == 0)
			return;
		else if (A[i][j] == A[i - 1][j])
			AddResults(i - 1, j, A, items, res);
		else
		{
			AddResults(i - 1, j - items[i - 1].first, A, items, res);
			res.push_back(items[i - 1]);
		}
	}
}

//������ ����������� ���� �����
//param N - ���������� ���������
//param W - ����������� �� ��� �������
//param items - ������ ������� N, � ���������� - first = ���, second = ���������
//param res - ������ ����������� (��������, ������� ���� �����)
void solve(int N, int W, pair<int, int>* items, vector<pair<int, int>>& res)
{
	int** A = new int* [N + 1];
	for (int i = 0; i <= N; i++)
	{
		A[i] = new int[W + 1];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			A[i][j] = A[i - 1][j];
			if (j >= items[i - 1].first)
			{
				if (A[i - 1][j - items[i - 1].first] + items[i - 1].second > A[i][j])
					A[i][j] = A[i - 1][j - items[i - 1].first] + items[i - 1].second;
			}
		}
	}

	AddResults(N, W, A, items, res);
	for (int i = 0; i <= N; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

int main(int argc, const char* argv[])
{
	ReadWriter rw;
	int N = rw.readInt(); //���������� ���������
	int W = rw.readInt(); //����������� �� ��� �������

	//��������� ������ pair �������, ��� ��� �������� ���������� � � ������� ����� 2 ��������������
	//first = ���(weight), second = ��������� (cost)
	//����� ���������� ������ � ����� ������ ������� ��������
	//��������(!) ������ �� �����������, �� ����� ��� ������� ���� ��� ���������
	pair<int, int>* arr = new pair<int, int>[N];
	rw.readArr(arr, N);

	//��������� ������ pair �������, ��� ��� ���������� ���������� ���������, � � ������� ����� 2 ��������������
	//���������, ����� first = ���(weight), second = ��������� (cost)
	vector<pair<int, int>> res;
	solve(N, W, arr, res);

	int sumCost = 0, sumWeight = 0;
	for (int i = 0; i < res.size(); i++)
	{
		sumWeight += res[i].first;
		sumCost += res[i].second;
	}
	//���������� ����� � ����
	rw.writeInt(sumCost);
	rw.writeInt(sumWeight);
	rw.writeInt(res.size());
	rw.writeVector(res);

	delete[] arr;
	return 0;
}