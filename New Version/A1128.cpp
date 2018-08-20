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

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		vector<int> v(temp);

		bool ans = true;

		for (int j = 0; j < temp; j++) {

			cin >> v[j];

			if(ans) for (int l = 0; l < j; l++) if (v[l] == v[j] || abs(v[l] - v[j]) == abs(l - j)) ans = false;


		}

		if (ans) cout << "YES\n";

		else cout << "NO\n";

	}



	system("pause");

	return 0;
}