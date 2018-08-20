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

	int id;

	int f, m;

	int m_r = 0, r_a = 0;

	vector<int> child;
};

struct ans {

	int head;

	double mr = 0, ra = 0;

	int pnum = 0;

	bool operator < (const ans & ano) const { return ra != ano.ra ? ra > ano.ra : head  < ano.head; }
 
};

map<int,int> father;

void add(int x) {

	if (father.find(x) == father.end() && x >= 0) father[x] = x;

}


int findFather(int x) {

	return x == father[x] ? x : (father[x] = findFather(father[x]));

}

void Union(int a, int b) {

	int fa = findFather(a);

	int fb = findFather(b);

	if (fa != fb) {

		if (fb > fa) swap(fa, fb);

		father[fa] = fb;

	}
}



int main() {

	int n;

	cin >> n;

	vector<node> v(100000);

	for (int i = 0; i < n; i++) {

		node a;

		cin >> a.id >> a.f >> a.m;

		add(a.id); add(a.f); add(a.m);

		if(a.f >= 0 && a.m >= 0) Union(a.f, a.m);

		if(a.f >= 0)Union(a.f, a.id);

		if(a.m >= 0)Union(a.id, a.m);

		int temp;

		cin >> temp;

		a.child.resize(temp);

		for (int j = 0; j < temp; j++) {
			
			cin >> a.child[j];

			add(a.child[j]);

			Union(a.id, a.child[j]);

		}

		cin >> a.m_r >> a.r_a;

		v[a.id] = a;

	}

	map<int, ans> ma;

	int cnt = 0;

	for (auto it : father) {

		findFather(it.first);

		if (it.first == it.second) {

			cnt++;
		}

	}

	for (auto it : father) {

		ma[it.second].head = it.second;

		ma[it.second].pnum++;

		ma[it.second].mr += v[it.first].m_r;

		ma[it.second].ra += v[it.first].r_a;

	}

	vector<ans> u;

	for (auto it : ma) {

		it.second.mr /= it.second.pnum;

		it.second.ra /= it.second.pnum;

		u.push_back(it.second);

	}
	
	sort(u.begin(), u.end());

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++) {

		printf("%04d %d %.3f %.3f\n", u[i].head, u[i].pnum, u[i].mr,u[i].ra);

	}

	system("pause");

	return 0;
}