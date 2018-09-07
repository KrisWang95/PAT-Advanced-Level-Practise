/*
1005 Spell It Right (20)（20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:

12345
Sample Output:

one five
*/
//简单的字符串处理以及数字拆分
#include<iostream>
#include<string>

using namespace std;

int numSum(string a){

	int sum = 0;

	for(int i = 0 ; i < a.length(); i++){

		sum += (a[i] - '0');

	}
	return sum;
}

int numToArr(int a,int *b){

	int i = 0;

	while(a!=0){

		b[i++] = a%10;

		a /=10;

	}

	return i;
}

int main(){

	string num;

	string str[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

	cin >> num;

	int n[100],k;

	k = numToArr(numSum(num),n);

	cout << str[n[k-1]] ;

	for(int i = k-2;i >= 0 ;i --){

		cout << " " << str[n[i]] ;

	}

	return 0;
}
