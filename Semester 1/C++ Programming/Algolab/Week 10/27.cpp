//국제표준도서번호 왜 94점이야 야발 
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;

//split 구현
vector<string> split(string str, char d) {
    vector<string> isbn_vec;
    stringstream ss(str);
    string temp;

    while(getline(ss, temp, d)) {
        isbn_vec.push_back(temp);
    }

    return isbn_vec;
}

//- 이외의 문자 체크
int check_str(vector<string> isbn) {
    for(int i=0; i<isbn.size(); i++) {
        for(int j=0; j<isbn[i].size(); j++) {
            if(!isdigit(isbn[i][j])) {
                if(!(isbn[3][0] == 'X'))
                    return 0;
            }
        }
    }
    return 1;
}

//isbn 요소 개수 체크
int count_section(vector<string> isbn) {
    if(isbn.size() != 4) return 0;
    for(int i=0; i<isbn.size(); i++) {
        if(isbn[i] == "") return 0;

    }
    return 1;
}

//각 요소 자리수 체크
int check_element_len(vector<string> isbn) {
    int element_len[4] = {5, 7, 6, 1};
    for(int i=0; i<4; i++){
        if(isbn[i].size() > element_len[i]) return 0;
    }
    return 1;
}

//checksum 값 계산
int get_checksum(vector<string> isbn) {
    int checksum, multi_11;
    int multi_num = 10, total = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<isbn[i].size(); j++) {
            int num = isbn[i][j] - '0';
            total += num * multi_num--;
            if(multi_num == 1) break;
        }
        if(multi_num == 1) break;
    }
    multi_11 = total/11 + (total%11 ? 1 : 0);
    checksum = 11*multi_11 - total;
    return checksum;
}

//check이 유효한 값인지 체크
int check_cksum(vector<string> isbn) {
    string origin_str = isbn[3];
    int origin_cksum;
    origin_cksum = origin_str[0] == 'X' ? 10 : stoi(origin_str);
    int cksum = get_checksum(isbn);
    if (cksum == origin_cksum) return 1;
    return 0;
}

int check_front_back(string s) {
    if (s[s.size()-1] == '-') return 0;
    if (s[0] == '-') return 0;
    return 1;
}

int count_dash(string s) {
    int cnt = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == '-') cnt++;
    }

    if (cnt != 3) return 0;
    return 1;
}

int check_ten(vector<string> isbn) {
    int total_len = 0;
    for(int i=0; i<isbn.size(); i++) {
        total_len += isbn[i].size();
    }
    if (total_len == 10) return 1;
    return 0;
}

//옳은 isbn인지 판별
int check_isbn(string str) {
    vector<string> isbn = split(str, '-');
    
    if (!check_ten(isbn)) return 0;
    if (!count_dash(str)) return 0;
    if (!check_front_back(str)) return 0;
    if (!count_section(isbn)) return 0;
    if (!check_element_len(isbn)) return 0;
    if (!check_str(isbn)) return 0;
    if (!check_cksum(isbn)) return 0;

    return 1;
}

string isbn;
int t;

int main() {
    cin >> t;
    while(t--) {
        cin >> isbn;
        cout << check_isbn(isbn) << endl;
    }    
}