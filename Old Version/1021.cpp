/**
*算法思想：
*首先对图进行dfs遍历计算连通分量数
*然后
*	1.如果是个连通图只会进行一次dfs遍历，将所有最大深度叶子节点存储起来，从中选取一个节点作为根节点进行dfs，得到所有最大深度叶子节点，将两个集合并起来
*	2.不是连通图输出结果
**/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

set<int> s;
vector<int> v[10001],temp;
bool visited[10001];
int num, maxDepth = 0, cnt = 0;

//dfs计算最大深度
void dfs(int root,int depth) {

	if (depth > maxDepth) {
		temp.clear();
		temp.push_back(root);
		maxDepth = depth;
	}
	else if(depth == maxDepth){
		temp.push_back(root);
	}

	visited[root] = true;
	for (int i = 0; i < v[root].size(); i++){
		if (visited[v[root][i]] == false)
			dfs(v[root][i], depth + 1);
	}
}

int main() {  
	cin >> num;

	//建立邻接表
	for (int i = 0; i < num - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//计算连通分量
	for (int i = 1; i <= num; i++) {
		if (visited[i] == false) {
			dfs(i, 1);
			if (i == 1) {
				//存储最大深度叶子节点
				for (int j = 0; j < temp.size(); j++) {
					s.insert(temp[j]);
				}
			}
			cnt++;
		}
	}

	//输出
	if (cnt >= 2) {
		cout << "Error: " << cnt << " components";
	}
	else {

		//dfs遍历初始化
		temp.clear();
		maxDepth = 0;
		fill(visited, visited + 10001, false);
		dfs(*s.begin(), 1);

		//合并最大深度叶子节点
		for (int j = 0; j < temp.size(); j++) {
			s.insert(temp[j]);
		}

		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}

	system("pause");
	return 0;
}