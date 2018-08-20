#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct info {
	string user, psw;
};

bool change(string &a) {
	bool tag = false;
	for (int i = 0; i < a.length(); i++){
		if (a[i] == '1') {
			a[i] = '@';
			tag = true;
		}
			
		else if (a[i] == '0') {
			a[i] = '%';
			tag = true;
		}
			
		else if (a[i] == 'l') {
			a[i] = 'L';
			tag = true;
		}
			
		else if (a[i] == 'O') {
			a[i] = 'o';
			tag = true;
		}
	}
	return tag;
}

int main() {
	
	int num;

	vector<info> v;

	cin >> num;

	for (int i = 0; i < num; i++){
		info a;
		cin >> a.user >> a.psw;
		if (change(a.psw)) {
			v.push_back(a);
		}
	}

	if (v.size() != 0) {
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].user << " " << v[i].psw << endl;
		}
	}
	else {
		if (num == 1) {
			cout << "There is 1 account and no account is modified";
		}
		else {
			printf("There are %d accounts and no account is modified",num);
		}
	}


	system("pause");
	return 0;
}