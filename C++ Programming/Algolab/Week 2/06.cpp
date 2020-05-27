#include <iostream>
using namespace std;
int t, n, H, M, S, h, m, s, sum;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        sum = 0;
        while(n--){
            cin >> H >> M >> S >> h >> m >> s;
            sum += (h-H)*3600 + (m-M)*60 + (s-S);
        }
        cout << (sum/3600)/24 << " " << (sum/3600)%24 << " " << (sum/60)%60 << " " << sum%60 << endl;
    }
}