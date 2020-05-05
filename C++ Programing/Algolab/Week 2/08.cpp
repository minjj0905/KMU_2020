#include <iostream>
using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int y=0; y<n/2+1; y++){
            for(int x=0; x<y; x++) cout << "-";
            cout << "*";
            for(int x=0; x<n/2-y; x++) cout << "+*";
            for(int x=0; x<y; x++) cout << "-";
            cout << endl;
        }
        for(int y=n/2-1; y>=0; y--){
            for(int x=0; x<y; x++) cout << "-";
            cout << "*";
            for(int x=0; x<n/2-y; x++) cout << "+*";
            for(int x=0; x<y; x++) cout << "-";
            cout << endl;
        }
    }
}