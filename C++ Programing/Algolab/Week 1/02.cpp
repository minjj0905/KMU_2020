#include <iostream>
using namespace std;
int main() {
    int t, n, s, mn, mx;
    cin >> t;
    mx, mn = 0;
    while (t--){
        cin >> n;
        for (int i=0; i<n; i++) {
            if (i==0) {
                cin >> s;
                mx = s;
                mn = s;
            }
            else {
                cin >> s;
                if (s>mx) mx = s;
                if (s<mn) mn = s;
            }
        }
        cout << mx << " " << mn << endl;
    }
}