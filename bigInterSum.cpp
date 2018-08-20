#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string a, string b) {

	int i = a.length() - 1, j = b.length() - 1, carry = 0;

	string res;

	while (i >= 0 || j >= 0 || carry == 1) {

		char temp = ((i >= 0 ? a[i] : '0') + (j >= 0 ? b[j] : '0') - '0' + carry);

		carry = 0;

		if (temp > '9') {

			temp -= 10;

			carry = 1;

		}

		res = temp + res;

		i--;

		j--;

	}
	
	return res;

}
int main(){

	string a,b;

	cin >> a >> b;
	
	cout << add(a, b);

	system("pause");
	return 0;

}
