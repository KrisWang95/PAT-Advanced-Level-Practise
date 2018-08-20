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

int n;

double p, r;

vector<int> v[100010];

int minDepth = INT_MAX, cnt = 1;

void dfs(int root, int depth) {

	if (v[root].size() == 0) {

		if (depth < minDepth) {

			minDepth = depth;

			cnt = 1;
		}
		else if(minDepth == depth){

			cnt++;

		}
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

	}

	dfs(0, 0);

	double  ans = pow((1 + r / 100), minDepth) * p;
	
	printf("%.4lf %d", ans, cnt);

	system("pause");

	return 0;
}