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

vector<vector<int>> e;


bool check(int i, int j) {

	for (int k = 0; k < e[i].size(); k++) {

		if (e[i][k] == j) return true;

	}

	return false;
}

int main() {

	int n, en;

	cin >> n >> en;

	e.resize(n + 1);

	for (int i = 0; i < en; i++) {

		int f, s;

		cin >> f >> s;

		e[f].push_back(s);

		e[s].push_back(f);

	}

	int qn;

	cin >> qn;

	for (int i = 0; i < qn; i++) {

		bool ans = true;

		int temp;

		cin >> temp;

		map<int, int> m;

		vector<int> v(temp);

		for (int i = 0; i < temp; i++) {

			cin >> v[i];

			if (m.find(v[i]) == m.end() || i == temp - 1) m[v[i]] = 1;

			else ans = false;

			if (i > 0 && check(v[i], v[i - 1]) == false) ans = false;

		}

		if (temp != n + 1 || v[0] != v[temp - 1] || ans == false) ans = false;

		if (ans) cout << "YES\n";

		else cout << "NO\n";

	}



	system("pause");

	return 0;
}