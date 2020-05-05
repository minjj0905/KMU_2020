#include <iostream>
#include <cstring>
using namespace std;

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

int Kvector::total_len = 0;

Kvector::Kvector(int sz, int value) {
    if(sz==0) clear();
    else {
        total_len += sz;
        len = sz;
        m = new int[len];
        for(int i=0; i<len; i++) m[i] = value;
    }
    cout << this << " : Kvector(int)" << endl;
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
    const Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();

    cout << "total length = " << Kvector::total_len << endl;
    v2.print();
    v3.print();
    cout << "total length = " << Kvector::total_len << endl;
    return 0;
}