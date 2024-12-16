
#include <iostream>
#include <cmath>
using namespace std;

long long pn[1000000];

int simple(long long maxN){
    pn[0] = 2;
    int pSum = 1;
    for(int i=3; i<=maxN; i++){
        bool isP = true;
        for(int j=0; pn[j]*pn[j]<=i; j++){
            if(i % pn[j]==0){
                isP = false;
                break;
            }
        }
        if(isP){
            pn[pSum++]=i;
        }
    }
    return pSum ;
}

int main(){
    long long n,  p=0,ps, ans=0;
    cin >> n;
    long long ghn = sqrt(n)+1;
    int pc = simple(ghn);
    while(p<pc && pn[p]*pn[p] <= n){
        ps = 0;
        while(n % pn[p] ==0){
            n /= pn[p];
            ps++;
        }
        if(ps>0){
            int c = 0;
            while(ps>c){
                c++;
                ps -= c;
            }
            ans += c;
        }
        p++;
    }
    if(n>1){
        ans ++;
    }
    cout << ans << endl;
    return 0;
}