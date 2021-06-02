#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadWriter
{
private:

	std::fstream fin;
	std::fstream fout;

public:

	~ReadWriter()
	{
		fin.close();
		fout.close();
	}

	ReadWriter(int a, int b, int c)
	{
		string path = "..\\tests\\" + to_string(a);
		path += "\\" + to_string(b);
		path += "\\input" + to_string(c);
		path += ".txt";
		fin.open(path, std::ios::in);
		string path2 = "output";
		path2 += to_string(a);
		path2 += to_string(b);
		path2 += to_string(c) + ".txt";
		fout.open(path2, std::ios_base::app | std::ios_base::in);
	}

	int readInt()
	{
		if (!fin.is_open())
			throw std::ios_base::failure("file not open");

		int n = 0;
		fin >> n;
		return n;
	}

	//This method only fill array. You should create it before call this method.
	void readArray(int* arr, int length)
	{
		if (!fin.is_open())
			throw std::ios_base::failure("file not open");

		for (int i = 0; i < length; i++)
			fin >> arr[i];
	}

	void writeInt(int n)
	{
		if (!fout.is_open())
			throw std::ios_base::failure("file not open");
		fout << n << "\n";
	}
	void writeArray(int* arr, int n)
	{
		if (!fout.is_open())
			throw std::ios_base::failure("file not open");
		for (int i = 0; i < n; i++)
			fout << arr[i] << " ";
	}
	
};