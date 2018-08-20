#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int id, grade;
	char name[9];
};

int num, query;

bool cmp(node a, node b) {

	switch (query) {

	case 1: return (a.id < b.id);

	case 2: return (strcmp(a.name, b.name) != 0 ? (strcmp(a.name, b.name) <= 0) : a.id < b.id);

	case 3:return (a.grade != b.grade ? a.grade < b.grade : a.id < b.id);

	}
}

int main() {

	cin >> num >> query;

	vector<node> v;

	for (int i = 0; i < num; i++) {

		node a;

		scanf("%d %s %d", &a.id, a.name, &a.grade);

		v.push_back(a);

	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < num; i++)  printf("%06d %s %d\n", v[i].id, v[i].name, v[i].grade);

	system("pause");

	return 0;
}
