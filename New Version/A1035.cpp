#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool isChanged(string &s) {

	bool res = false;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '1' || s[i] == '0' || s[i] == 'l' || s[i] == 'O') {

			res = true;

			switch (s[i]) {
			case '1':
				s[i] = '@';
				break;
			case '0':
				s[i] = '%';
				break;
			case 'l':
				s[i] = 'L';
				break;
			case 'O':
				s[i] = 'o';
				break;
			}

		}
	}

	return res;
}

int main() {

	int num, flag = 0;

	vector<string> v;

	cin >> num;

	for (int i = 0; i < num; i++) {

		string id, psw;

		cin >> id >> psw;

		if (isChanged(psw)) {

			flag++;

			v.push_back(id);

			v.push_back(psw);

		}

	}


	if (flag == 0) {

		if (num == 1) cout << "There is 1 account and no account is modified\n";

		else cout << "There are " << num << " account and no account is modified";

	}
	else {
		cout << flag << endl;

		for (int i = 0; i < flag; i++) {
			cout << v[2 * i] << " " << v[2 * i + 1] << endl;
		}

	}

	system("pause");

	return 0;
}


