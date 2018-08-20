#include<iostream>
#include <regex>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a = "-123456789";
	regex pattern ("(\\d)(?=(\\d{3})+(?!\\d))");
	cout << regex_replace(a, pattern, "$1,") << endl;
}
