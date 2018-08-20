#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a, string b) {

	return a < b;
}

int main() {

	int num;

	cin >> num;

	vector<string> v(num);

	for (auto &it : v) {

		cin >> it;

	}

	sort(v.begin(), v.end(), cmp);

	string res = "";

	for (auto &it : v) {

		res += it;

	}

	while (res[0] == '0') res.erase(res.begin());

	cout << res;

	system("pause");

	return 0;
}


