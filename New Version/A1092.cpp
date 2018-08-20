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

	int m[256] = { 0 };

	string s, t;

	cin >> s >> t;

	for (auto it : s) {

		m[it]++;

	}

	int cnt = 0;

	for (auto it : t) {

		if (m[it] > 0) m[it] --;

		else cnt++;

	}

	if (cnt) cout << "No " << cnt;

	else cout << "Yes " << s.length() - t.length();

	system("pause");

	return 0;
}