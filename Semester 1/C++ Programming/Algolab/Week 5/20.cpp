#include <iostream>
#include <algorithm>
using namespace std;
int t, n, s, cnt;
unsigned int a[132], b[132], res[132];

int main() {
    cin >> t;
    while(t--) {
        for(int i=0; i<132; i++) {
            a[i] = 0;
            b[i] = 0;
        }
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s;
            a[s] = 1;
        }
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s;
            b[s] = 1;
        }

        //1
        cnt = 0;
        for(int i=0; i<132; i++) {
            res[i] = a[i]&b[i];
            if (res[i] == 1) {
                cnt ++;
            }
        }
        cout << cnt << " ";
        for(int i=0; i<132; i++) {
            if (res[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;

        //2
        cnt = 0;
        cnt = 0;
        for(int i=0; i<132; i++) {
            res[i] = a[i]|b[i];
            if (res[i] == 1) {
                cnt ++;
            }
        }
        cout << cnt << " ";
        for(int i=0; i<132; i++) {
            if (res[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;


        //3
        cnt = 0;
        for(int i=0; i<132; i++) {
            res[i] = 0;
            if ((a[i]&(~b[i])) == 1) {
                res[i] = a[i]&(~b[i]);
                cnt ++;
            }
        }
        cout << cnt << " ";
        for(int i=0; i<132; i++) {
            if (res[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}