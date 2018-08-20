#include<iostream>
#include<queue>
using namespace std;
struct node {
	int x, y, z;
};
int M, N, L, T;
int pix[1300][130][70], visited[1300][130][70];
int X[] = { 1,-1,0,0,0,0 }, 
	Y[] = { 0,0,1,-1,0,0 }, 
	Z[] = { 0,0,0,0,1,-1 };

bool judge(int x, int y, int z) {
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L) return false;
	if (pix[x][y][z] == 0 || visited[x][y][z] == true) return false;
	return true;
}

int bfs(int x, int y, int z) {
	int t = 0;
	node Node;
	Node.x = x, Node.y = y, Node.z = z;
	queue<node> q;
	q.push(Node);
	visited[x][y][z] = true;
	while (!q.empty()) {
		node Node = q.front();
		q.pop();
		t++;
		for (int i = 0; i < 6; i++) {
			int nextX = Node.x + X[i], nextY = Node.y + Y[i], nextZ = Node.z + Z[i];
			if (judge(nextX, nextY, nextZ)) {
				node temp;
				temp.x = nextX, temp.y = nextY, temp.z = nextZ;
				q.push(temp);
				visited[nextX][nextY][nextZ] = true;
			}
		}
	}

	if (t >= T) return t;
	else return 0;

}

int main() {
	int ans = 0;
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++){
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> pix[j][k][i];
			}
		}
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (pix[j][k][i] == 1 && visited[j][k][i] == false) {
					ans += bfs(j, k, i);
				}
			}
		}
	}
	cout << ans;
	system("pause");
	return 0;
}