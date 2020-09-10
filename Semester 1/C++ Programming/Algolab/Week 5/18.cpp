#include <iostream>
using namespace std;
int t, r, c;
int main() {
    cin >> t;
    while(t--) {
        cin >> r >> c;
        int a[r][c], b[r][c];

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> a[i][j];
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> b[i][j];
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout << a[i][j] + b[i][j] << " ";
            }
            cout << endl;
        }
    }
}