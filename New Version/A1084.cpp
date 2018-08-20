#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<cctype>
#include<queue>

using namespace std;

	


int main() {

	string a, b,res;

	cin >> a >> b;

	int i = 0, j = 0;

	map<char, bool> m;

	while (i < a.length()) {

		if ( b.length() == 0 ||a[i] != b[j]) {

			if(m.find(toupper(a[i])) == m.end())

				res += toupper(a[i]);

			m[toupper(a[i])] = true;

			i++;

		}
		else {

			i++;

			j++;
		}

	}

	cout << res << endl;

	system("pause");

	return 0;
}