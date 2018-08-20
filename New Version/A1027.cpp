#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main() {

	string s = "0123456789ABC";

	int r, g, b;

	cin >> r >> g >> b;

	cout << "#" << s[r / 13] << s[r % 13] << s[g / 13] << s[g % 13] << s[b / 13] << s[b % 13];


	
	system("pause");

	return 0;
}
