/*
1001. A+B Format (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/ 


#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b;
    c=a+b,d=abs(c);
    if(d<1000)
        printf("%d\n",c);
    else if(d<1000000)
        printf("%d,%03d",c/1000,d%1000);
    else
        printf("%d,%03d,%03d",c/1000000,(d%1000000)/1000,d%1000);
    return 0;
}

