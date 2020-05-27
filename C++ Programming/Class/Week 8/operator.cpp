#include <iostream>
#include <cstring>
using namespace std;

// =, ==, !=, [], <<

class Kvector {
    int *m;
    int len;
public:
    static int total_len;
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector() {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    int& operator[](int idx);
    Kvector& operator=(const Kvector& k);
    friend bool operator==(const Kvector& a, const Kvector& b);
    friend ostream& operator<<(ostream& os, const Kvector& k);

    void print() {
        for(int i=0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void print() const {
        for(int i=0; i<len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size() { return len; }
    
};

//연산자 구현
Kvector& Kvector::operator=(const Kvector& k){
    len = k.len;
    m = new int[len];
    for(int i=0; i<len; i++){
        m[i] = k.m[i];
    }
    return *this;
}

bool operator==(const Kvector& a, const Kvector& b){
    bool ret;
    ret = a.len==b.len;
    if(ret){
        for(int i=0; i<a.len; i++){
            if (a.m[i] != b.m[i]) return 0;
        }
        return 1;
    }else {
        return 0;
    }
}

bool operator!=(const Kvector& a, const Kvector& b){
    return !(a==b);
}

ostream& operator<<(ostream& os, const Kvector& k){
    for(int i=0; i<k.len; i++) {
        os << k.m[i] << " ";
    }
    return os;
}

int& Kvector::operator[](int idx){
    return m[idx];
}

// 연산자구현 끝

int Kvector::total_len = 0;

Kvector::Kvector(int sz, int value) : len(sz) {
    if(sz==0) clear();
    else {
        total_len += sz;
        len = sz;
        m = new int[len];
        for(int i=0; i<len; i++) m[i] = value;
    }
    cout << this << " : Kvector(int, int)" << endl;
}

Kvector::Kvector(const Kvector& v){
    len = v.len;
    total_len += len;
    m = new int[len];
    for(int i=0; i<len; i++) m[i] = v.m[0];
    cout << this << " : Kvector(Kvector&)" << endl;
}

int main() {
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();

    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    return 0;
}