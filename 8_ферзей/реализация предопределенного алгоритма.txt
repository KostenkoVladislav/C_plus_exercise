#include <iostream>
#include "windows.h"
using namespace std;
const int n = 9;

int main()
{
	int cht = 0;

	int field[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			field[i][j] = 0;//initialization
	int a;
	if (n % 2 == 1)
		a = n / 2;
	else
		a = (n / 2) - 1;

	int b = n;
	field[0][a] = 1;
	for (int i = 1; i < n; i++) {
		cht++;
		if (i % 2 == 0) {
			a--;
			field[i][a] = 1;
		}
		else {
			b--;
			field[i][b] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << field[i][j] << " ";
			Sleep(20);
		}
		cout << endl;
	}
	cout << endl << cht+1 << endl;

	return 0;
}