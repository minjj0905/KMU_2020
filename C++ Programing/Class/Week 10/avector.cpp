#include <iostream>
#include <cstring>
using namespace std;

class Kvector {
protected:
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0) : len(sz) {
        cout << this << " : Kvector(" << sz << "," << value << ")\n";
        if(!sz) {
            m = NULL;
            return;
        }
        m = new int[sz];
        for(int i=0; i<sz; i++) m[i] = value;
    }

    Kvector(const Kvector& v) {
        cout << this << " : Kvector(*" << &v << ")\n";
        len = v.len;
        if(!len) {
            m = NULL;
            return;
        }
        m = new int[len];
        for(int i=0; i<len; i++) m[i] = v.m[i];
    }

    ~Kvector() {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    
    int& operator[](int idx);
    Kvector& operator=(const Kvector& k);
    friend bool operator==(const Kvector& a, const Kvector& b);
    friend ostream& operator<<(ostream& os, const Kvector& k);

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


#define N 3
class Avector : public Kvector {
    char table[N];
public:
    Avector(int sz=0, int v=0, const char *t="abc") : Kvector(sz, v){
        cout << this << " : Avector(" << sz << "," << v << "," << t << ")\n";
        setTable(t);
    }

    void setTable(const char *t){
        for(int i=0; i<3; i++){
            table[i] = t[i];
        }
    }
    
    friend ostream& operator<<(ostream& os, const Avector& v);
};

ostream& operator<<(ostream& os, const Avector& v){
    for(int i=0; i<v.len; i++) {
        os << v.table[v.m[i]%3] << " ";
    }
    return os;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "usage : ./avector pqr\n";
        return 1;
    }

    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();

    cout << "v1 == v2 " << (v1 == v2) << endl;
    cout << "v3 == v2 " << (v3 == v2) << endl;

    v3 = v2 = v1;

    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();

    cout << "v3 != v2 " << (v3 != v2) << endl;
    
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);

    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}