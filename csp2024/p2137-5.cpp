#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
vector<int> qu;
int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i <n; i++){
        cin >> a >> b;
        if(a > b){
            qu.push_back(a);
            qu.push_back(b);
        }
    }
    sort(qu.begin(), qu.end(), greater<int>());
    long long ans = 0, sign = 1;
    for (int i=0; i < qu.size(); i++){
        ans += qu[i] * sign;
        sign *= -1;
    }
    cout << ans << endl;
    return 0;
}