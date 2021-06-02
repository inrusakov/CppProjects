#include "ReadWriter.h"
//vector, string, iostream, algorithm included in "ReadWriter.h"

using namespace std;

//����� ��������� ����� ��������������� ������ � ������ ��� ������� ������.

//������ ����������� ���� ����� (������ ��������)
//param N - ���������� ���������
//param W - ����������� �� ��� �������
//param items - ������ ������� N, � ���������� - first = ���, second = ���������
//param res - ������ ����������� (��������, ������� ���� �����)
void solve(int N, int W, pair<int, int>* items, vector<pair<int, int>>& res)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            auto firstC = (items[j].second / (double)items[j].first); 
            auto secC = (items[j + 1].second / (double)items[j + 1].first);
            if (firstC < secC)
                swap(items[j], items[j + 1]);
            if (firstC == secC && items[j].first < items[j + 1].first)
                swap(items[j], items[j + 1]);
        }
    }

    int weight = 0;
    for (int i = 0; i < N; i++)
    {
        if ((weight + items[i].first) <= W)
        {
            res.push_back(items[i]);
            weight += items[i].first;
        }
    }
}

int main(int argc, const char* argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //���������� ���������
    int W = rw.readInt(); //����������� �� ��� �������

    //��������� ������ pair �������, ��� ��� �������� ���������� ���������, � � ������� ����� 2 ��������������
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