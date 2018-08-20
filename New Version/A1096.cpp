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

	int s = sqrt(n) + 1;

	int last = 2, cnt = 1, maxLen = 1, start = 2;

	for (int i = 2; i <= s + 1; i++) {

		if (n % i == 0) {

			if (i - last == 1) cnt++;

			last = i;

		}
		else {

			if (maxLen < cnt) {

				start = i - cnt;

				maxLen = cnt;

			}

			cnt = 1;

		}

	}

	cout << maxLen << endl;

	for (int i = 0; i < maxLen; i++) {

		if (i == 0) cout << start;

		else cout << "*" << start + i;

	}
		

	system("pause");

	return 0;
}