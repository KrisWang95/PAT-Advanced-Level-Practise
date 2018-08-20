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
using namespace std;

vector<vector<int>> v(100100);

int cnt = 1, maxDepth = 0;

void dfs(int root, int depth) {

	if (v[root].size() == 0) {

		if (maxDepth < depth) {

			cnt = 1;

			maxDepth = depth;

		}
		else if(maxDepth == depth) {

			cnt++;

		}

	}

	for(auto it : v[root]){

		dfs(it, depth + 1);

	}

}



int main() {

	int n, root;

	double p, r;

	cin >> n >> p >> r;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		if(temp != -1) v[temp].push_back(i);

		else root = i;


	}

	dfs(root, 0);

	double ans = p * pow((1 + r / 100), maxDepth);

	printf("%.2f %d", ans, cnt);

	system("pause");

	return 0;
}