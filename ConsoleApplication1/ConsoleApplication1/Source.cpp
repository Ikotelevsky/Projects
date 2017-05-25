/*
Определите наименьшее расстояние между двумя локальными максимумами последовательности натуральных чисел, завершающейся числом 0.
Если в последовательности нет двух локальных максимумов, выведите число 0.

Начальное и конечное значение при этом локальными максимумами не считаются.

Расстоянием считается количество пробелов между элементами. 

Формат входных данных
Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, 
а служит как признак ее окончания).
Формат выходных данных
Выведите ответ на задачу.
*/


#include <iostream>
using namespace std;
int main() {


	int temp1 = -1, temp2 = -1, input = -1, min_lenth = 0, pos_max1 = 0, pos_max2 = 0, count = 0, count_max = 0;
	while (input != 0) {
		cin >> input;
		if (input == 0) {
			break;
		}
		else if (temp1 == -1) {
			temp1 = input;
			count++;
			continue;
		}
		else if (temp2 == -1) {
			temp2 = input;
			count++;
			continue;
		}

		if (temp2 > temp1 && temp2 > input) {
			count_max++;
			if (pos_max1 == 0) {
				pos_max1 = count;
				count++;
				temp1 = temp2;
				temp2 = input;
			}
			else if (pos_max2 == 0) {
				pos_max2 = count;
				count++;
				min_lenth = pos_max2 - pos_max1;
				temp1 = temp2;
				temp2 = input;
			}
			else {
				pos_max1 = pos_max2;
				pos_max2 = count;
				if (pos_max2 - pos_max1 < min_lenth) {
					min_lenth = pos_max2 - pos_max1;
				}
				temp1 = temp2;
				temp2 = input;
			}
		}
		else {
			temp1 = temp2;
			temp2 = input;
			count++;
		}
	}
	if (count_max < 2)
		cout << 0;
	else cout << min_lenth;
		return 0;
}