#include <iostream> // 标准输入输出流 cin、cout 所在的库
#include <cstdio>  // 标准输入输出文件 stdin、stdout和相关函数fgets、fputs所在的文件
#include <cstring> 
using namespace std;
int main(){
   
   int num[1000];
   int l = 0;
   int n;
   cin >> n;
   while(n !=1){
      num[l++] = n;
      if(n%2==0)
         n >>= 1;
      else 
         n = n*3+1;
   }
   cout <<1;
   for(int i=l-1; i>=0; i--)
      cout <<' '<<num[i];
   cout << endl;

   return 0;
}
