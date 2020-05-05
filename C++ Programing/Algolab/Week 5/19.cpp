#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int t, n, i;
set<int> s;
unsigned int h[1350];

int main() {
    cin >> t;
    i = 1;
    for(int cnt=0; cnt<1350; cnt++) {
        if(cnt == 0) {
            h[0] = 1;
        }else {
            s.insert(2*i);
            s.insert(3*i);
            s.insert(5*i);
            auto it = s.begin();
            h[cnt] = *it;
            s.erase(*it);
            i = h[cnt];
        }
    }
    while(t--) {
        cin >> n;
        cout << h[n-1] << endl;
    }
}