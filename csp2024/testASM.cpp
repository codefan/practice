#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a = 10;
 
int getA() {
    int result;
    // 嵌入汇编代码
    asm volatile (
        "movl %1, %%eax\n" // 将变量a的地址放入eax寄存器
        "movl %%eax, %0\n" // 将eax寄存器的内容放入result
        : "=m"(result)     // 输出操作数，result的内存值
        : "m"(a)           // 输入操作数，a的内存值
        : "%eax"           // 被修改的寄存器，eax
    );
    return result;
}
 
int main() {
    int val = getA();
    // 输出变量a的值
    printf("The value of a is: %d\n", val);
    return 0;
}