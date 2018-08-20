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

int n, k, p, maxfacsum = -1;

vector<int> np, temp, ans;

int getFactor(int n, int p) {

	int i = 0, temp = 0;

	while (temp <= n) {

		np.push_back(temp);

		i++;

		temp = pow(i, p);

	}

	return i - 1;
}

void dfs(int index, int nowk, int sum, int facsum) {

	if (sum == n && nowk == k) {

		if (facsum > maxfacsum) {

			ans = temp;

			maxfacsum = facsum;


		}

		return;

	}

	if (index == 0) return;

	if (sum + np[index] <= n && nowk + 1 <= k) {

		temp.push_back(index);

		dfs(index, nowk + 1, sum + np[index], facsum + index);

		temp.pop_back();

	}

	dfs(index - 1, nowk, sum, facsum);

}



int main() {

	ios::sync_with_stdio(false);

	cin >> n >> k >> p;

	int m = getFactor(n, p);

	dfs(m, 0, 0, 0);

	if (ans.size()) {

		cout << n << " = ";

		for (auto it = ans.begin(); it != ans.end(); it++) {

			if (it != ans.begin()) cout << " + " << *it << "^" << p;

			else cout << *it << "^" << p;

		}

	}
	else {

		cout << "Impossible";

	}

	system("pause");

	return 0;
}