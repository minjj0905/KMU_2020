#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int Type()
{
	int arr[6] = { 0, };
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	int tmp[3];
	tmp[0] = (arr[2] - arr[0])*(arr[2] - arr[0]) + (arr[3] - arr[1])*(arr[3] - arr[1]);
	tmp[1] = (arr[4] - arr[0])*(arr[4] - arr[0]) + (arr[5] - arr[1])*(arr[5] - arr[1]);
	tmp[2] = (arr[4] - arr[2])*(arr[4] - arr[2]) + (arr[5] - arr[3])*(arr[5] - arr[3]);

	sort(tmp, tmp + 3);


	float a_ = sqrt(tmp[0]);
	float b_ = sqrt(tmp[1]);
	float c_ = sqrt(tmp[2]);

	if (a_ + b_ <= c_) return 0;
	if (tmp[0] + tmp[1] == tmp[2]) return 1;
	if (tmp[0] + tmp[1] < tmp[2]) return 2;
	if (tmp[0] + tmp[1] > tmp[2]) return 3;
}

int main()
{
	int testcase = 0;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
		cout << Type() << endl;

	return 0;
}