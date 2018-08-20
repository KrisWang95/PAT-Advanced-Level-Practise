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

bool cmp(int a, int b) { return a > b; }



int main() {

	int n;

	cin >> n;

	vector<int> v(n);

	for (auto &it : v) {

		cin >> it;

	}

	sort(v.begin(), v.end(), cmp);

	int m = sqrt(n);

	while (n % m != 0) m++;

	n /= m;

	int j = 0;

	for (int i = 0; i < n; i++) {
		
		cout << v[i];

		j++;

	}

	for (int i = 0; i < m - 2; i++) {


	}





	system("pause");

	return 0;
}