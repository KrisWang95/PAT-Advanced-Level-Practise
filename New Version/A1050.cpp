#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int main(){

	string s1,s2;

	map<char, int> m;

	getline(cin, s1);

	getline(cin, s2);

	for (int i = 0; i < s2.length(); i++) {

		m[s2[i]] = 1;

	}
	for (int i = 0; i < s1.length(); i++) {

		if (m.find(s1[i]) == m.end()) cout << s1[i];

	}
	
	system("pause");

	return 0;
}


