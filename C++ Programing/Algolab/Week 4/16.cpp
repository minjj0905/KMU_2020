#include <iostream>
#include <cmath>
using namespace std;
int t, n, ans;
int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 1;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0){
                ans = 0;
            }
        }
        cout << ans << endl;
    }
}