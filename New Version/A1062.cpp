#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct node {

	int id;

	int t;

	int v;

	int total;

};

vector<node> v[4];

bool cmp(node a, node b) {

	return (a.total != b.total ? a.total > b.total : (a.v != b.v ? a.v > b.v:a.id < b.id));

}

int main() {

	int num, l, h, cnt = 0;

	cin >> num >> l >> h;

	for (int i = 0; i < num; i++) {

		node a;

		cin >> a.id >> a.v >> a.t;

		a.total = a.t + a.v;

		if (a.t < l ||  a.v < l) continue;

		else if (a.t >= h && a.v >= h) v[0].push_back(a);
		
		else if (a.t < h && a.v >= h) v[1].push_back(a);
		
		else if (a.t < h && a.v < h && a.t <= a.v) v[2].push_back(a);
		
		else v[3].push_back(a);
		
		cnt++;
	}

	cout << cnt << endl;

	for (int i = 0; i < 4; i++) {

		sort(v[i].begin(), v[i].end(), cmp);

		for (int j = 0; j < v[i].size(); j++) {

			printf("%d %d %d\n", v[i][j].id, v[i][j].v, v[i][j].t);

		}
	}


	system("pause");

	return 0;

}