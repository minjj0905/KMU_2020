#include <iostream>
using namespace std;
int main() {
    int t, y, C, N, T, I, J, K, L, P, Q, month, day;
    cin >> t;
    while(t--){
        cin >> y;
        C = y/100;
        N = y - y/19*19;
        T = (C-17)/25;
        I = (C - C/4 - (C-T)/3) + N*19+15;
        J = I- I/30*30;
        K = J - ((J/28) * (1- J/28) * (29/(J+1)) * ((21-N)/11));
        L = (y + y/4 + J + 2) - C + C/4;
        P = L - L/7*7;
        Q = K - P;
        month = (Q+40)/44 + 3;
        day = (Q+28) - month/4*31;
        cout << month << " " << day << endl;
    }
}