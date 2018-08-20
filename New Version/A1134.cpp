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

vector<pair<int,int>> v;

bool check(set<int> s) {

	for (auto it: v) {

		if (s.find(it.first) == s.end() && s.find(it.second) == s.end()) return false;

	}


	return true;
}


int main() {

	ios::sync_with_stdio(false);

	int vn, en;

	cin >> vn >> en;

	for (int i = 0; i < en; i++) {

		int v1, v2;

		cin >> v1 >> v2;
		
		v.push_back(make_pair(v1,v2));

	}
	int qn;

	cin >> qn;

	for (int i = 0; i < qn; i++) {

		int t;

		cin >> t;

		set<int> vs;

		for (int j = 0; j < t; j++) {

			int temp;

			cin >> temp;

			vs.insert(temp);

		}

		if (check(vs)) cout << "Yes\n";

		else cout << "No\n";

	}



	system("pause");

	return 0;
}