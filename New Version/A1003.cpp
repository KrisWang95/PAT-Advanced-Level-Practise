/*
1003 Emergency (25)
As an emergency rescue team leader of a city, you are given a special map of your country. 
The map shows several scattered cities connected by some roads. 
Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. 
When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case.
For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. 
It is guaranteed that there exists at least one path from C1 to C2.

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

//dijkstraËã·¨
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX
using namespace std;

struct node {

	int to, cost;

};

struct dij {

	int x, d;

	dij(int _x, int _d) :x(_x), d(_d) {}

	bool operator < (const dij &ano) const { return d > ano.d; }

};

vector<int> rt;// rescue teams numbers in every vertex

vector<vector<node>> edge;//adjacent table

vector<int> d;//min distance for s to every vertex

vector<int> sp;//shortest path numbers for s to every vertex

vector<int> mc;//max call rescue teams numbers for s to every vertex

int main() {

	int vn, en, s, e;

	cin >> vn >> en >> s >> e;

	d.resize(vn, inf);

	sp.resize(vn, 0);

	mc.resize(vn, 0);

	rt.resize(vn);

	edge.resize(vn);

	// input
	for (auto &it : rt) {

		cin >> it;

	}

	for (int i = 0; i <en; i++) {

		int c1, c2, cost;

		cin >> c1 >> c2 >> cost;

		edge[c1].push_back({ c2,cost });

		edge[c2].push_back({ c1,cost });

	}


	// init
	priority_queue<dij> q;

	q.push({ s,0 });

	d[s] = 0;

	sp[s] = 1;

	mc[s] = rt[s];

	while (!q.empty()) {

		dij temp = q.top(); q.pop();

		int u = temp.x;

		if (d[u] < temp.d) continue;

		for (int i = 0; i < edge[u].size(); i++) {

			int v = edge[u][i].to, cost = edge[u][i].cost;

			if (d[v] > d[u] + cost) {

				d[v] = d[u] + cost;

				sp[v] = sp[u];

				mc[v] = mc[u] + rt[v];

				q.push({ v,d[v] });


			}
			else if (d[u] + cost == d[v]) {

				sp[v] += sp[u];

				mc[v] = max(mc[u] + rt[v], mc[v]);

			}

		}

	}

	cout << sp[e] << " " << mc[e];

	system("pause");

	return 0;

}
