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

	int n, s, f;

	cin >> n >> s >> f;

	vector<string> v(n + 1);

	for (int i = 1; i <= n; i++) {

		cin >> v[i];

	}

	vector<string> ans;

	map<string, int> m;
	

	while (f <= n) {

		if (m.find(v[f]) == m.end()) {

			m[v[f]] = 1;

			ans.push_back(v[f]);

			f = f + s;
		}
		else {

			f = f + 1;

		}


	}

	if (m.size() > 0) {

		for (auto it : ans) {

			cout << it << endl;

		}

	}
	else {
		cout << "Keep going...\n";
	}


	system("pause");

	return 0;
}