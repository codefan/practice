#include <iostream>
using namespace std;

int main(){
    long long n,  p=2,ps, ans=0;
    cin >> n;
    while(p*p <= n){
        ps = 0;
        while(n % p ==0){
            n /= p;
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