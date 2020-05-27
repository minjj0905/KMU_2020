#include <iostream>
using namespace std;
int tc, r, s, t;
int main(){
    cin >> tc;
    while(tc--){
        cin >> r >> s >> t;
        int a[r][s], b[s][t], res[r][t];
        for(int i=0; i<r; i++) {
            for(int j=0; j<t; j++) {
                res[i][j] = 0;
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<s; j++) {
                cin >> a[i][j];
            }
        }
        for(int i=0; i<s; i++) {
            for(int j=0; j<t; j++) {
                cin >> b[i][j];
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<s; j++) {
                for(int k=0; k<t; k++) {
                    res[i][k] += a[i][j]*b[j][k];
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<t; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}