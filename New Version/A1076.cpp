#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
#include<queue>
using namespace std;

vector<vector<int> > user(1010);

vector<bool> visit(1010, false);

vector<int> step(1010, 0);

int N, L;


int bfs(int s) {

	int cnt = 0;

	queue<int> q;

	q.push(s);

	step[s] = 0;

	visit[s] = true;

	while (!q.empty()){

		int k = q.front();

		q.pop();

		for (int i = 0; i < user[k].size(); i++) {

			int next = user[k][i];

			if (visit[next] == false) {

				step[next] = step[k] + 1;

				if (step[next] <= L) {

					q.push(next);

					visit[next] = true;

					cnt++;

				}


			}

		}

	}

	return cnt;

}


int main() {

	cin >> N >> L;

	for (int i = 1; i <= N; i++) {

		int temp;

		cin >> temp;

		for (int j = 0; j < temp; j++) {

			int k;

			cin >> k;

			user[k].push_back(i);

		}

	}

	int k;

	cin >> k;

	for (int i = 0; i < k; i++) {

		fill(visit.begin(), visit.end(), false);

		fill(step.begin(), step.end(), 0);

		int temp;

		cin >> temp;

		cout << bfs(temp) << endl;

	}
	
	system("pause");

	return 0;
}