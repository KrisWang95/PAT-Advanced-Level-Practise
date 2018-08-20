#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
#include<queue>

using namespace std;

struct node {

	int ge, gi;

	double fg;

	int id, rank;

	vector<int> app;

};

struct  school{

	int lowRank = 0;

	int quota;

	vector<int> addmit;

};

int m, n, k;

vector<school> sc(100);

vector<node> v;

bool cmp(node a, node b) {return (a.fg != b.fg ? a.fg > b.fg : a.ge > b.ge);}
	


int main() {

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++) {

		cin >> sc[i].quota;

	}

	for (int i = 0; i < n; i++) {

		node a;

		a.app.resize(k);

		a.id = i;

		scanf("%d %d", &a.ge, &a.gi);

		for (int j = 0; j < k; j++) {

			scanf("%d", &a.app[j]);

		}

		a.fg = (a.ge + a.gi) / 2.0;

		v.push_back(a);

	}

	sort(v.begin(), v.end(), cmp);

	v[0].rank = 1;

	for (int i = 0; i < n; i++) {

		v[i].rank = i + 1;

		if (i != 0 && v[i].fg == v[i-1].fg && v[i].ge == v[i - 1].ge) {

			v[i].rank = v[i - 1].rank;

		}

		for (int j = 0; j < k; j++) {

			int cur = v[i].app[j];

			if (sc[cur].lowRank <= v[i].rank &&  sc[cur].quota != 0) {

				sc[cur].lowRank = v[i].rank;

				sc[cur].addmit.push_back(v[i].id);

				sc[cur].quota--;

				break;

			}
			else if (sc[cur].lowRank == v[i].rank && sc[cur].quota == 0) {

				sc[cur].addmit.push_back(v[i].id);

				break;

			}

		}


	}


	for (int i = 0; i < m; i++) {

		sort(sc[i].addmit.begin(), sc[i].addmit.end());

		for (int j = 0; j < sc[i].addmit.size(); j ++) {

			if (j == 0) printf("%d", sc[i].addmit[j]);

			else printf(" %d", sc[i].addmit[j]);

		}

		printf("\n");

	}

	return 0;
}