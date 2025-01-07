#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long ans=0;

long long  N,M,c[32];
long long mc[100100], ms=1;

long long  cost(int n){
    if(n<=ms){
        return mc[n];
    }
    for(int i=ms+1; i<=n; i++){
        long long  maxN=0;
        for(int j=1; j<=N && j<=i; j++){
            if(maxN < mc[i-j]+ c[j-1]){
                maxN = mc[i-j]+ c[j-1];
            }
        }
        mc[i] = maxN;
    }
    return mc[n];
}

int main(){
    cin >> N;
    for(int i=0;i<N; i++)
        cin >> c[i];
    mc[1] = c[0];
    cin >> M;
    string str;
    cin >> str;
    int i = 0;
    while(i<M-2){
        if(str[i]=='a' && str[i+1]=='b' && str[i+2]=='c'){
            int k=1;
            i+=3;
            while(i<M-2 && str[i]=='a' && str[i+1]=='b' && str[i+2]=='c'){
                k++;
                i+=3;
            }
            ans += cost(k);
        }
        i++;
    }

    cout << ans << endl;
    return 0;
}