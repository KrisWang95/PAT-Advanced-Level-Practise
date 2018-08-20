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
#include<regex>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;

bool isLegal(string s, double &res) {

	bool isNum = true, isDot = false;

	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '-' && i == 0) continue;

		if (!isdigit(s[i]) && s[i] != '.') {

			isNum = false;

			break;
		}

		if (isDot == false && s[i] == '.') {

			isDot = true;

		}

		if (isDot) {

			if (cnt > 2) isNum = false;

			cnt++;

		}

	}

	

	if (isNum) {

		res = atof(s.c_str());

		if (res > 1000 || res < -1000) { res = 0;  return false; }

		return true;

	}

	else return false;

}


bool isValid(string temp,double &ans) {

	regex re("(-?\\d*)(\\.\\d{0,2})?");

	if (regex_match(temp, re)) {

		ans = stod(temp);

		if (ans < -1000 || ans > 1000) ans = 0;

		else return true;

	}

	return false;

}



int main() {

	int num;

	cin >> num;

	double ans = 0;

	int cnt = 0;

	for (int i = 0; i < num; i++) {

		double a = 0;

		string s;

		cin >> s;

		bool res = isValid(s, a);

		ans += a;

		if (res == false) {

			cout << "ERROR: " << s << " is not a legal number" << endl;

			cnt++;

		}

	}

	if (num - cnt > 1) {

		cout << "The average of " << num - cnt << " numbers is ";

		printf("%.2f", ans / (num - cnt));

	}
	else if(num - cnt == 1){

		cout << "The average of " << num - cnt << " number is ";

		printf("%.2f", ans / (num - cnt));

	}
	else {

		cout << "The average of " << num - cnt << " numbers is Undefined";

	}


	system("pause");

	return 0;
}