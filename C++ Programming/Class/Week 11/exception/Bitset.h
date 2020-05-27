//BitSet.h
#include <iostream>
#include <exception>
#include "Bvector.h"
class IncompatibleException : public std::exception{
  public:
    int n1, n2;
    IncompatibleException(int num1, int num2) : n1(num1), n2(num2) {};
};
class BitSet : public Bvector {
  public:
    BitSet(int sz=32);
void insert(int v);
friend BitSet operator+(const BitSet& v1, const BitSet& v2);
friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};