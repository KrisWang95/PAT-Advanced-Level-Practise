/*
1001 A+B Format (20)
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

//正则表达式和数字转字符串的应用；
//仅支持c++11以上 ； 

#include<iostream> 
#include<string>
#include<algorithm>
#include <sstream>
#include<regex>
using namespace std;

int main(){

	std::ios::sync_with_stdio(false);
	
	long a, b, c;

	cin >> a >> b ;

	c = a + b;
	
	string s = to_string(c);
	
	regex pattern("(\\d)(?=(\\d{3})+(?!\\d))");

	cout << regex_replace(s,pattern,"$1,");
	
	return 0; 
	
}
