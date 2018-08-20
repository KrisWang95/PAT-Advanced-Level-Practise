/**
*�㷨˼�룺
*���ȶ�ͼ����dfs����������ͨ������
*Ȼ��
*	1.����Ǹ���ͨͼֻ�����һ��dfs������������������Ҷ�ӽڵ�洢����������ѡȡһ���ڵ���Ϊ���ڵ����dfs���õ�����������Ҷ�ӽڵ㣬���������ϲ�����
*	2.������ͨͼ������
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

//dfs����������
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

	//�����ڽӱ�
	for (int i = 0; i < num - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//������ͨ����
	for (int i = 1; i <= num; i++) {
		if (visited[i] == false) {
			dfs(i, 1);
			if (i == 1) {
				//�洢������Ҷ�ӽڵ�
				for (int j = 0; j < temp.size(); j++) {
					s.insert(temp[j]);
				}
			}
			cnt++;
		}
	}

	//���
	if (cnt >= 2) {
		cout << "Error: " << cnt << " components";
	}
	else {

		//dfs������ʼ��
		temp.clear();
		maxDepth = 0;
		fill(visited, visited + 10001, false);
		dfs(*s.begin(), 1);

		//�ϲ�������Ҷ�ӽڵ�
		for (int j = 0; j < temp.size(); j++) {
			s.insert(temp[j]);
		}

		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}

	system("pause");
	return 0;
}