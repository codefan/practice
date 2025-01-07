#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int p, ans = 0;
    int com[2][130];
    memset(com, 1, sizeof(com));
    for(int i=0; i<10; i++){
        cout << com[0][i] << ' ';
    }
    cout << endl;
    p= 1 + (1<< 8) + (1<< 16) +  (1<< 24);
   
    cout << p << endl;
    return 0;
}