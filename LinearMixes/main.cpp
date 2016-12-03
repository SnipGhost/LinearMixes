#include <iostream>
#include <fstream>
#include <Windows.h>
#define GETBIT(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 )
using namespace std;
typedef double TYPE;
int work(istream &input, ostream &output)
{
	double EPS = 10;
	TYPE *keys, num, sum;
	unsigned SIZE = 1, count, i;
	unsigned long int solve;
	bool end = false;
	cout << "Ввод погрешности: \n";
	input >> EPS;
	cout << "EPS = " << EPS << endl;
	cout << "Ввод числа: \n";
	input >> num;
	cout << "NUM = " << num << endl;
	cout << "Введ количества чисел в массиве: \n";
	input >> SIZE;
	cout << "SIZE = " << SIZE << endl;
	if (SIZE > 32) {
		cout << "Слишком много эл-ов! (Не более 32)\n";
		return -1;
	}
	keys = new TYPE[SIZE];
	cout << "Введите массив: \n";
	for (i = 0; i < SIZE; ++i) input >> keys[i];
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
					output << keys[i];
					count--;
					if (count > 0) output << " + ";
					else output << "\n = " << sum << endl;
				}
			}
		}
	}
	output << "Больше нет решений\n";
	system("pause");
	delete [] keys;
	return 0;
}
int main()
{
	system("chcp 1251 > nul");
	char s[255] = "out.txt";
	cout << "Введите имя выходного файла: ";
	cin.getline(s, '\n');
	ofstream fout(s);
	if (fout.fail()) {
		cout << "Ошибка открытия файла" << endl;
	} else {
		cout << "Ввод из файла? (y/n) ";
		char c;
		cin >> c;
		if (c == 'y') {
			cout << "Введите имя входного файла: ";
			cin.ignore(777, '\n');
			cin.getline(s, '\n');
			ifstream fin(s);
			if (fin.fail()) {
				cout << "Ошибка чтения входного файла" << endl;
			} else {
				work(fin, fout);
				fin.close();
			}
		} else {
			work(cin, fout);
		}
	}
	fout.close();
	return 0;
}