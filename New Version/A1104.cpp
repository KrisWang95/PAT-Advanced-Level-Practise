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
#include<iomanip>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;



int main() {

	int n;

	cin >> n;

	float ans = 0;

	for (float i = 1, j = n; i <= n && j >= 1; i++, j--) {

		float temp;

		cin >> temp;

		ans += (i * j * temp);

	}

	cout << setiosflags(ios::fixed) << setprecision(2) << ans;

	system("pause");

	return 0;
}