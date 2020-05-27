#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int t;
string s;

int check(string str) {
    stack<char> st;
        map<char, char> pair = { {'(', ')'}, {'{', '}'}, {'[', ']'} };

        for(char ch : str) {
            if(pair.find(ch) != pair.end()) {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return 0;
                }else if (ch == pair[st.top()]) {
                    st.pop();
                }else {
                    return 0;
                }
            }
        }
        if (st.empty()) {
            return 1;
        }else {
            return 0;
        }

}

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        cout << check(s) << endl;
    }
} 