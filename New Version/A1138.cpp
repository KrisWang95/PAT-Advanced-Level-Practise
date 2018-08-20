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

vector<int> pre, in, post;

void getPost(int preL, int preR, int inL, int inR) {

	if (preL > preR) return;

	int k;

	for (k = inL; k < inR && pre[preL] != in[k]; k++);

	int num = k - inL;

	getPost(preL + 1, preL + num, inL, k - 1);

	getPost(preL + num + 1, preR, k + 1, inR);

	post.push_back(pre[preL]);

}


int main() {

	int n;

	cin >> n;

	pre.resize(n);

	in.resize(n);

	for (auto &it : pre) {

		cin >> it;
	}

	for (auto &it : in) {

		cin >> it;
	}

	getPost(0, n - 1, 0, n - 1);

	cout << post[0];



	system("pause");

	return 0;
}