#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int dp[1005][1005];
int main() {
	string s;

	getline(cin, s);

	memset(dp, 0, sizeof(dp));

	int l = s.length(), ans = 1;

	//边界条件
	for (int i = 0; i < l; i++) {
		dp[i][i] = 1;
		if (i > 0 && s[i] == s[i - 1]) {
			dp[i-1][i] = 1;
			ans = 2;
		}
	}

	//状态转移方程
	for (int L = 3; L <= l; L++) {//子串长度
		for (int i = 0; i + L - 1 < l; i++){//子串右端点
			int j = i + L - 1; //子串右端点
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}

	printf("%d", ans);
	system("pause");
	return 0;

}