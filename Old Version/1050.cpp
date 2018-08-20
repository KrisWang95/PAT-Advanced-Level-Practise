#include<iostream>
#include<string>
bool asi[260];
using namespace std;

int main() {
	string s,a;
	getline(cin, s);
	getline(cin, a);

	for (int i = 0; i < a.length(); i++) {
		asi[a[i]] = true;
	}

	for (int i = 0; i < s.length(); i++) {
		if (asi[s[i]] == false) {
			cout << s[i];
		}
	}

	system("pause");

	return 0;

}