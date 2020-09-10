#include <iostream>

using namespace std;

int Cross()
{
	int arr1[4] = { 0, };
	int arr2[4] = { 0, };

	for (int i = 0; i < 4; i++)
		cin >> arr1[i];

	int check = 0;
	for (int i = 0; i < 4; i++) {
		cin >> arr2[i];
	}

	if (arr1[0] == arr1[2]) {
		if (arr1[0] == arr2[0] || arr1[0] == arr2[2] || arr1[2] == arr2[0] || arr1[2] == arr2[2]) {
			if ((arr1[1] <= arr2[1] && arr2[1] <= arr1[3]) || (arr1[3] <= arr2[1] && arr2[1] <= arr1[1])) check = 2;
		}
		if (arr1[1] == arr2[1] || arr1[1] == arr2[3] || arr1[3] == arr2[1] || arr1[3] == arr2[3]) {
			if ((arr2[0] <= arr1[0] && arr1[0] <= arr2[2]) || (arr2[2] <= arr1[0] && arr1[0] <= arr2[0])) check = 2;
		}
	}

	if (arr1[1] == arr1[3]) {
		if (arr1[1] == arr2[1] || arr1[1] == arr2[3] || arr1[3] == arr2[1] || arr1[3] == arr2[3]) {
			if ((arr1[0] <= arr2[0] && arr2[0] <= arr1[2]) || (arr1[2] <= arr2[0] && arr2[0] <= arr1[0])) check = 2;
		}
		if (arr1[0] == arr2[0] || arr1[0] == arr2[2] || arr1[2] == arr2[0] || arr1[2] == arr2[2]) {
			if ((arr2[1] <= arr1[1] && arr1[1] <= arr2[3]) || (arr2[3] <= arr1[1] && arr1[1] <= arr2[1])) check = 2;
		}
	}
	if (check != 2) {

		if (arr1[0] == arr1[2]) {
			if (((arr1[1] < arr2[1] && arr2[1] < arr1[3]) || (arr1[3] < arr2[1] && arr2[1] < arr1[1])) && ((arr2[0] < arr1[0] && arr1[0] < arr2[2]) || (arr2[2] < arr1[0] && arr1[0] < arr2[0])))
				check = 1;
		}

		if (arr1[1] == arr1[3]) {
			if (((arr2[1] < arr1[1] && arr1[1] < arr2[3]) || (arr2[3] < arr1[1] && arr1[1] < arr2[1])) && ((arr1[0] < arr2[0] && arr2[0] < arr1[2]) || (arr1[2] < arr2[0] && arr2[0] < arr1[0])))
				check = 1;
		}
	}

	return check;
}


int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cout << Cross() << endl;
	}
}