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
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;

struct node {
	int next;
	int data;
	int address;
};



int main() {

	int r, num;

	cin >> r >> num;

	vector<node> v(100010),newl,rl;

	map<int, int> m;

	for (int i = 0; i < num; i++) {

		int address, data, next;

		cin >> address >> data >> next;

		v[address].data = data;

		v[address].next = next;

		v[address].address = address;


	}

	int temp = r;

	while (temp != -1){


		if (m.find(abs(v[temp].data)) == m.end()) {

			m[abs(v[temp].data)] = 1;

			newl.push_back(v[temp]);


		}
		else {

			rl.push_back(v[temp]);

		}

		temp = v[temp].next;


	}

	for (auto it = newl.begin(); it != newl.end();it++) {

		if (it != newl.end() - 1) printf("%05d %d %05d", it->address, it->data, (it + 1)->address);

		else printf("%05d %d -1", it->address, it->data);

		cout << endl;

	}

	for (auto it = rl.begin(); it != rl.end(); it++) {

		if (it != rl.end() - 1) printf("%05d %d %05d", it->address, it->data, (it + 1)->address);

		else printf("%05d %d -1", it->address, it->data);

		cout << endl;

	}



	system("pause");

	return 0;
}