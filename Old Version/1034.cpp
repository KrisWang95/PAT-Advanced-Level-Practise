#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> stringToInt,ans;
map<int, string> intToString;

int idNum = 1, k;
int weight[2005],graph[2005][2005];
bool visited[2005];

int f(string a) {
	if (stringToInt[a] == 0) {
		stringToInt[a] = idNum;
		intToString[idNum] = a;
		return idNum++;
	}
	else {
		return stringToInt[a];
	}
}

//参数说明：v 访问的点 ；head 当前连通图中权重最大的 ；numMember 连通图节点个数；totalweight 连通图总的权重
void dfs(int v, int &head, int &numMember, int &totalweight) {

	visited[v] = true;

	numMember++;

	if (weight[v] > weight[head])
		head = v;

	for (int i = 1; i < idNum; i++){

		//注意这里和dfs不一样，dfs遍历的只要求所有的vertex，而同时要求这里遍历所有的edge
		if ( graph[v][i] > 0 ) {

			totalweight += graph[v][i];
			graph[v][i] = graph[i][v]= 0;

			if (visited[i] == false) {
				dfs(i, head, numMember, totalweight);
			}
		}
	}
}

void dfst() {
	for (int i = 1; i < idNum; i++){
		if (visited[i] == false) {

			int head = i,num = 0,total = 0;

			dfs(i,head,num,total);

			if(num > 2 && total > k )
				ans[intToString[head]] = num;
		}
	}
}

int main() {
	int n, w;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		string temp, temp1;
		cin >> temp >> temp1 >> w;
		int id1 = f(temp), id2 = f(temp1);
		weight[id1] += w;
		weight[id2] += w;
		graph[id1][id2] += w;
		graph[id2][id1] += w;
	}

	dfst();
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;

	system("pause");
	return 0;
	
}