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

map<int, int> father;

int findFather(int x) {

	return x == father[x] ? x : (father[x] = findFather(father[x]));

}

void Union(int a, int b) {

	int fa = findFather(a);

	int fb = findFather(b);

	if (fa != fb) {

		father[fa] = fb;

	}

}


int main() {

	int pn;

	cin >> pn;

	for (int i = 0; i < pn; i++) {

		int num;

		cin >> num;

		int last;

		for (int j = 0; j < num; j++) {

			int temp;

			cin >> temp;

			if (father.find(temp) == father.end()) father[temp] = temp;

			if (j > 0) Union(last, temp);

			last = temp;

		}

	}

	int cnt = 0;

	for (auto it : father) {

		findFather(it.first);

		if (it.first == it.second) cnt++;

	}

	cout << cnt << " " << father.size() << endl;

	int query;

	cin >> query;

	for (int i = 0; i < query; i++) {

		int t, s;

		cin >> t >> s;

		if (father[t] == father[s]) cout << "Yes\n";

		else cout << "No\n";

	}



	system("pause");

	return 0;
}