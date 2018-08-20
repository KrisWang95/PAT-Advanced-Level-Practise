#include<iostream>
#include<string>
using namespace std;

char c(int k) {
	return k + '0';
}


int main() {
	int d, n;
	cin >> d >> n;
	string s = "",ans="";
	s += c(d);
	for (int i = 0; i < n ; i++){
		int table[10];
		fill(table, table + 10, 1);

		ans = "";

		for (int j = 0; j < s.length() - 1; j++) {
			if (s[j] == s[j + 1]) {
				table[s[j] - '0']++;
				continue;
			}

			ans += s[j];
			ans += c(table[s[j]-'0']);
			
		}

	}
	cout << s;

	system("pause");

	return 0;
}