#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int a[100100];
vector<int> ab[100100];
int N,M,K;
int main(){
    cin >> M >> N >> K;
    for(int i=0; i<N; i++){
        cin>> a[i];
    }
    int c;
    for(int i=0; i<N; i++){
        cin>> c;
        ab[a[i]].push_back(c);
    }
    int ans =0, maxM=0;
    for(int i=1; i<=M; i++){
        sort(ab[i].begin(), ab[i].end(), greater<int>() );
        int x = 0; 
        int allK=0;
        for(vector<int>::iterator it = ab[i].begin(); it< ab[i].end(); it++){
            allK+= *it;
            x++;
            if(allK>=K) break;
        }
        if(allK<K){
            cout << -1 << endl;
            return 0;
        }
        if(x>maxM) maxM = x;
        ans += x;
    }
    if(maxM + maxM -1 > ans){
        if(maxM + maxM -1 <= N){
            cout << maxM+ maxM -1 << endl;
        }else{
            cout << -1 << endl;
        }
    } else {
        cout<< ans << endl;
    }
    return 0;
}