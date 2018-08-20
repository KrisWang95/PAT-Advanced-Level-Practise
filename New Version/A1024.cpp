#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

string add(string a,string b) {
	string res = "";
	int k = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char temp = (a[i] + b[i] - '0' + k);
		k = 0;
		if (temp > '9') {
			temp -= 10;
			k = 1;
		}
		res += temp;
	}
	if (k == 1) res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	int k, i;
	string num;
	cin >> num >> k;
	for (i = 0; i <= k; i++) {
		string s = num;
		reverse(s.begin(), s.end());
		if (s == num || i == k) break;
		num = add(s,num);
	}
	cout << num << endl << i;
	
	system("pause");
	return 0;
}
