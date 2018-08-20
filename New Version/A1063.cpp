#include<iostream>
#include<set>
#include<vector>

using namespace std;



int main() {

	int num;

	cin >> num;

	vector<set<int> > v(num + 1);

	for (int i = 1; i <= num; i++) {

		int nums;

		cin >> nums;

		for (int j = 0; j < nums; j++) {

			int t;

			cin >> t;

			v[i].insert(t);

		}

	}

	int query;

	cin >> query;

	for (int i = 0; i < query; i++) {

		int c1, c2;

		cin >> c1 >> c2;

		int common = 0;

		for (auto & it : v[c1]) {

			if (v[c2].find(it) != v[c2].end()) common++;

		}

		printf("%.1f%%\n", (common) * 1.0 / (v[c1].size() + v[c2].size() - common )* 100.0);
		

	}

	system("pause");

	return 0;

}