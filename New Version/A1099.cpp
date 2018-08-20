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
struct node {

	int key;

	int l, r;
};

vector<node> v;

vector<int> nums,level;

int index = 0;

void inOrder(int root) {

	if (root == -1) return;

	inOrder(v[root].l);

	v[root].key = nums[index++];

	inOrder(v[root].r);

 }

void getLevle(int root) {

	queue<int> q;

	q.push(root);

	while (!q.empty()) {

		int k = q.front();

		q.pop();

		level.push_back(v[k].key);

		if (v[k].l != -1) q.push(v[k].l);

		if (v[k].r != -1) q.push(v[k].r);

	}


}

int main() {

	int num;

	cin >> num;

	v.resize(num);

	nums.resize(num);

	for (auto &it : v) {

		cin >> it.l >> it.r;

	}

	for (auto &it : nums) {

		cin >> it;

	}

	sort(nums.begin(), nums.end());

	inOrder(0);

	getLevle(0);

	for (int i = 0; i < num; i++) {

		if (i == 0) cout << level[i];

		else cout << " " << level[i];

	}

	system("pause");

	return 0;
}