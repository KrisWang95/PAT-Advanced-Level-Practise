/*
1004 Counting Leaves (30)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input

2 1
01 1 02
Sample Output

0 1
*/
//bfs
//解法1：通过父亲结点的层次计算出儿子节点的层次，再通过出队访问判断是否是叶子节点
//缺点：浪费空间
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector <int> v[101];

int node[101],l[101], maxl;

void bfs(){

	queue<int> q;

	q.push(1);

	node[1] =1;
	
	while(!q.empty()){

		int k = q.front();

		q.pop();

		if(v[k].size() == 0){

			l[node[k]]++;

		} 
		maxl = max(maxl,node[k]);

		for(int i = 0 ; i < v[k].size(); i++){

			q.push(v[k][i]);

			node[v[k][i]] = node[k] +1;

		}

	} 

}

int main(){
	std::ios::sync_with_stdio(false);

	int cnt,nln;

	cin >> cnt >> nln ;
	
	for(int i  = 0; i < nln ; i ++){
		int t,t1;
		
		cin >> t >> t1;
		
		for ( int j = 0 ; j < t1 ; j++ ){
			
			int t2;

			cin >> t2;
			
			v[t].push_back(t2);
		}
		
	}
	
	bfs();
	
	cout << l[1];
	
	for(int i = 0 ; i <  ; i++){

		cout << " " << l[i];

	}

	return 0;
} 
