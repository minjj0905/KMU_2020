#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char*argv[]){
    if(argc != 2){
        cout <<"usage: dice n\n";
    }
    int seed = atoi(argv[1]);
    srand(seed);
    for(int i=0; i<10; i++){
        int dice = rand()%6 +1;
        cout << dice << " ";
    }
    cout << "\n";
}