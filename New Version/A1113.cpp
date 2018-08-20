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

int main() {

	int n;

	cin >> n;

	vector<int> v(n);

	for (auto &it : v) {

		cin >> it;

	}

	sort(v.begin(), v.end());

	int left = 0, right = 0;

	for (int i = 0; i < n; i++) {

		if (i < n / 2) left += v[i];

		else right += v[i];

	}


	cout << (n % 2 == 0 ? 0 : 1)  <<" " << right - left;

	return 0;
}