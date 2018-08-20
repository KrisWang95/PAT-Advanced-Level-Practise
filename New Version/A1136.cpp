#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX
using namespace std;

string add(string a, string b) {

	int i = a.length() - 1, j = b.length() - 1, carry = 0;

	string res;

	while (i >= 0 || j >= 0 || carry) {

		char temp = (i >= 0 ? a[i] : '0') + (j >= 0 ? b[j] : '0') - '0' + carry;

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


int main() {

	string s, temp;

	cin >> s;

	temp = s;

	reverse(temp.begin(), temp.end());

	if (temp == s) cout << s << " is a palindromic number.";

	else {

		bool flag = false;

		for (int i = 0; i < 10; i++) {

			string ss = add(temp, s);

			cout << s << " + " << temp << " = " << ss << endl;

			s = ss;

			temp = ss;

			reverse(temp.begin(), temp.end());

			if (s == temp) { flag = true; cout << ss << " is a palindromic number."; break; }

		}

		if (flag == false) cout << "Not found in 10 iterations.";

	}



	system("pause");

	return 0;
}