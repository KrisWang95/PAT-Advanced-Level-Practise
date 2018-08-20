#include<iostream>
#include<algorithm>
const int maxv = 110;
const int maxe = 1110;
using namespace std;
int father[maxv];

struct edge {

	int u, v;

	int weight;

}e[maxe];

bool cmp(edge a, edge b) {

	return a.weight < b.weight;

}

int findFather(int x) {

	return (x == findFather(x) ? x : ( father[x] = findFather(father[x])));

}

int kruskal(int n, int m) {

	int ans = 0, num = 0;

	//初始化并查集

	for (int i = 0; i < n; i++)	{

		father[i] = i;

	}

	sort(e, e + n, cmp);

	for (int i = 0; i < m; i++) {
		//union
		int fa = findFather(e[i].u);

		int fb = findFather(e[i].v);

		if (fa != fb) {

			father[fa] = fb;

			num++;

			ans += e[i].weight;

			if (num == n - 1) break;

		}
	}

	if (num != n - 1) return -1;

	return ans;
}