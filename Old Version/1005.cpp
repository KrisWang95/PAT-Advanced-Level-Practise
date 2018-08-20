#include<iostream>
#include<string>
using namespace std;
string numToWords[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
int stringToNumAndSum(string a,int *b) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		b[i] = a[i] - '0';
		sum += (a[i] - '0');
	}
	return sum;
}
int ArrayToNumAndCount(int a, int *b) {
	int i;
	for (i = 0; a!=0; i++) {
		b[i] = a % 10;
		a /= 10;
	}
	return i;
}
int main() {
	string a;
	int num[100],sum,t;
	cin >> a;
	sum = stringToNumAndSum(a, num);
	t = ArrayToNumAndCount(sum, num);
	for (int i = t-1; i > 0; i--) 
		cout << numToWords[num[i]] << " ";
	cout << numToWords[num[0]];
	system("pause");
}