#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
using namespace std;


int main() {

	string s, m, res;

	cin >> s;

	bool isPostive = true, ePositive = true;


	//判断正负
	if (s[0] == '-') isPostive = false;

	//求整数部分res 小数部分m
	int i = 1, flag = 1;

	while (s[i] != 'E')

		if (isdigit(s[i]) && flag) { res += s[i++]; flag = 0; }

		else if (isdigit(s[i]) && flag == 0) m += s[i++];

		else i++;

	i++;

	//判断指数正负
	if (s[i++] == '-') ePositive = false;

	//求指数
	int e = 0;

	while (i < s.length()) e = e * 10 + (s[i++] - '0');

	//根据指数正负求主体部分
	i = 0;

	if (ePositive) {

		while (i < e) {

			if (i < m.length()) res += m[i];

			else res += '0';

			i++;

		}

		if (i < m.length()) res += '.';

		while (i < m.length()) {

			res += m[i++];

		}

	}
	else {

		while (i < e - 1) {

			res = '0' + res;

			i++;

		}

		if (e == 0) res = res + '.' + m;

		else res = "0." + res + m;

	}

	if (!isPostive) res = '-' + res;

	cout << res;

	system("pause");

	return 0;
}