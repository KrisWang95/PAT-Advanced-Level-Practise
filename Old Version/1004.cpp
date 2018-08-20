#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[100];
int level[100],result[100];//每个节点所在的层数,每层的叶子节点数
int sumNode,noneLeaf,maxLevel = -1;
void bfs() {
	queue<int> q;
	q.push(1);
	level[1] = 1;
	while (!q.empty()){

		int index = q.front();

		q.pop();

		maxLevel = max(level[index], maxLevel);

		if (v[index].size() == 0)
			result[level[index]]++;

		for (int i = 0; i < v[index].size(); i++) {
			q.push(v[index][i]);
			level[v[index][i]] = level[index] + 1;
		}

	}



}
int main() {

	cin >> sumNode >> noneLeaf;
	

	for (int i = 0; i < noneLeaf; i++) {
		int temp1,temp2;
		cin >> temp1 >> temp2;
		for (int i = 0; i < temp2; i++){
			int temp;
			cin >> temp; 
			v[temp1].push_back(temp);
		}
	}

	bfs();

	cout << result[1];

	for (int i = 2; i <= maxLevel; i++){
		cout << " "<< result[i];
	}

	return 0;
}