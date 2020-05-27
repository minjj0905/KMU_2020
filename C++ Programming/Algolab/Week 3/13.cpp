#include <iostream>
using namespace std;
int t, ax, ay, bx, by, cx, cy, ans;

int abs(int n){
    if (n<0){
        return -n;
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        ans = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);

        cout << abs(ans) << " ";
        if (ans>0) cout << 1 << endl;
        else if (ans<0) cout << -1 << endl;
        else cout << 0 << endl;
    }
}