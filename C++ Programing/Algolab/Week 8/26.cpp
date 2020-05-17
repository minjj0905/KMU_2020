#include <iostream>
using namespace std;

unsigned int t, num1, num2;

int getHammingWeight(unsigned int n) {
    int cnt = 0;
    for(int i=0; i<32; i++) {
        unsigned int ck = 1;
        ck = ck << i;
        if(ck&n) {
            cnt++;
        }
    }
    return cnt;
}

int getHammingDistance(unsigned int n1, unsigned int n2) {
    int cnt = 0;
    for(int i=0; i<32; i++) {
        unsigned int ck = 1;
        ck = ck << i;
        if((ck&n1)^(ck&n2)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> num1 >> num2;
        
        cout << getHammingWeight(num1) << " " << getHammingWeight(num2) << " " << getHammingDistance(num1, num2) << endl;
    }
}