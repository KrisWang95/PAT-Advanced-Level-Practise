#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main() {

	int n, m, check;

	cin >> n >> m;

	vector<int> e[1001], res;

	vector<int> indegree(1001, 0), tempdegree;

	for (int i = 0; i < m; i++) {

		int c, s;

		cin >> c >> s;

		e[c].push_back(s);

		indegree[s]++;

	}

	cin >> check;

	for (int i = 0; i < check; i++) {

		tempdegree = indegree;

		int flag = true;

		for (int j = 0; j < n; j++) {

			int temp;

			cin >> temp;

			if (tempdegree[temp] == 0) {

				for (int k = 0; k < e[temp].size(); k++) {

					tempdegree[e[temp][k]]--;

				}

			}
			else {

				flag = false;

			}

		}

		if (!flag) res.push_back(i);

	}

	cout << res[0];

	for (int i = 1; i < res.size(); i++) {

		cout << " " << res[i];

	}


	system("pause");

	return 0;

}