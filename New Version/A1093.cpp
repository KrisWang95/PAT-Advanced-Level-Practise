#include<iostream>
#include<string>
#include<vector>
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



int main() {

	string s;

	cin >> s;

	vector<int> p(s.length(),0);

	int i = 0, cnt = 1, ans = 0;

	for (int i = 0; i < s.length(); i++) {

		if (i == 0 && s[0] == 'P') p[0] = 1;

		else if (i != 0) {

			if (s[i] == 'P') p[i] = p[i - 1] + 1;

			else p[i] = p[i - 1];

		}
	}

	cnt = 1;

	for (int j = s.length() - 1; j >= 0; j--) {

		if (s[j] == 'T') cnt++;

		else if (s[j] == 'A') ans += p[j] * (cnt - 1);

	}

	cout << ans;

	system("pause");

	return 0;
}