#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size)  // Сортировка пузырьком
{
	int tmp;

	for (int i = 0; i < size - 1; ++i) // i - номер прохода
	{
		for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
		{
			if (arr[j + 1] > arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int sum(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + arr[i];
	return sum;
}

void Output(int* arr, int size) {
	cout << "[" << arr[0];
	for (int i = 1; i < size; i++)
		cout << "," << arr[i];
	cout << "]";
}


int main() {
	int size;

		cout << "Enter the size of the array: ";
	cin >> size;
	int* mas = new int[size];

	cout << endl << "Enter the elements: " << endl;
	for (int i = 0; i < size; i++)
		cin >> mas[i];
	cout << endl;

	int ms1 = 0, ms2 = 0, ms3 = 0;
	int sz = size-2, i1 = 0, i2 = 0, i3 = 0;
	int* mas1 = new int[sz];
	int* mas2 = new int[sz];
	int* mas3 = new int[sz];

	for (int i = 0; i <sz; i++) {
		mas1[i] = 0;
		mas2[i] = 0;
		mas3[i] = 0;
	}

	bubbleSort(mas, size);

	for (int i = 0; i < size; i++) {
		if ((sum(mas1, sz) == sum(mas2, sz)) || (sum(mas1, sz) == sum(mas3, sz)) || (sum(mas2, sz) == sum(mas3, sz)))
			if ((sum(mas1, sz) == sum(mas2, sz)) && (sum(mas1, sz) == sum(mas3, sz)) && (sum(mas2, sz) == sum(mas3, sz))) {
				mas1[i1] = mas[i];
				i1++;
			}
			else	if (sum(mas1, sz) == sum(mas2, sz))
				if (sum(mas1, sz) > sum(mas3, sz)) {
					mas3[i3] = mas[i];
					i3++;
				}
				else {
					mas1[i1] = mas[i];
					i1++;
				}
			else	if (sum(mas1, sz) == sum(mas3, sz))
				if (sum(mas3, sz) > sum(mas2, sz)) {
					mas2[i2] = mas[i];
					i2++;
				}
				else {
					mas3[i3] = mas[i];
					i3++;
				}
			else {
				if (sum(mas2, sz) == sum(mas3, sz))
					if (sum(mas1, sz) > sum(mas2, sz)) {
						mas2[i2] = mas[i];
						i2++;
					}
					else {
						mas1[i1] = mas[i];
						i1++;
					}
			}
		else if ((sum(mas1, sz) < sum(mas2, sz)) && (sum(mas1, sz) < sum(mas3, sz))) {
			mas1[i1] = mas[i];
			i1++;
		}
		else if ((sum(mas2, sz) < sum(mas1, sz)) && (sum(mas2, sz) < sum(mas3, sz))) {
			mas2[i2] = mas[i];
			i2++; 
		}
		else if ((sum(mas3, sz) < sum(mas1, sz)) && (sum(mas3, sz) < sum(mas2, sz))) {
			mas3[i3] = mas[i];
			i3++;
		}
		else {
			mas1[i1] = mas[i];
			i1++;
		}

	}

		cout << "Array 1 ";	Output(mas1, sz);
		cout << endl << "Sum of  first array " << sum(mas1, sz) << endl << endl;
		cout << "Array 2 ";	Output(mas2, sz);
		cout << endl << "Sum of second array " << sum(mas2, sz) << endl << endl;
		cout << "Array 3 ";	Output(mas3, sz);
		cout << endl << "Sum of  third array " << sum(mas3, sz) << endl << endl;
		cout << "Input Array ";	Output(mas, size);
		cout << endl << "Sum of input array " << sum(mas, size) << endl << endl;

		cout << endl << "Status:";
		if (sum(mas1, sz) + sum(mas2, sz) + sum(mas3, sz) == sum(mas, size))
			cout << "Good" << endl;
		else
			cout << "Not Good" << endl;
	return 0;
}