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

struct node{
	string data;
	int left, right;
};

vector<node> v;

string dfs(int root) {

	if (root == -1) return "";

	if (v[root].left != -1 || v[root].right != -1) return "(" + dfs(v[root].left) + v[root].data + dfs(v[root].right) + ")";

	else return v[root].data;

}



int main() {

	int n;

	cin >> n;

	v.resize(n + 1);

	map<int, bool> isRoot;

	for (int i = 1; i <= n; i++) {

		cin >> v[i].data >> v[i].left >> v[i].right;

		if (v[i].left > 0) isRoot[v[i].left] = 1;

		if (v[i].right > 0) isRoot[v[i].right] = 1;

	}

	int root;

	for(int i = 1; i <= n; i++){

		if (isRoot.find(i) == isRoot.end()) {

			root = i;

			break;

		}

	}
	string ans = dfs(root);

	if(ans[0] == '('){

		ans.erase(ans.begin());

		ans.erase(ans.end() - 1);

		cout << ans;


	}



	system("pause");

	return 0;
}