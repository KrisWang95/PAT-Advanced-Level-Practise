#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

	int gp, gm, gf, g;

	string id;

	bool operator < (const node &ano) const { return g != ano.g ? g > ano.g : id < ano.id; }

};

int main() {

	ios::sync_with_stdio(false);

	int p, n, m;

	cin >> p >> n >> m;

	map<string, int> gp, gm, gf;

	for (int i = 0; i < p; i++) {

		string id;

		int grade;

		cin >> id >> grade;

		if(grade >= 200) gp[id] = grade;

	}

	for (int i = 0; i < n; i++) {

		string id;

		int grade;

		cin >> id >> grade;

		if(gp.find(id) != gp.end())gm[id] = grade;

	}

	for (int i = 0; i < m; i++) {

		string id;

		int grade;

		cin >> id >> grade;

		if (gp.find(id) != gp.end())gf[id] = grade;

	}

	vector<node> v;

	for (auto it : gf) {

		node a;

		a.id = it.first;

		a.gp = gp[it.first];

		if (gm.find(it.first) == gm.end()) {

			if (it.second >= 60) {

				a.g = it.second;

				a.gf = it.second;

				a.gm = -1;

				v.push_back(a);

			}
		}
		else {

			a.g = it.second < gm[it.first] ? (int)(it.second * 0.6 + gm[it.first] * 0.4 + 0.5) : it.second;

			if (a.g >= 60) {

				a.gm = gm[it.first];

				a.gf = it.second;

				v.push_back(a);

			}

		}

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		cout << v[i].id << " " << v[i].gp << " " << v[i].gm << " " << v[i].gf << " " << v[i].g << endl;

	}


	system("pause");

	return 0;
}