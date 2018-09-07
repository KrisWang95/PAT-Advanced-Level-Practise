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
//dfs
//解法3：递归记录每个结点的深度
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector <int> v[101];

vector<int> levelNum;

int maxLevel = -1;

void dfs(int s, int depth){

	if (v[s].size() == 0) {

		levelNum[depth]++;

	}

	maxLevel = max(maxLevel, depth);

	for (int i = 0; i < v[s].size(); i++) {

		dfs(v[s][i], depth + 1);

	}
	
}

int main(){

	std::ios::sync_with_stdio(false);

	int cnt,nln;

	cin >> cnt >> nln ;

	levelNum.resize(cnt,0);
	
	for(int i  = 0; i < nln ; i ++){
		int t,t1;
		
		cin >> t >> t1;
		
		for ( int j = 0 ; j < t1 ; j++ ){
			
			int t2;

			cin >> t2;
			
			v[t].push_back(t2);
		}
		
	}
	
	dfs(1,0);
	
	for(int i = 0 ; i <=  maxLevel; i++){

		if(i != 0) cout << " " << levelNum[i];

		else cout << levelNum[i];

	}

	return 0;
} 
