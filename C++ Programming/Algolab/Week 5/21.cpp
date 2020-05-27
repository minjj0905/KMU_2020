#include <iostream>
using namespace std;
int t, n, k;
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        cin >> k;
        
        int ans[n-k+1];
        int temp = 0;
        for(int i=0; i<n-k+1; i++) {
            temp = 0;
            for(int j=i; j<k+i; j++) {
                temp += a[j];
            }
            ans[i] = temp/k;
        }
        cout << n-k+1 << " ";
        for(int i=0; i<n-k+1; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}