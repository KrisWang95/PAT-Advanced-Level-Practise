#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string num;

void add(string t) {
	int l = num.length(), c = 0;
	for (int i = l - 1; i >= 0; i--) {
		num[i] = num[i] + t[i] + c - '0';
		c = 0;
		if (num[i] > '9') {
			num[i] -= 10;
			c = 1;
		}
	}
	if (c == 1) num = '1' + num;
}

int main() {
	
	int k, i;
	cin >> num >> k;
	for (i = 0; i <= k; i++) {
		string s = num;
		reverse(s.begin(), s.end());
		if (s == num || i == k) break;
		add(s);
	}
	cout << num << endl << i;
	system("pause");
	return 0;
 }