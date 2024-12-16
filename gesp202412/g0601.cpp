#include <iostream>
using namespace std;
char step[10000000];
int main(){
    int n, s=0;
    long long p;
    cin >> n >> p;
    char c;
    while(n--){
        cin >> c;
        if(c == 'U' && s>0 && step[s-1]!='U'){
            s--;
        } else {
            step[s] = c;
            s++;
        }
    }

    for(int i=0; i<s; i++){
        switch(step[i]){
            case 'U':
                if(p>1){
                    p /= 2;
                }
                break;
            case 'R':
                p = p*2+1;
                break;
            case 'L':
                p = p*2;
                break;
        }
    }
    cout << p << endl;
    return 0;
}
