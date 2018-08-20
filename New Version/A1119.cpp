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

vector<int> pre, post,in;

int n;

bool isUnique = true;

void getIn(int preL, int preR, int postL, int postR) {

	if (preL > preR || postL > postR) return;

	int k;

	for (k = preL + 1 ; k < preR && pre[k] != post[postR - 1]; k++);

	if (k - preL != 1 || k > preR) {

		getIn(preL + 1, k - 1, postL, postL + k - preL - 2);

	}
	else {

		isUnique = false;
	}

	in.push_back(pre[preL]);

	getIn(k, preR,postL + k -preL -1 , postR - 1);

}

int main() {

	cin >> n;

	pre.resize(n);

	post.resize(n);

	for (auto &it : pre) {

		cin >> it;

	}

	for (auto &it : post) {

		cin >> it;

	}

	getIn(0, n - 1, 0, n - 1);

	if (isUnique) cout << "Yes\n";

	else cout << "No\n";

	for (int i = 0; i < n; i++) {

		if (i == 0) cout << in[i];

		else cout << " " << in[i];

	}

	system("pause");

	return 0;
}