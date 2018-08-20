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
