#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int l[100100];
int r[100100];
int rev[100100];

void dfs(int k, int f){
    if(k==0) return;
    if(f){
        rev[k] = rev[k] ^ 1;
    }
    dfs(l[k], rev[k]);
    dfs(r[k], rev[k]);
}

int main(){
    int n, q, c;
    string str;
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> c;
        if(l[c]==0){
            l[c] = i;
        } else {
            r[c] = i;
        }
    }
    cin >> str;
    cin >> q;
    while(q--){
        cin >>c;
        rev[c] = rev[c] ^ 1;
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++){
        if(rev[i] && str[i-1] == '1' || !rev[i] && str[i-1] == '0' ){
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout<<endl;
    return 0;
}