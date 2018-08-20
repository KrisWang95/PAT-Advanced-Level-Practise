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
#define INT_MAX inf
using namespace std;

struct node {
	string name, id;
	int grade;
};

int ma, mi;

bool cmp(node a, node b) {
	return a.grade > b.grade;
}

int main() {

	int n;

	scanf("%d", &n);

	vector<node> v, r;

	for (int i = 0; i <n; i++) {

		node a;

		cin >> a.name >> a.id >> a.grade;

		v.push_back(a);
	}

	scanf("%d %d", &mi, &ma);

	sort(v.begin(), v.end(), cmp);

	for (auto it : v) {

		if (it.grade >= mi && it.grade <= ma) r.push_back(it);

	}

	if (r.size() == 0) printf("NONE");

	for (auto it : r) {

		printf("%s %s\n", it.name.c_str(), it.id.c_str());

	}

	return 0;
}