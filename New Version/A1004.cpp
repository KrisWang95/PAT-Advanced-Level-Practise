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
		if(v[k].size()) == 0){
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
} 
