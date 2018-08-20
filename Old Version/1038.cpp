#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}
/*cmp真的很强大*/
int main() {
	int num;
	string s[10005];
	cin >> num;
	for (int  i = 0; i < num; i++){
		cin >> s[i];
	}
	sort(s, s + num, cmp);
	string s1;
	for (int i = 0; i < num; i++){
		s1 += s[i];
	}
	while (s1.length() != 0 && s1[0] == '0') {
		s1.erase(s1.begin());
	}
	if (s1.length() == 0) cout << 0;
	cout << s1;
	system("pause");
	return 0;
}