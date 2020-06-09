//Kvector.h
#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__

template<class T>
class Kvector{
protected:
    T *m;
    int len;
public:
    Kvector(int sz = 0, T value = 0);
    Kvector(const Kvector& v);
virtual ~Kvector();
    T sum() const {
        T s;
        for(int i=0; i<len; i++) s+=m[i];
        return s;
    }
virtual void print() const{
    std::cout << "Kvector: ";
    for (int i=0; i<len; i++) std::cout << m[i] << " ";
    std::cout << std::endl;
    }
    void clear(){ delete[] m; m = NULL; len = 0; }
    int size() const { return len; }
Kvector& operator=(const Kvector& v);
bool operator==(const Kvector& v);
bool operator!=(const Kvector& v);
T& operator[](int idx){ return m[idx]; }
const int& operator[](int idx) const { return m[idx]; }
friend std::ostream& operator<<(std::ostream& os, const Kvector& v) {
    for(int i=0; i<v.len; i++) os << v.m[i] << " ";
     return os;
}
};
#include "Kvector.cpp"
#endif