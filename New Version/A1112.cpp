#include<iostream>
#include<vector>
#include<cmath>
#include<regex>
#include<map>
using namespace std;
int main() {

	string s;

	int n;

	cin >> n >> s;

	string ans = s;

	smatch sm;

	regex p("(\\w)\\1{" + to_string(n - 1) + "}");// n个重复character的正则

	map<string, bool> rep;

	while (regex_search(s, sm, p)) {

		string stemp = ans;

		string temp = sm.str().substr(0, 1);//得到重复项

		string par = "(" + temp + ")\\1{" + to_string(n - 1) + "}"; // n个temp的正则

		stemp = regex_replace(stemp, regex(par), "");//把所有重复n个的去除

		if (!regex_search(stemp, regex(temp)) && rep.find(temp) == rep.end()) { //若去除后依然搜索不到temp存在，表明是

			rep[temp] = true;//防止已输出的再次输出 Example:3 eeeeeeeee

			cout << temp;

			ans = regex_replace(ans,regex(par), temp);//n个替换成1个

		}

		s = sm.suffix().str();

	}

	cout << endl << ans;

	system("pause");

	return 0;

}