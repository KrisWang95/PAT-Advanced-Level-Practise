#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<cctype>
using namespace std;



int main() {

	map<string, int> m;

	string s;

	getline(cin, s);

	string temp;

	for (int i = 0; i < s.length(); i++) {

		s[i] = tolower(s[i]);

		if (isalnum(s[i]) ){

			temp += s[i];

		}
		else {

			if(!temp.empty())

				if (m.find(temp) == m.end()) m[temp] = 1;

				else m[temp]++;


			temp.clear();

		}

	}

	if(!temp.empty())

		if (m.find(temp) == m.end()) m[temp] = 1;

		else m[temp]++;

	int max = -1;

	for (auto it : m) {

		if (it.second > max) {

			temp = it.first;

			max = it.second;

		}
	}

	cout << temp << " " << max;

	system("pause");

	return 0;
}