#include <iostream>
using namespace std;
int t, n, ans;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n][2];
        ans = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i][0] >> arr[i][1];
        }
        for(int i=0; i<n-1; i++){
            ans += (arr[i][0]*arr[i+1][1] - arr[i][1]*arr[i+1][0]);
        }
        ans += arr[n-1][0]*arr[0][1] - arr[n-1][1]*arr[0][0];
        if(ans<0){
            cout << -ans << " " << -1 << "\n";
        }else{
            cout << ans << " " << 1 << "\n";
        }
    }
    
} 