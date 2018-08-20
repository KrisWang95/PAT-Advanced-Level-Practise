#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
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

typedef pair<int, int> pp;

vector<int> fre;

int n, mn;

struct cmp {

	int x, d;

	bool operator <(const cmp &a) const { return d != a.d ? d < a.d : x > a.x; }

};

priority_queue<cmp> q;

vector<cmp> getAns() {

	vector<cmp> v;

	while (!q.empty() && v.size() < mn) {

		cmp k = q.top(); q.pop();

		if (fre[k.x] > k.d) continue;

		v.push_back(k);

	}

	for (auto it : v) {

		q.push(it);

	}
	
	return v;
}

int main() {

	ios::sync_with_stdio(false);

	cin >> n >> mn;

	fre.resize(n + 1,0);

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		if (i > 0) {

			cout << temp << ":";

			vector<cmp> v = getAns();

			for (int j = 0; j < mn && j < v.size(); j++) {

				cout << " " << v[j].x;

			}

			cout << endl;

		}

		fre[temp]++;

		q.push({ temp, fre[temp] });

	}

	system("pause");

	return 0;
}