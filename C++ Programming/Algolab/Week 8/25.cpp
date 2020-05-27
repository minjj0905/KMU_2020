#include <iostream>
#include <bitset>
using namespace std;

class Ham {
public:
    Ham(int m, int num) {
        c = m;
        n = num;
        if (c) {
            toRealData(toBinaryStr());
        }else {
            toHamming(toBinaryStr());
        }
    }
    int getAnswer() {
        return ans;
    }

private:
    int ans;
    int n, c;
    string toBinaryStr() {
        return bitset<32>(n).to_string();;
    }

    void toDecimalInt(string b) {
        ans = bitset<32>(b).to_ulong();;
    }

    int count(const string &s, int n) {
        int cnt = 0;
        int check = 0;

        for(int i=s.length() - n; i >= 0; i--) {
            check++;
            if(s[i] == '1') {
                cnt++;
            }
            if(check == n) {
                check = 0;
                i -= n;
            }
        }
        return cnt;
    }

    void toHamming(string b) {
        string hammingcode;
        int cnt;
        int pos = b.length() - 1;
        for (int i=1; i<32; i++) {
            if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) {
                hammingcode.insert(0, 1, 'p');
            }else {
                hammingcode.insert(0, 1, b[pos]);
                pos--;
            }
        }
        for (int i=1; i<=16; i<<=1) {
            cnt = count(hammingcode, i);
            if (cnt%2) { 
                hammingcode[hammingcode.length() - i] = '1';
            }else {
                hammingcode[hammingcode.length() - i] = '0';
            }
        }
        toDecimalInt(hammingcode);
    }

    void toRealData(string b) {
        string realdata;
        int cnt, errorcnt;
        int p = 0;
        int errorbit = 0;
        int error[5] = {0};
        for(int i=1; i<=16; i<<=1) {
            cnt = count(b, i);
            if(cnt%2) {
                errorcnt++;
                error[p++] = i;
            }
        }

        if(errorcnt) {
            for(int i=0; i<5; i++) {
                errorbit += error[i];
            }
            b[b.length() - errorbit] = '1';
        }

        for(int i=1; i<b.length(); i++) {
            if(!(i == 1 || i == 2 || i == 4 || i == 8 || i == 16)) {
                realdata.insert(0, 1, b[b.length() - i]);
            }
        }

        toDecimalInt(realdata);
    }

};

int main() {
    int t, c, n;
    cin >> t;
    while(t--) {
        cin >> c >> n;
        Ham ham(c, n);
        cout << ham.getAnswer() << endl;
    }
}