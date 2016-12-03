#include <iostream>
#include <fstream>
#include <Windows.h>
#define GETBIT(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 )
using namespace std;
typedef double TYPE;
int main()
{
	system("chcp 1251 > nul");
	ofstream fout("out.txt");
	double EPS = 10;
	TYPE *keys, num, sum;
	unsigned SIZE = 1, count, i;
	unsigned long int solve;
	bool end = false;
	cout << "Введите погрешность: ";
	cin >> EPS;
	cout << "Введите число: ";
	cin >> num;
	cout << "Введите количество чисел в массиве: ";
	cin >> SIZE;
	if (SIZE > 32) {
		cout << "Слишком много эл-ов! (Не более 32)\n";
		return 0;
	}
	keys = new TYPE[SIZE];
	cout << "Введите массив: ";
	for (i = 0; i < SIZE; ++i) cin >> keys[i];
	cout << "---------------------------------------\n";
	for (solve = 0; solve < pow(2, SIZE); ++solve)
	{
		count = 0;
		sum = 0;
		for (i = 0; i < SIZE; ++i)
		{
			if (GETBIT(solve, i) == 1)
			{
				sum += keys[i];
				count++;
			}
		}
		if (fabs(sum - num) <= EPS) {
			for (i = 0; i < SIZE; ++i) 
			{
				if (GETBIT(solve, i) == 1) {
					cout << keys[i];
					count--;
					if (count > 0) cout << " + ";
					else cout << "\n = " << sum << endl;
				}
			}
		}
	}
	cout << "Больше нет решений\n";
	system("pause");
	delete [] keys;
	return 0;
}