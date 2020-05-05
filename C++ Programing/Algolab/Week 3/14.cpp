#include <iostream>
#include <algorithm>
using namespace std;
int t, x1, x2, y1, y2, p, q;

int pow(int n){
    return n*n;
}

int abs(int n){
    if (n<0) return -n;
}

int main(){
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> p >> q;

        if(x1<=p && p<=x2 && y1<=q && q<=y2) cout << "0 0" << endl;
        else{
            if(x1<=p && p<=x2){
                cout << pow(min(abs(y1-q), abs(y2-q))) << " " << min(abs(y1-q), abs(y2-q)) << endl;
            }else if(y1<=q && q<=y2){
                cout << pow(min(abs(x1-p), abs(x2-p))) << " " << min(abs(x1-p), abs(x2-p)) << endl;
            }else{
                cout << min(pow(x1-p), pow(x2-p)) + min(pow(y1-q), pow(y2-q)) << " ";
                cout << min(abs(x1-p), abs(x2-p)) + min(abs(y1-q), abs(y2-q)) << endl;
            }
        }
    }
}