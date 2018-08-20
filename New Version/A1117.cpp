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

bool cmp(int a, int b) {
	return a > b;
}


int main() {

	int n;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {

		cin >> v[i];

	}

	int e;

	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < n; i++) {

		if (v[i] > i + 1) {

			e = i + 1;

		}

	}

	cout << e;



	system("pause");

	return 0;
}