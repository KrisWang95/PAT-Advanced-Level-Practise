#include<iostream>
#include<string>
#include<algorithm>
#define err -1
#define INF 65535
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int cnt, mr, s, o;
	int g[501][501], dis[501], mrt[501], ps[501], mc[501];
	bool visited[501];
	cin >> cnt >>  mr >>  s >>  o;
	
	for(int i  = 0; i  < cnt; i++){
		cin >> 	mrt[i] ;
		dis[i] = INF;
		visited[i] = false;
		ps[i] = 0;
		mc[i] = 0;
		for(int j = 0; j < cnt; j++)
			g[i][j] = INF;
	
	}
	
	for(int i  = 0; i  < mr; i++){
		int t, t1, t2;
		cin >> t >> t1 >> t2;
		g[t][t1] = g[t1][t] = t2;
	}
	
	dis[s] = 0;
	ps[s] = 1;
	mc[s] = mrt[s];
	
	while(1){
		int min = INF, u = err, w;
		
		for(int i = 0; i < cnt; i++){
			if(visited[i] == false && dis[i] < min){
				u = i;
				min = dis[i];
			}
		}
		
		if(u == err) break;
		
		visited[u] = true;
		
		for( w = 0; w < cnt; w++){
			if(g[u][w] < INF && visited[w] == false ){
				if(dis[w] > dis[u] +g[u][w]){
					dis[w] = dis[u] + g[u][w];
					ps[w] = ps[u];
					mc[w] = mc[u]+mrt[w];
				}else if(dis[w] == dis[u] +g[u][w]){
					ps[w] = ps[u]+ps[w];
					mc[w] = max(mc[u] + mrt[w] , mc[w]);
				}
			}
		}
	}
	
	for(int i = 0; i < cnt; i++){
		cout << dis[i] << endl;
	}
	
	cout << ps[o] << " " << mc[o];

	system("pause");
	
	return 0;
} 
