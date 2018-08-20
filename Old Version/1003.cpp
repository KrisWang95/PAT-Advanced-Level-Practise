/* 
1003. Emergency (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/ 
/* Applicatio of Dijkstra algorithm */
#include<iostream>
#define INF 65535
#define Error -1
using namespace std;
int main(){
	
	int cityNum, roadNum, c1, c2;
	
	cin >> cityNum >> roadNum >> c1 >> c2;
	
	int teams[500], maxTeams[500], sum[500], dist[500], M[500][500];
	
	bool visited[500];
	
	for(int i = 0; i < cityNum; i++){
		cin >> teams[i];
		/*初始化原始参数*/ 
		dist[i] = INF;
		visited[i] = false;
		sum[i] = 0;
		maxTeams[i] = 0;
		for(int j = 0; j < cityNum; j++)
			M[i][j] = INF;
	}
	
	for(int i = 0; i < roadNum; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2; 
		cin >> M[temp1][temp2];
		M[temp2][temp1] = M[temp1][temp2];
		if(temp1 == c1) dist[temp2] = M[temp1][temp2];
	}
	
	/*初始化起点*/ 
	dist[c1] = 0;
	sum[c1] = 1;
	maxTeams[c1] = teams[c1];
	
	while(1){
		int v = -1, w, minDist = INF;
		
		/*寻找未访问且路径最短的点*/ 
		for(int i = 0; i < cityNum; i++){
			if(visited[i] == false && dist[i] < minDist){
				v = i;
				minDist = dist[i];
			}
		}
		
		/*不存在这样的点*/ 
		if(v == -1) break;
		
		visited[v] = true;
		
		/*更新最短路径*/ 
		for(w = 0; w < cityNum; w++){
			if(visited[w] == false && M[v][w] < INF ){
				if(dist[v] + M[v][w] < dist[w]){
					dist[w] = dist[v] + M[v][w];
					sum[w] = sum[v];
					maxTeams[w] = maxTeams[v] + teams[w];
				}else if(dist[v] + M[v][w] == dist[w]){
					sum[w] = sum[w] + sum[v];
					if(maxTeams[w] < maxTeams[v] + teams[w]) maxTeams[w] = maxTeams[v] + teams[w];
				}
			}
		}
		
	}
	printf("%d %d", sum[c2], maxTeams[c2]);
	
	return 0;
	
} 





































