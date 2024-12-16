#include <iostream>
using namespace std;
char step[10000000];
int main(){
    int n, s=100;
    long long p;
    cin >> n >> p;
    while(p>0){
        if(p%2)
            step[s]=1;
        p/=2;
        s--;
    }
    int b=s+1, e=101;
    char c;
    while(n--){
        cin >> c;
        switch(c){
            case 'U':
                if(e>b+1){
                    e--;
                }
                break;
            case 'R':
                step[e] = 1;
                e++;
                break;
            case 'L':
                step[e] = 0;
                e++;
                break;
        }
    }
    p = 0;
    for(int i=b; i<e; i++){
        p = p *2 + step[i];
    }
    cout << p << endl;
    return 0;
}
