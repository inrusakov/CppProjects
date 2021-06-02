#include "ReadWriter.h"
//string, iostream included in "ReadWriter.h"

using namespace std;

//Можно добавлять любые вспомогательные методы и классы для решения задачи.
long long countCell(int i, int j, int M, int N, long long** A)
{
	if (A[i][j] > 0)
		return A[i][j];

	A[i][j] = 0;

	if (i > 1)
	{
		if (j > 0)
		{
			A[i][j] += countCell(i - 2, j - 1, M, N, A);
		}
		if (j < (M - 1))
		{
			A[i][j] += countCell(i - 2, j + 1, M, N, A);
		}
	}
	if (j > 1)
	{
		if (i > 0)
		{
			A[i][j] += countCell(i - 1, j - 2, M, N, A);
		}
		if (i < (N - 1))
		{
			A[i][j] += countCell(i + 1, j - 2, M, N, A);
		}
	}

	return A[i][j];
}

//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M)
{
	long long** A = new long long* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new long long[M];
		for (int j = 0; j < M; j++)
		{
			A[i][j] = 0;
		}
	}

	A[0][0] = 1;

	long long result = countCell(N - 1, M - 1, M, N, A);

	for (int i = 0; i < N; i++)
	{
		delete[] A[i];
	}
	delete[] A;

	return result;
}

int main(int argc, const char* argv[])
{
	ReadWriter rw;

	int N = rw.readInt(); //количество строк (rows)
	int M = rw.readInt(); //количество столбцов (columns)
	//решение
	long long res = solve(N, M);
	//результат в файл
	rw.writeLongLong(res);

	return 0;
}