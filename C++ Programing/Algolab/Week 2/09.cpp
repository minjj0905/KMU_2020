#include <iostream>
using namespace std;
int t, n, temp, ans;
int main(){
    cin >> t;
    while(t--){
        ans = 1;
        cin >> n;
        while(n--){
            cin >> temp;
            temp = temp%10;
            ans *= temp;
            ans = ans%10;
        }
        cout << ans << endl;
    }
}