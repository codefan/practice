#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int cost[100100];
int main(){
    int N, L, c, l;
    cin >> N >> L;
    memset(cost+1, 0x3f, sizeof(int) * (L+5));
    for(int i=0; i<N; i++){
        cin >> c >> l;
        for(int j=L;  j>0; j-- ){
            int bp = j-l>0?j-l : 0;
            if(cost[j] > cost[bp] + c){
                cost[j] = cost[bp] + c;
            }
        }
    }
    if(cost[L]==cost[L+2]){
        cout << "no solution" << endl;
    }else {
        cout << cost[L] << endl;
    }
    return 0;
}