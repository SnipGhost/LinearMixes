#include <iostream>
#include <fstream>
#define GETBIT(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 )
using namespace std;
typedef double TYPE;
int main()
{
	system("chcp 1251 > nul");
	double EPS = 0.00000000000000001;
	TYPE *keys, num, sum;
	unsigned SIZE = 1, count, i;
	unsigned long int solve;
	bool end = false;
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
	//---
	for (solve = 0; solve <= pow(2, SIZE); ++solve)
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
		if (abs(sum - num) < EPS) {
			for (i = 0; i < SIZE; ++i) 
			{
				if (GETBIT(solve, i) == 1) {
					cout << keys[i];
					count--;
					if (count > 0) cout << " + ";
					else cout << " = " << num << endl;
				}
			}
		}
	}
	//---
	cout << "Больше нет решений\n";
	system("pause");
	delete [] keys;
	return 0;
}