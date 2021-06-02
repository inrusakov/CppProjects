#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

using namespace std;

//����� ��������� ����� ��������������� ������ � ������ ��� ������� ������.
void AddResults(int i, int j, int** A, int*& stones, vector<int>& res)
{
	if (i != 0 && j != 0)
	{
		if (A[i][j] == 0)
			return;
		else if (A[i][j] == A[i - 1][j])
			AddResults(i - 1, j, A, stones, res);
		else
		{
			AddResults(i - 1, j - stones[i - 1], A, stones, res);
			res.push_back(stones[i - 1]);
		}
	}
}
//������ ����������� ���� �����
//param N - ���������� ������
//param M - ����������� �� ���
//param stones - ������ ������� N, � ������ ������
//param res - ������ ����������� (��� ������, ������� ���� �����)
void solve(int N, int W, int*& stones, vector<int>& res)
{
	//vector<vector<unsigned short int>> A(N + 1, vector<unsigned short int>(W + 1));
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
			if (j >= stones[i - 1])
				if ((A[i - 1][j - stones[i - 1]] + stones[i - 1] > A[i][j]))
				{
					A[i][j] = A[i - 1][j - stones[i - 1]] + stones[i - 1];
				}
		}
	}

	AddResults(N, W, A, stones, res);
	for (int i = 0; i <= N; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

int main(int argc, const char* argv[])
{
	ReadWriter rw;
	int N = rw.readInt(); //�����
	int W = rw.readInt(); //����������� �� ���
	int* arr = new int[N]; //��������� �����
	rw.readArr(arr, N);

	//�������� ���������� ������ ������, ��� ��� ������� ���������� ����� ���������� ������ ����� �����
	vector<int> res;
	//������ ������
	solve(N, W, arr, res);
	int sum = 0;
	for (int i = 0; i < res.size(); i++)
		sum += res.at(i);

	//���������� ����� � ����
	rw.writeInt(sum); //�������� ���
	rw.writeInt(res.size()); //���������� ������ ������
	rw.writeVector(res); //���� �����

	delete[] arr;
	return 0;
}