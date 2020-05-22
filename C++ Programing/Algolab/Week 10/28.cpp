#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

unsigned int t, c;
string str, res;

vector<string> split(string s, char d) {
    vector<string> bytes;
    stringstream ss(s);
    string temp;

    while(getline(ss, temp, d)) {
        bytes.push_back(temp);
    }

    return bytes;
}

string toBinaryStr_32(int n) {
    return bitset<32>(n).to_string();
}

string toBinaryStr_8(int n) {
    return bitset<8>(n).to_string();
}

unsigned int toDecimalInt_32(string s) {
    return bitset<32>(s).to_ulong();
}

int toDecimalInt_8(string s) {
    return bitset<8>(s).to_ulong();
}

string make_dec(string s) {
    vector<string> bytes = split(s, '.');
    string ipv4[4];
    for(int i=0; i<4; i++) {
        ipv4[i] = toBinaryStr_8(stoi(bytes[i]));
    }

    string result = "";
    for(int i=0; i<4; i++) {
        result += ipv4[i];
    }

    stringstream ss;
    ss << toDecimalInt_32(result);
    return ss.str();
}

string make_ipv4(string s) {
    string binary = toBinaryStr_32(stoul(s));
    int ipv4[4];
    int start = 0, gap = 8;
    
    for(int i=0; i<4; i++){
        ipv4[i] = toDecimalInt_8(binary.substr(start, start+8));
        start += gap;
    }

    stringstream ss;
    ss << ipv4[0] << '.' << ipv4[1] << '.' << ipv4[2] << '.' << ipv4[3];

    return ss.str();

}

string get_answer(int c, string s) {
    string answer;
    if(c == 1) answer = make_dec(s);
    if(c == 2) answer = make_ipv4(s);
    return answer;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> c >> str;
        cout << get_answer(c, str) << endl;
    }
}

