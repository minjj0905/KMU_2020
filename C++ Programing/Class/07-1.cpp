#include <iostream>
using namespace std;

int main(){

    float f = 97;

    float *f_p;
    int *i_p;

    f_p = &f;
    cout << "*f_p = " << *f_p << endl;

    i_p = (int *)&f;
    cout << "*i_p = " << *i_p << endl;

    return 0;
}