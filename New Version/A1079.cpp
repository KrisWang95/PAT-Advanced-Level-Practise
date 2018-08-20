#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

vector<vector<int>> v(100010);

vector<int> w(100010,0);

double ans = 0;

int n;

double p, r;


void dfs(int root, int depth) {

	if (v[root].size() == 0) {

		ans += (p * pow(1 + r / 100, depth) * w[root]);

		return;

	}

	for (int i = 0; i < v[root].size(); i++) {

		dfs(v[root][i], depth + 1);

	}

}





int main() {

	cin >> n >> p >> r;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		for (int j = 0; j < temp; j++) {

			int t;

			cin >> t;

			v[i].push_back(t);

		}

		if (temp == 0) cin >> w[i];

	}

	dfs(0, 0);

	printf("%.1lf", ans);
	
	system("pause");

	return 0;
}