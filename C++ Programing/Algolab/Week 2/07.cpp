#include <iostream>
using namespace std;
int t, k, n;
int main(){
    cin >> t;
    while(t--){
        cin >> k;
        for(int i=1; i<k+1; i++){
            n = i;
            for(int j=0; j<i; j++){
                cout << n << " ";
                n += k-j-1;
            }
            cout << endl;
        }
    }
}