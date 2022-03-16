#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Sum(int** a, const int rowCount, const int colCount);


int main()
{
	int rowCount, colCount,s=-1;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	s =Sum(a, rowCount, colCount);
		cout << "S = " << s << endl;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int rowCount, const int colCount)
{
	int S = 0;
	bool minus_element;
	for (int j = 0; j < colCount; j++)
	{
		minus_element = false;
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] < 0)
			{
				minus_element = true;
				break;
			}
		if (!minus_element)
		{
			for (int i = 0; i < rowCount; i++)
				if (a[i][j] > 0)
					S+=a[i][j];
		}
	}
	return S;
}