#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	int *keys, num, count, SIZE = 1;
	bool *solve, ret = false;
	cout << "Введите число: ";
	cin >> num;
	cout << "Введите количество чисел в массиве: ";
	cin >> SIZE;
	keys = new int[SIZE];
	solve = new bool[SIZE];
	cout << "Введите массив: ";
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
		int buf = keys[i];
		keys[i] = keys[m];
		keys[m] = buf;
		cout << keys[i] << " ";
	}
	cout << endl;
	for (int i = 0; (i < SIZE)&&(!ret); ++i)
	{
		for (int k = 0; k < SIZE; ++k) solve[k] = false;
		if (keys[i] > num) continue;
		int sum = 0;
		count = 0;
		for (int j = i; j < SIZE; ++j)
		{
			sum += keys[j];
			solve[j] = true;
			count++;
			if (sum == num) {
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
		cout << "Нет решений" << endl;
	} else {
		cout << "Решение для " << count << " чисел" << endl;
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