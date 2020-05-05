#include <iostream>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    int sums[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int nums[n];
        for (int j=-0; j<n; j++)
        {
            cin >> nums[j];
        }
        int sum = 0;
        for (int k=0; k<n; k++)
        {
            sum += nums[k];
        }
        sums[i] = sum;
    }
    for (int i=0; i<t; i++)
    {
        cout << sums[i] << endl;
    }
}