#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#define _WIN32_WINDOWS 0x0501
#define _WIN32_IE 0x0600
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	double EPS = 0.00000000000001;
	system("chcp 1251 > nul");
	double *keys, num;
	int count, SIZE = 1;
	bool *solve, ret = false;
	cout << "������� �����: ";
	cin >> num;
	cout << "������� ���������� ����� � �������: ";
	cin >> SIZE;
	keys = new double[SIZE];
	solve = new bool[SIZE];
	cout << "������� ������: ";
	for (int i = 0; i < SIZE; ++i)
		cin >> keys[i];
	for (int i = 0; i < SIZE; ++i)
	{
		int m = i;
		for (int j = i+1; j < SIZE; ++j)
		{
			if (keys[j] > keys[m]) 
			{
				m = j;
			}
		}
		double buf = keys[i];
		keys[i] = keys[m];
		keys[m] = buf;
		cout << keys[i] << " ";
	}
	cout << endl;
	for (int i = 0; (i < SIZE)&&(!ret); ++i)
	{
		for (int k = 0; k < SIZE; ++k) solve[k] = false;
		if (keys[i] > num) continue;
		double sum = 0;
		count = 0;
		for (int j = i; j < SIZE; ++j)
		{
			sum += keys[j];
			solve[j] = true;
			count++;
			if (abs(sum - num) < EPS) {
				ret = true; 
				break;
			}
			else if (sum > num) {
				sum -= keys[j];
				solve[j] = false;
				count--;
			}
		}
	}
	if (!ret) {
		cout << "��� �������" << endl;
	} else {
		cout << "������� ��� " << count << " �����" << endl;
		for (int k = 0; k < SIZE; ++k)
		{
			if (solve[k]) {
				cout << keys[k];
				count--;
				if (count > 0) cout << " + ";
			}
		}
		cout << " = " << num << endl;
	}
	system("pause");
	delete [] keys;
	return 0;
}