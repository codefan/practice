#include <iostream> // 标准输入输出流 cin、cout 所在的库
#include <cstdio>  // 标准输入输出文件 stdin、stdout和相关函数fgets、fputs所在的文件
#include <cstring> 
#include <cmath> 
#define ML 100000
using namespace std;

int sq(int k){
   return sqrt(k) + 0.05;
}

int main(){
   int n;
	cin>>n;
	int s = sq(n);
	if(s * s==n){
		cout << 1 << endl;
		return 0;
	}
	for(int i=1;i<=s;i++)
	{
		int s1 = sq(n - i*i);
		if(s1 * s1 ==n-i*i){
			cout << 2 << endl;
			return 0;
		}
	}
	for(int i=1; i<=s; i++)
	{
		for(int j=i; j<=s; j++)
		{
			int s1=sq(n - i*i - j*j);
			if(s1*s1 == n - i*i - j*j){
				cout << 3 << endl;
				return 0;
			}
		}
	}
	cout << 4 << endl;
	return 0;
}