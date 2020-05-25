#include <iostream>
#include "Bitset.h"
using namespace std;

BitSet::BitSet(int sz): Bvector(sz){}

void BitSet::insert(int v) {
    set(v);
    }

BitSet operator+(const BitSet& v1, const BitSet& v2) {
    BitSet r(v1.NBITS);
    for(int i=0; i<r.len; i++) {
        r.u_m[i] = v1.u_m[i] | v2.u_m[i];
    }
    return r;
}

ostream& operator<<(ostream& os, const BitSet& s){
    cout << "{ ";
    for(int i=0; i<s.NBITS; i++) {
        if(s[i]) cout << i << " ";
    }
    cout << "}";
    return os;
}

int main(int argc, char *argv[]){
    BitSet b1(131), b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    cout << "b1+b2= " << b1+b2 << endl;
}