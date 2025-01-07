#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long ans=0;
int cost[500500];
int temp[500500];

void mergeSort(int b, int e){
    if(b>=e-1) return;
    int mid = (b+e)/2;
    mergeSort(b,mid);
    mergeSort(mid,e);
    int i=b, j=mid, t=b;
    while(i<mid && j<e){
        if(cost[i] < cost[j]){
            ans += mid-i;
            temp[t++] = cost[j++];
        } else {
            temp[t++] = cost[i++];
        }
    }
    while(i<mid){
        temp[t++] = cost[i++];
    }
    while(j<e){
        temp[t++] = cost[j++];
    }
    memcpy(cost+b, temp+b, sizeof(int)* (e-b));
}

int main(){
    int N;
    cin >> N ;
    for(int i=0; i<N; i++){
        cin >> cost[i];
    }
    mergeSort(0, N);
    cout << ans << endl;
    return 0;
}