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

int n, m;

vector<int> father;//并查集

vector<int> p, value;// 第一个想抢该地方的编号,每个地方抢到的最大值价值

struct gang {

	int total;

	int value;

	vector<int> v;

	bool operator < (const gang &ano) const {
		return total > ano.total;
	}

};

void init() {

	for (int i = 1; i <= n; i++){

		father[i] = i;

	}
}

int findFather(int x) {

	return x == father[x] ? x : (father[x] = findFather(father[x]));

}

void unionset(int a, int b) {

	int fa = findFather(a), fb = findFather(b);

	if (fa != fb) {

		father[fa] = fb;

	}

}

int main() {

	scanf("%d %d", &n, &m);

	father.resize(n + 1);

	p.resize(m + 1,0);

	value.resize(m + 1);

	init();

	for (int i = 1; i <= m; i++) {

		scanf("%d", &value[i]);
	}

	vector<vector<int>> wr(n + 1);//每个人想抢劫的地方

	for (int i = 1; i <= n; i++) {

		int temp;

		scanf("%d:", &temp);

		for (int j = 0; j < temp; j++) {

			int k;

			scanf("%d", &k);

			wr[i].push_back(k);

			if (p[k] == 0) p[k] = i;

			unionset(i, findFather(p[k]));

		}

	}

	vector<vector<int>> v(n + 1); // 团伙编号

	for (int i = 1; i <= n; i++) {

		v[father[i]].push_back(i);

	}

	vector<gang> ans;//团伙抢到的价值

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		int max = -1;

		for (int j = 0; j < v[i].size(); j++) {

			int index = v[i][j];

			for (int k = 0; k < wr[index].size(); k++) {
				
				if (max < value[wr[index][k]]) {

					max = value[wr[index][k]];

				}

			}

		}

		if (max != -1) ans.push_back({(int)v[i].size(),max,v[i]});

		if (v[i].size() != 0) cnt++;

	}


	cout << cnt << endl;

	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < cnt; i++) {

		cout << ans[i].total << ":";

		for (int j = 0; j < ans[i].v.size(); j++) {

			cout << " " << ans[i].v[j];

		}

		cout << " " << ans[i].value << " " << ans[i].value / ans[i].total << endl;

	}

	system("pause");

	return 0;
}

/*
8 6
300 400 200 600 250 350 
3: 1 2 3
1: 4
2: 5 6
1: 4
1: 4
2: 3 2
1: 4
1: 1
*/