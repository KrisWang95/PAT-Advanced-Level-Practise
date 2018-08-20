#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct _node {
	int come, ptime;
}node;
bool cmp(node a, node b) {
	return a.come < b.come;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<node> v;
	for (int i = 0; i < n; i++) {
		int h, m, s, ptime;
		scanf("%d:%d:%d %d", &h, &m, &s, &ptime);
		node a;
		if (ptime > 60) ptime = 60;
		a.ptime = ptime * 60;
		a.come = h * 60 * 60 + m * 60 + s;
		if (a.come <= 17 * 3600)
			v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	vector<int> win(m, 28800);
	double result = 0;
	for (int i = 0; i < v.size(); i++) {
		int tempindex = 0;
		for (int i = 0; i < m; i++) {
			if (win[tempindex] > win[i]) {
				tempindex = i;
			}
		}
		if (win[tempindex] <= v[i].come) {
			win[tempindex] = v[i].come + v[i].ptime;
		}
		else {
			result += (win[tempindex] - v[i].come);
			win[tempindex] += v[i].ptime;
		}
	}
	if (v.size() == 0)
		printf("0.0");
	else
		printf("%.1f", result / 60.0 / v.size());
	system("pause");
	return 0;
}