#include <iostream>
#include <map>
#include <vector>
#include<string>
#include<set>
#include <algorithm>
using namespace std;

vector<int> v[10001],temp;
bool visited[10001] = { false };
int maxDep = 0;
set<int> s;

void dfs(int root, int depth) {
	if (depth > maxDep) {
		temp.clear();
		temp.push_back(root);
		maxDep = depth;
	}
	else if( depth == maxDep){
		temp.push_back(root);
	}

	visited[root] = true;

	for (int i = 0; i < v[root].size(); i++) {
		if (visited[v[root][i]] == false)
			dfs(v[root][i], depth + 1);
	}
}


int main() {

	int num,cnt = 0;
	cin >> num;

	for (int i = 0; i < num - 1; i++) {
		int t, t1;
		cin >> t >> t1;
		v[t].push_back(t1);
		v[t1].push_back(t);
	}

	for (int i = 1; i <= num; i++) {
		if (visited[i] == false) {
			dfs(i, 1);
			cnt++;
		}

		if (i == 1) {

			for (int j = 0; j < temp.size(); j++) {
				s.insert(temp[j]);
			}

		}
	}

	if (cnt >= 2) {
		cout << "Error: " << cnt << " components";
	}
	else {
		temp.clear();
		fill(visited, visited + num+1, false);
		maxDep = 0;
		dfs(*s.begin(), 1);
		for (int j = 0; j < temp.size(); j++) {
			s.insert(temp[j]);
		}
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}

	
		

	system("pause");
	return 0;
}