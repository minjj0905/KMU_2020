#include <iostream>
using namespace std;
int t, m, n;
int main() {
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cout << (n*(n+1) - m*(m-1))/2 << endl;
    }
}