#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
#include<queue>

using namespace std;


int main() {

	int num, p,ans = -1;

	cin >> num >> p;

	vector<int> v(num);

	for (auto &it : v) {

		cin >> it;

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < num; i++) {

		int j = upper_bound(v.begin() + i, v.end(), (long long)v[i] * p) - v.begin();

		ans = max(ans, j - i);

	}

	cout << ans;
	
	system("pause");

	return 0;
}