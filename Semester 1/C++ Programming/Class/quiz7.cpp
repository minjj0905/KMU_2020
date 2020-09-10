#include <iostream>
using namespace std;

int main(){
    double d;

    cout << "d의 주소 = " << &d << endl;

    d = 3.141592;

    char *cp = (char *)&d;
    int *ip = (int *)&d;
    float *fp = (float *)&d; 
    double *dp = &d;

    cout << "값 선언한 d의 주소 = " << &d << endl;
    cout << "*cp = " << *cp << endl;
    cout << "*ip = " << *ip << endl;
    cout << "*fp = " << *fp << endl;
    cout << "*dp = " << *dp << endl;

    cout << "주소" << &d << endl;
}