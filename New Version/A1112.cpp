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

	regex p("(\\w)\\1{" + to_string(n - 1) + "}");// n���ظ�character������

	map<string, bool> rep;

	while (regex_search(s, sm, p)) {

		string stemp = ans;

		string temp = sm.str().substr(0, 1);//�õ��ظ���

		string par = "(" + temp + ")\\1{" + to_string(n - 1) + "}"; // n��temp������

		stemp = regex_replace(stemp, regex(par), "");//�������ظ�n����ȥ��

		if (!regex_search(stemp, regex(temp)) && rep.find(temp) == rep.end()) { //��ȥ������Ȼ��������temp���ڣ�������

			rep[temp] = true;//��ֹ��������ٴ���� Example:3 eeeeeeeee

			cout << temp;

			ans = regex_replace(ans,regex(par), temp);//n���滻��1��

		}

		s = sm.suffix().str();

	}

	cout << endl << ans;

	system("pause");

	return 0;

}