#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> wq[1050];
int cnt[1050] = {0};

long long calc(int mx, int n){
    long long ans = 0;
    vector<int> temp;
    int ps = cnt[1];
    for(int i=2; i<=n; i++){
        if(cnt[i]>0){
            int j=0;
            while(j < cnt[i] - mx + 1){
                ans += wq[i][j];
                j++;
                ps ++;
            }
            while(j < cnt[i]){
                temp.push_back(wq[i][j]);
                j++;
            }
        }
    }
    if(ps<mx){
        sort(temp.begin(), temp.end());
        for(int i=0; i<mx-ps; i++){
            ans += temp[i];
        }
    }
    return ans;
}

int main(){
    int n, m, p, s, maxW=0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> p >> s;
        cnt[p] ++;
        wq[p].push_back(s);
    }

    for(int i=2; i<=n; i++){
        if(cnt[i]>0){
            sort(wq[i].begin(), wq[i].end());
        }
        if(maxW < cnt[i]){
            maxW = cnt[i];
        }
    }
    
    long long ans = calc(maxW+1,n);
    int b = cnt[1]>0?cnt[1]:1;
    for(int i =b; i<=maxW; i++){
        long long t = calc(i, n);
        if(t<ans){
            ans = t;
        }
    }
    cout << ans << endl;
    return 0;
}