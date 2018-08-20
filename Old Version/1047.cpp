#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
char name[41000][5];
bool cmp(int a, int b) {
	return strcmp(name[a],name[b]) < 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v[2510];
	for (int i = 0; i < n; i++) {
		int cnt;
		scanf("%s %d", name[i], &cnt);
	
		for (int j = 0; j < cnt; j++){
			int temp;

			scanf("%d", &temp);

			v[temp].push_back(i);
		}

	}
	for (int i = 1; i <= m; i++){
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++)
			printf("%s\n", name[v[i][j]]);
	}

	system("pause");

	return 0;
}