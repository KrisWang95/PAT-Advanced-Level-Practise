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

map<int, int> m;

map<int, bool> isIn;

map<int, bool> ans;

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {

		int c, t;

		cin >> c >> t;

		m[c] = t;

		m[t] = c;

	}

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {

		int t;

		cin >> t;

		isIn[t] = true;

	}

	for (auto it : isIn) {

		if (m.find(it.first) == m.end() || isIn.find(m[it.first]) == isIn.end()) {

			ans[it.first] = true;

		}
			
	}

	cout << ans.size() << endl;

	for (auto it = ans.begin(); it!= ans.end(); it++){

		if (it == ans.begin()) printf("%05d", it->first);

		else printf(" %05d", it->first);

	}

	system("pause");

	return 0;
}