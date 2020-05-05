#include <iostream>
using namespace std;
int t, n, cnt;
unsigned int ans;
int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n;
        ans = n;
        while(n!=0) {
            n &= n-1;
            cnt++;
        }
        if(cnt%2!=0) {
            ans += 2147483648;
        }
        cout << ans << endl;
    }
}