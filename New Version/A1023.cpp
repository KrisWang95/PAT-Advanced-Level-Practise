#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;

int v[10] = { 0 };

string add(string a) {
	string res = "";
	int k = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		char temp = (a[i] + a[i] - '0' + k);
		k = 0;
		if (temp > '9') {
			temp -= 10;
			k = 1;
		}
		res += temp;
	}
	if (k == 1) res += '1';
	reverse(res.begin(),res.end());
	return res;
}

bool isPerm(string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		v[a[i] - '0'] ++;
	}
	for (int i = 0; i < b.length(); i++) {
		v[b[i] - '0'] --;
	}
	for (int i = 0; i < 10; i++) {
		if (v[i] != 0) return false;
	}

	
	return true;
}

int main() {
	string num;
	cin >> num;
	string dou = add(num);
	cout << (isPerm(num, dou)? "Yes\n":"No\n");
	cout << dou;
	system("pause");
	return 0;
}
