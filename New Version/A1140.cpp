#include<iostream>
#include<string>
using namespace std;

int main() {

	string s = "", res = "";

	int n, num;

	cin >> n >> num;

	res += (n + '0');

	for (int i = 2; i <= num; i++) {

		s = res;

		res = "";

		int k = 1;

		for (int j = 0; j < s.length(); j++) {

			if (s[j] == s[j + 1] && j < s.length() - 1) {

				k++;

			}
			else {

				res += s[j];

				res += (k + '0');

				k = 1;

			}
		}
	}
	cout << res << endl;

	system("pause");

	return 0;
}