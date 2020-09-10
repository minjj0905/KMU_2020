#include <iostream>
using namespace std;
int t, n, i, j, k;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i==n/2 && j==n/2) cout << "O";
                else if(i==n/2) cout << "+";
                else if(j==n/2) cout << "I";
                else if(i+j==n-1) cout << "*";
                else cout << ".";
            }
            cout << endl;
        }
    }
}