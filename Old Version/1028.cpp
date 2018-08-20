#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct node {
	int id, marks;
	char name[10];
}node;

vector<node> v;

int type = 1;

bool cmp(node a, node b) {
	switch (type){
		case 1:
			return a.id < b.id;
			break;
		case 2:
			return (strcmp(a.name,b.name) != 0 ? (strcmp(a.name, b.name) <= 0) : a.id < b.id);
			break;
		case 3:
			return (a.marks != b.marks ? a.marks < b.marks : a.id < b.id);
			break;
	}
}

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++){
		node a;
		scanf("%d %s %d", &a.id, a.name, &a.marks);
		v.push_back(a);
	}

	type = c;
	sort(v.begin(),v.end(),cmp);

	for (int i = 0; i < v.size(); i++) {
		printf("%06d %s %d\n", v[i].id,v[i].name,v[i].marks);
	}
	system("pause");
	return 0;
}