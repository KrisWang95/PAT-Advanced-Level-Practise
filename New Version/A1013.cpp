#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visited[1001];
vector <int> v[1001]; 

void bfs(int k){
	queue<int> q;
	q.push(k);
	
	while(!q.empty()){
		int l = q.front();
		q.pop();
		visited[l] = true;
		for(int i = 0 ; i < v[l].size();i ++){
			if(visited[v[l][i]] == false)
				q.push(v[l][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int cityNum,roadNum,cn,cnt = 0;
	cin >> cityNum >> roadNum >> cn;
	for(int i = 0; i < roadNum; i++){
		int t,t1;
		cin >> t >> t1;
		v[t].push_back(t1);
		v[t1].push_back(t);
	} 
	
	for(int i = 0; i < cn; i++){
		int t;
		cin >> t;
		cnt = 0;
		fill(visited,visited+1001,false);
		visited[t] = true;
		for(int j = 1;  j <= cityNum; j++){
			if(visited[j] == false){
				bfs(j);
				cnt++;
			}
		}
		cout << cnt - 1 << endl;
	} 
	return 0;
	
} 
